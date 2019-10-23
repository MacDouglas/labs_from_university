#ifndef POLYNOM_H
#define POLYNOM_H

#include <iostream>

namespace math_subjects {

	class polynom {
	private:
		double* index;
		int n;
	public:
		explicit polynom(int = 0);
		polynom(const double*, int);
		polynom(int, const double*);
		polynom(const polynom&);
		polynom(polynom&&);
		~polynom();
		void correct_deg();
		int get_deg();
		polynom& operator = (const polynom&);
		polynom& operator = (polynom&&);
		polynom& operator += (const polynom&);
		polynom& operator -= (const polynom&);
		polynom& operator *= (const polynom&);
		polynom& operator /= (const polynom&);
		polynom& operator %= (const polynom&);
		friend polynom operator + (const polynom&, const polynom&);
		friend polynom operator - (const polynom&, const polynom&);
		friend polynom operator * (const polynom&, const polynom&);
		friend polynom operator / (const polynom&, const polynom&);
		friend polynom operator % (const polynom&, const polynom&);
		double& operator [] (int a);
		double operator [] (int a) const;
		double operator () (double) const;
		friend std::ostream& operator << (std::ostream&, const polynom&);
	};
}
#endif 