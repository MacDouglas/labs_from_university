#ifndef POLYNOM_H
#define POLYNOM_H

#include <iostream>

namespace math_subjects {

	class polynom {
	private:
		double *index;
		int rank,capacity;
	public:

		explicit polynom(int = 0);

		polynom(const double*, int);
		polynom(int, const double*,int off = 1);

		polynom(const polynom&);
		polynom(polynom&&);

		~polynom();

		void deleteZeros();
		//void pack();
		int getRank() const;

		double& operator [] (int num);
		double operator [] (int num) const;
		double operator () (double) const;

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
		
		friend std::ostream& operator << (std::ostream&, const polynom&);
	};
}
#endif 