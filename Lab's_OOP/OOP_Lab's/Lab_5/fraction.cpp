#include "pch.h"
#include "fraction.h"
#include <sstream>

using namespace std;

namespace math_subjects {

	fraction::fraction(int num, int denom)
	{
		this->num = num;
		this->denom = denom;

		reduce();
	}

	void fraction::reduce()
	{
		if (denom == 0)
			throw "Error! Denominator shouldn't be zero";

		if (denom < 0) {
			num = -num;
			denom = -denom;
		}

		int tmp = nod(abs(num), denom);
		num /= tmp;
		denom /= tmp;
	}

	int fraction::nod(int a, int b)
	{
		if (a == 0 || b == 0) {
			return a + b;
		}
		if (a > b) {
			return nod(a - b, b);
		}
		return nod(a, b - a);
	}

	int fraction::nok(int a, int b)
	{
		return a * b / nod(a, b);
	}

	int fraction::findInteger()
	{
		int integer = num / denom;
		num %= denom;

		return integer;
	}

	int fraction::getNum() const
	{
		return num;
	}

	int fraction::getDenom() const
	{
		return denom;
	}

	void fraction::setNom(int num)
	{
		this->num = num;

		reduce();
	}

	void fraction::setDenom(int denom)
	{
		this->denom = denom;

		reduce();
	}

	fraction& fraction::operator += (const fraction& a)
	{
		if (this->denom != a.denom)
		{
			int tmp = nok(this->denom, a.denom);
			num = num * (tmp / denom) + a.num * (tmp / a.denom);
			denom = tmp;
		}
		else
			this->num += a.num;

		reduce();

		return *this;
	}

	fraction& fraction::operator -= (const fraction& a)
	{
		if (this->denom != a.denom)
		{
			int tmp = nok(this->denom, a.denom);
			num = num * (tmp / denom) - a.num * (tmp / a.denom);
			denom = tmp;
		}
		else
			this->num -= a.num;

		reduce();
		return *this;
	}

	fraction& fraction::operator *= (const fraction& a) // 
	{
		int tmp1 = nod(num, a.denom);
		int tmp2 = nod(a.num, denom);

		this->num = (num / tmp1) * (a.num / tmp2);
		this->denom = (denom / tmp2) * (a.denom / tmp1);

		reduce();
		return *this;
	}

	fraction& fraction::operator /= (const fraction& a)
	{
		this->num *= a.denom;
		this->denom *= a.num;
		reduce();
		return *this;
	}

	ostream& operator << (ostream& stream, const fraction& a)
	{
		stringstream ss;
		ss << a.num << '/' << a.denom;
		stream << ss.str();
		return stream;
	}

	fraction operator+ (const fraction& a, const fraction& b)
	{
		fraction c = a;
		c += b;
		return c;
	}

	fraction operator- (const fraction& a, const fraction& b)
	{
		fraction c = a;
		c -= b;
		return c;
	}

	fraction operator* (const fraction& a, const fraction& b)
	{
		fraction c = a;
		c *= b;
		return c;
	}

	fraction operator/ (const fraction& a, const fraction& b)
	{
		fraction c = a;
		c /= b;
		return c;
	}
}