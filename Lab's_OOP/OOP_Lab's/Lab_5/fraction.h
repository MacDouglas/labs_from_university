#pragma once
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

namespace math_subjects {

	template <class T>
	class fraction
	{
	private:
		T num, denom;
	public:

		fraction(T num, T denom);

		void reduce();
		static T nod(T a, T b);
		static T nok(T a, T b);
		
		T findInteger();

		T getNum() const;
		T getDenom() const;
		void setNom(T);
		void setDenom(T);

		fraction& operator += (const fraction&);
		fraction& operator -= (const fraction&);
		fraction& operator *= (const fraction&);
		fraction& operator /= (const fraction&);

		friend fraction operator + (const fraction&, const fraction&);
		friend fraction operator - (const fraction&, const fraction&);
		friend fraction operator * (const fraction&, const fraction&);
		friend fraction operator / (const fraction&, const fraction&);

		friend std::ostream& operator << (std::ostream&, const fraction&);
	};
}

#endif
#include "fraction.cpp"