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
		fraction(int, int );
		
		void reduce();
		int nod(int, int);
		int nok(int, int);

		int findWhole();

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