#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

namespace math_subjects {

	class fraction
	{
	private:
		int num,denom;
	public:
		fraction();
		fraction(int num);
		fraction(int num, int denom);
		
		void reduce();
		int nod(unsigned a, unsigned b);
		int nok(unsigned a, unsigned b);

		int findInteger();

		int getNum() const;
		int getDenom() const;
		void setNom(int);
		void setDenom(int);

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