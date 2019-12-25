#pragma once
#ifndef FRACTION_CPP
#define FRACTION_CPP
#include "fraction.h"
#include <sstream>

using namespace std;

namespace math_subjects {

	template<class T>
	fraction<T>::fraction(T num, T denom)
	{
		this->num = num;
		this->denom = denom;

		reduce();
	}

	template<class T>
	void fraction<T>::reduce()
	{
		if (denom == 0)
			throw "Error! Denominator shouldn't be zero";

		if (denom < 0) {
			num = num;
			denom = -denom;
		}

		int tmp = nod(abs(num), denom);
		num /= tmp;
		denom /= tmp;
	}

	template<class T>
	T	fraction<T>::nod(T a, T b)
	{
		if (a == 0 || b == 0) {
			return a + b;
		}
		if (a > b) {
			return nod(a - b, b);
		}
		return nod(a, b - a);
	}

	template <class T>
	T fraction<T>::nok(T a, T b)
	{
		return a * b / nod(a, b);
	}

	template <class T>
	T fraction<T>::findInteger()
	{
		T integer = num / denom;
		num %= denom;

		return integer;
	}

	template <class T>
	T fraction<T>::getNum() const
	{
		return num;
	}

	template <class T>
	T fraction<T>::getDenom() const
	{
		return denom;
	}

	template <class T>
	void fraction<T>::setNom(T num)
	{
		this->num = num;

		reduce();
	}

	template <class T>
	void fraction<T>::setDenom(T denom)
	{
		this->denom = denom;

		reduce();
	}
	
	template <class T>
	fraction<T>& fraction<T>::operator += (const fraction<T>& a)
	{
		if (this->denom != a.denom)
		{
			T tmp = nok(this->denom, a.denom);
			num = num * (tmp / denom) + a.num * (tmp / a.denom);
			denom = tmp;
		}
		else
			this->num += a.num;

		reduce();

		return *this;
	}
	template <class T>
	fraction<T>& fraction<T>::operator -= (const fraction<T>& a)
	{
		if (this->denom != a.denom)
		{
			T tmp = nok(this->denom, a.denom);
			num = num * (tmp / denom) - a.num * (tmp / a.denom);
			denom = tmp;
		}
		else
			this->num -= a.num;

		reduce();
		return *this;
	}

	template <class T>
	fraction<T>& fraction<T>::operator *= (const fraction<T>& a) // 
	{
		T tmp1 = nod(num, a.denom);
		T tmp2 = nod(a.num, denom);

		this->num = (num / tmp1) * (a.num / tmp2);
		this->denom = (denom / tmp2) * (a.denom / tmp1);

		reduce();
		return *this;
	}
	template <class T>
	fraction<T>& fraction<T>::operator /= (const fraction<T>& a)
	{
		this->num *= a.denom;
		this->denom *= a.num;
		reduce();
		return *this;
	}
	
	template <class U>
	ostream& operator << (ostream& stream, const fraction<U>& a)
	{
		stringstream ss;
		ss << a.num << '/' << a.denom;
		stream << ss.str();
		return stream;
	}
	template <class T>
	fraction<T> operator+ (const fraction<T>& a, const fraction<T>& b)
	{
		fraction<T> c = a;
		c += b;
		return c;
	}
	template <class T>
	fraction<T> operator- (const fraction<T>& a, const fraction<T>& b)
	{
		fraction c = a;
		c -= b;
		return c;
	}
	template <class T>
	fraction<T> operator* (const fraction<T>& a, const fraction<T>& b)
	{
		fraction c = a;
		c *= b;
		return c;
	}
	template <class T>
	fraction<T> operator/ (const fraction<T>& a, const fraction<T>& b)
	{
		fraction c = a;
		c /= b;
		return c;
	}
}

#endif
