#include "fraction.h"
#include "pch.h"

using namespace std;

namespace math_subjects {

	fraction::fraction():num(0),denom(0){}
	
	fraction::fraction(int num, int denom)
	{
		this->num = num;
		this->denom = denom;

		reduce();
	}

	void fraction::reduce()
	{
		if (denom == 0)
		{
			throw "Error! Denominator shouldn't be zero";
		}
		int tmp = nod(num, denom);
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
		else
			return nod(a, b - a);
	}

	int fraction::nok(int a, int b)
	{
		return a*b/nod(a,b);
	}

	int fraction::findWhole()
	{
		int whole = num/denom;
		num = num % denom;

		return whole;
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
	}

	void fraction::setDenom(int denom)
	{
		this->denom = denom;
	}

	fraction& fraction::operator += (const fraction& a)				//знаментаели умножить на НОК, а не друг на друга
	{
		if (this->denom != a.denom)
		{
			fraction tmp;
			tmp.denom = nok(this->denom,a.denom);
			tmp.num = this->num * (tmp.denom/this->denom) + a.num * (tmp.denom / a.denom);
			*this = move(tmp);
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
			fraction tmp;
			tmp.denom = nok(this->denom, a.denom);
			tmp.num = this->num * (tmp.denom / this->denom) - a.num * (tmp.denom / a.denom);
			*this = move(tmp);
		}
		else
			this->num -= a.num;
		reduce();
		return *this;
	}

	fraction& fraction::operator *= (const fraction& a)
	{
		this->num *= a.num;
		this->denom *= a.denom;
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
		streamsize size = stream.width();
		stream.width(size);
		stream << a.num << '/' << a.denom;
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