#include "polynom.h"
#include "pch.h"

using namespace std;

namespace math_subjects {

	polynom::polynom(int k) : polynom(k, 0)
	{
	}

	polynom::polynom(const double* a, int k) : polynom(k, a)
	{
	}

	polynom::polynom(int k, const double* a)
	{
		if (k < 0)
			throw "Negative degree";
		//cout << "Polynomial created" << endl;
		this->n = k;
		index = new double[n + 1];
		if (a)
			for (int i = 0; i <= n; i++)
				index[i] = a[i];
		else
			for (int i = 0; i <= n; i++)
				index[i] = 0;
	}

	polynom::polynom(const polynom& a) : polynom(a.n, a.index)
	{
	}

	polynom::polynom(polynom&& a) : polynom()
	{
		swap(n, a.n);
		swap(index, a.index);
	}

	polynom::~polynom()
	{
		if (index)
			delete[] index;
		//cout << "Polynomial deleted" << endl;
	}

	void polynom::correct_deg()					//удаление нолей старшей степени
	{
		if (n > 0)
		{
			int x = n;
			if (index[x] == 0)
			{
				do
				{
					x--;
				} while (x && index[x] == 0);
			}
			if (x != n)
			{
				polynom tmp(n);
				tmp = move(*this);
				delete[] index;
				index = NULL;
				index = new double[x + 1];
				n = x;
				for (int i = 0; i <= n; i++)
				{
					index[i] = tmp.index[i];
				}
			}
		}
	}

	int polynom::get_deg()
	{
		return n;
	}

	polynom& polynom::operator= (const polynom& a)
	{
		if (this->n != a.n)
		{
			if (index)
				delete[] index;
			this->n = a.n;
			index = new double[n + 1];
		}
		for (int i = 0; i <= n; i++)
			this->index[i] = a.index[i];
		return *this;
	}

	polynom& polynom::operator= (polynom&& a)
	{
		swap(n, a.n);
		swap(index, a.index);
		return *this;
	}

	polynom& polynom::operator+= (const polynom& a)
	{
		polynom tmp;
		if (n >= a.n)
		{
			tmp = *this;
			for (int i = 0; i <= a.n; i++)
				tmp.index[i] += this->index[i];
		}
		else
		{
			tmp = a;
			for (int i = 0; i <= n; i++)
				tmp.index[i] += this->index[i];
		}
		return *this = move(tmp);
	}

	polynom& polynom::operator-= (const polynom& a)
	{
		polynom tmp;
		if (n >= a.n)
		{
			tmp = *this;
			for (int i = 0; i <= a.n; i++)
				tmp.index[i] -= this->index[i];
		}
		else
		{
			tmp = a;
			for (int i = 0; i <= n; i++)
				tmp.index[i] -= this->index[i];
		}
		return *this = move(tmp);
	}

	polynom& polynom::operator*= (const polynom& a)
	{
		polynom tmp(this->n + a.n);
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= a.n; j++)
			{
				tmp.index[i + j] += index[i] * a.index[j];
			}
		}
		return *this = move(tmp);
	}

	polynom& polynom::operator/= (const polynom& a)
	{
		if (a.index[a.n] == 0)
			throw "Div on zero";
		if (n < a.n)
			return *this;
		int difference = n - a.n;
		polynom res(difference);
		for (int i = 0; i <= difference; i++)
		{
			res.index[difference - i] = index[n - i] / a.index[a.n];
			for (int j = 0; j <= a.n; j++)
			{
				index[n - j - i] -= a.index[a.n - j] * res.index[difference - i];
			}
		}
		res.correct_deg();
		return *this = move(res);
	}

	polynom& polynom::operator%= (const polynom& a)
	{
		if (a.index[a.n] == 0)
			throw "Div on zero";
		if (n < a.n)
			return *this;
		double k;
		for (int i = 0; i <= n - a.n; i++)
		{
			k = index[n - i] / a.index[a.n];
			for (int j = 0; j <= a.n; j++)
				index[n - i - j] -= a.index[a.n - j] * k;
		}
		correct_deg();
		return *this;
	}

	double polynom::operator () (double x) const
	{
		double num = index[0];
		for (int i = 1; i <= n; i++)
		{
			num += index[i] * pow(x, i);
		}
		return num;
	}

	double& polynom::operator [] (int a)
	{
		if (a < 0 || a >= n + 1)
		{
			throw "Incorrect index";
		}
		return *(index + a);
	}

	double polynom::operator [] (int a) const
	{
		if (a < 0 || a >= n + 1)
		{
			throw "Incorrect index";
		}
		return index[a];
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
		/*stream << a.index [0];
		if (a.n)
			for (int i = 1; i <= a.n; i++)
			{
				stream.setf (ios::showpos);
				stream << a.index [i];
				stream.unsetf (ios::showpos);
				stream << "*X^" << i;
			}*/
		streamsize size = stream.width();
		for (int i = 0; i <= a.n; i++)
		{
			stream.width(size);
			stream.setf(ios::showpos);
			stream << a.index[a.n - i];
			stream.unsetf(ios::showpos);
			stream << 'X' << '^' << a.n - i;
		}
		return stream;
	}

}
