#include "polynom.h"
#include "pch.h"

using namespace std;

namespace math_subjects {

	polynom::polynom(int r) : polynom(r, 0) {}

	polynom::polynom(const double* a, int r) : polynom(r, a) {}

	polynom::polynom(int r, const double* a,int off)
	{
		if (r < 0)
			throw "Rank should be > or = 0";

		this->rank = r;
		index = new double[rank + 1];
		if (a)
			for (int i = 0; i <= rank; i++) {
				index[i] = *a;
				a += off;
			}
		else
			for (int i = 0; i <= rank; i++)
				index[i] = 0;
	}

	polynom::polynom(const polynom& a) : polynom(a.rank, a.index){}

	polynom::polynom(polynom&& a) : polynom()
	{
		swap(rank, a.rank);
		swap(index, a.index);
	}

	polynom::~polynom()
	{
		if (index)
			delete[] index;
	}

	void polynom::deleteZeros()
	{
		if (rank> 0)
		{
			int x = rank;

			while (index[x] == 0 && x) {
				x--;
			}

			if (x != rank)
			{
				polynom tmp(rank);
				tmp = move(*this);
				
				if(index)
					delete[] index;
				
				rank = x;
				index = new double[rank + 1];
				
				for (int i = 0; i <= rank; i++)
				{
					index[i] = tmp.index[i];
				}
			}
		}
	}

	int polynom::getRank() const
	{
		return rank;
	}

	double polynom::operator () (double x) const
	{
		double num = index[0];
		for (int i = 1; i <= rank; i++)
		{
			num += index[i] * pow(x, i);
		}
		return num;
	}

	double& polynom::operator [] (int num)
	{
		if (num < 0 || num >= rank+ 1)
		{
			throw "Incorrect index";
		}
		return *(index + num);
	}

	double polynom::operator [] (int num) const
	{
		if (num < 0 || num >= rank + 1)
		{
			throw "Incorrect index";
		}
		return index[num];
	}

	polynom& polynom::operator= (const polynom& a)
	{
		if (this->rank != a.rank)
		{
			if (index)
				delete[] index;
			
			this->rank = a.rank;
			
			if (a.index)
			{
				index = new double[rank + 1];
			}
			else
				index = NULL;

		}
		for (int i = 0; i <= rank; i++)
			this->index[i] = a.index[i];
		
		return *this;
	}

	polynom& polynom::operator= (polynom&& a)
	{
		if (this != &a)
			return *this;

		if (index)
			delete[] index;
		rank = 0;

		swap(rank, a.rank);
		swap(index, a.index);
		return *this;
	}

	polynom& polynom::operator+= (const polynom& a)
	{
		polynom tmp;
		if (rank>= a.rank)
		{
			tmp = *this;
			for (int i = 0; i <= a.rank; i++)
				tmp.index[i] += this->index[i];
		}
		else
		{
			tmp = a;
			for (int i = 0; i <= rank; i++)
				tmp.index[i] += this->index[i];
		}
		return *this = move(tmp);
	}

	polynom& polynom::operator-= (const polynom& a)
	{
		polynom tmp;
		if (rank>= a.rank)
		{
			tmp = *this;
			for (int i = 0; i <= a.rank; i++)
				tmp.index[i] -= this->index[i];
		}
		else
		{
			tmp = a;
			for (int i = 0; i <= rank; i++)
				tmp.index[i] -= this->index[i];
		}
		return *this = move(tmp);
	}

	polynom& polynom::operator*= (const polynom& a)
	{
		polynom tmp(this->rank+ a.rank);
		for (int i = 0; i <= rank; i++)
		{
			for (int j = 0; j <= a.rank; j++)
			{
				tmp.index[i + j] += index[i] * a.index[j];
			}
		}
		return *this = move(tmp);
	}

	polynom& polynom::operator/= (const polynom& a)
	{
		if (a.index[a.rank] == 0)
			throw "Delete last zeros";

		if (rank < a.rank)
			return *this;

		int difference = rank - a.rank;
		polynom res(difference);

		for (int i = 0; i <= difference; i++)
		{
			res.index[difference - i] = index[rank - i] / a.index[a.rank];
			for (int j = 0; j <= a.rank; j++)
			{
				index[rank - j - i] -= a.index[a.rank- j] * res.index[difference - i];
			}
		}

		res.deleteZeros();
		return *this = move(res);
	}

	polynom& polynom::operator%= (const polynom& a)
	{
		if (a.index[a.rank] == 0)
			throw "Delete last zeros";

		if (rank < a.rank)
			return *this;

		double k;

		for (int i = 0; i <=rank- a.rank; i++)
		{
			k = index[rank - i] / a.index[a.rank];

			for (int j = 0; j <= a.rank; j++)
				index[rank - i - j] -= a.index[a.rank- j] * k;
		}

		deleteZeros();
		return *this;
	}

	

	polynom operator+ (const polynom& a, const polynom& b)
	{
		polynom c = a;
		c += b;
		return c;
	}

	polynom operator- (const polynom& a, const polynom& b)
	{
		polynom c = a;
		c -= b;
		return c;
	}

	polynom operator* (const polynom& a, const polynom& b)
	{
		polynom c = a;
		c *= b;
		return c;
	}

	polynom operator/ (const polynom& a, const polynom& b)
	{
		polynom tmp = a;
		tmp /= b;
		return tmp;
	}

	polynom operator% (const polynom& a, const polynom& b)
	{
		polynom tmp = a;
		tmp %= b;
		return tmp;
	}

	ostream& operator<< (ostream& stream, const polynom& a)
	{
		streamsize size = stream.width();
		for (int i = 0; i <= a.rank; i++)
		{
			stream.width(size);
			stream.setf(ios::showpos);
			stream << a.index[a.rank- i];
			stream.unsetf(ios::showpos);
			stream << 'X' << '^' << a.rank - i;
		}
	
		return stream;
	}

}
