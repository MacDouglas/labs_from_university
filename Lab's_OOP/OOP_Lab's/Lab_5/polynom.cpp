#include "polynom.h"
#include "pch.h"

using namespace std;

namespace math_subjects {

	polynom::polynom(int r) : polynom(r, 0) {}

	polynom::polynom(const double* a, int r) : polynom(r, a) {}

	polynom::polynom(int r, const double* a, int off)
	{
		if (r < 0)
			throw "Rank should be > or = 0";

		rank = r;
		capacity = r;

		index = new double[rank + 1];
		if (a)
			for (int i = 0; i <= rank; i++) {
				index[i] = *a;
				a += off;
			}
		else
			for (int i = 0; i <= rank; i++)
				index[i] = 0;

		deleteZeros();
	}

	polynom::polynom(const polynom& a) : polynom(a.rank, a.index) {}

	polynom::polynom(polynom&& a) : polynom()
	{
		swap(rank, a.rank);
		swap(capacity, a.capacity);
		swap(index, a.index);
	}

	polynom::~polynom()
	{
		if (index)
			delete[] index;
	}

	void polynom::deleteZeros()
	{
		if (rank > 0)
		{
			if (index[rank] == 0 && rank) {
				while (index[rank] == 0 && rank) {
					rank--;
				}
			}
		}
	}

	int polynom::getRank() const
	{
		return rank;
	}

	double polynom::operator () (double x) const   //+
	{
		double num = index[rank];
		for (int i = 1; i <= rank; i++)
		{
			num *= x;
			num += index[rank - i];

		}
		return num;
	}

	double& polynom::operator [] (int num)
	{
		if (num < 0 || num > rank)
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
		if (this == &a)
			return *this;

		if (capacity < a.rank)	//если размер контейнеров не одинаковый и степень this меньше other
		{
			delete[] index;
			index = new double[a.rank + 1];	//Перевыделяем память под массив
			capacity = a.rank;
		}

		rank = a.rank;
		for (int i = 0; i <= rank; ++i)
			index[i] = a.index[i];

		return *this;


	}

	polynom& polynom::operator= (polynom&& a)
	{
		if (this != &a)
			return *this;

		if (index)
			delete[] index;
		index = NULL;
		rank = 0;
		capacity = 0;

		swap(rank, a.rank);
		swap(index, a.index);
		swap(capacity, a.capacity);

		return *this;
	}

	polynom& polynom::operator+= (const polynom& a)		//+
	{
		if (capacity >= a.rank)
		{
			for (int i = 0; i <= a.rank; i++)
				this->index[i] += a.index[i];

			if (rank < a.rank)
				rank = a.rank;
		}
		else
		{
			polynom tmp = a;

			tmp += *this;

			//for (int i = 0; i <= rank; i++)
			//	tmp.index[i] += index[i];

			*this = move(a);
		}

		deleteZeros();

		return *this;
	}

	polynom& polynom::operator-= (const polynom& a)		//+
	{
		if (capacity >= a.rank)
		{
			for (int i = 0; i <= a.rank; i++)
				this->index[i] -= a.index[i];

			if (rank < a.rank)
				rank = a.rank;
		}
		else
		{
			polynom tmp(a.rank);

			tmp -= a;
			tmp += *this;

			//for (int i = 0; i <= rank; i++) {
			//	tmp.index[i] = index[i];
			//}
			//for (int i = 0; i <= rank; i++)
			//	tmp.index[i] -= a.index[i];

			*this = move(tmp);
		}

		deleteZeros();

		return *this;
	}

	polynom& polynom::operator*= (const polynom& a)
	{
		polynom tmp(this->rank + a.rank);
		for (int i = 0; i <= rank; i++)
		{
			for (int j = 0; j <= a.rank; j++)
			{
				tmp.index[i + j] += index[i] * a.index[j];
			}
		}
		tmp.deleteZeros();

		return *this = move(tmp);
	}

	polynom& polynom::operator/= (const polynom& a)			//+
	{
		if (a.index[a.rank] == 0)
			throw "Delete last zeros";

		if (rank < a.rank)
			return *this = move(polynom(0));

		else {
			int difference = rank - a.rank;
			polynom res(difference);

			for (int i = 0; i <= difference; i++)
			{
				res.index[difference - i] = index[rank - i] / a.index[a.rank];
				for (int j = 0; j <= a.rank; j++)
				{
					index[rank - j - i] -= a.index[a.rank - j] * res.index[difference - i];
				}
			}
			res.deleteZeros();
			return *this = move(res);
		}

	}

	polynom& polynom::operator%= (const polynom& a)
	{
		if (a.index[a.rank] == 0)
			throw "Reduce last number's with zero";

		if (rank < a.rank)
			return *this;

		else {
			double k;

			for (int i = 0; i <= rank - a.rank; i++)
			{
				k = index[rank - i] / a.index[a.rank];

				for (int j = 0; j <= a.rank; j++)
					index[rank - i - j] -= a.index[a.rank - j] * k;
			}
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
			stream << a.index[a.rank - i];
			stream.unsetf(ios::showpos);
			stream << 'X' << '^' << a.rank - i;
		}

		return stream;
	}

}
