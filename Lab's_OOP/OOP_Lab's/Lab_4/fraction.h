#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

namespace math_subjects {

	class fraction
	{
	private:
		int num,denom;
	public:
		
		fraction(int num = 0, int denom = 1);
		
		void reduce();
		static int nod(int a, int b);
		static int nok(int a, int b);

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