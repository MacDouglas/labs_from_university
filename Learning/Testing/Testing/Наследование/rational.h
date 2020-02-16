#ifndef RATIONAL_H //signature
#define RATIONAL_H

#include <utility>
#include <iostream>
#include <cmath>

namespace maths
{
	class my_rational
	{
	private:
		int numer;
		int denom;

		//signature
		static int gcd(int, int);
		static int lcm(int, int);

	public:
		my_rational(int n = 0, int d = 1);
		my_rational(const my_rational&) = default;
		my_rational(my_rational&&) = default;

		~my_rational(void) {}

		int get_numer(void) const;
		int get_denom(void) const;

		my_rational& norm(void); // приведение к каноническому виду
		//signature
		std::pair<int, my_rational> decompose(void) const;

		my_rational& operator +=(const my_rational&);
		my_rational& operator -=(const my_rational&);
		my_rational& operator *=(const my_rational&);
		my_rational& operator /=(const my_rational&);

		my_rational& operator =(const my_rational&) = default;
		my_rational& operator =(my_rational&&) = default;

		my_rational& operator =(int);

		friend my_rational operator +(const my_rational&, const my_rational&);
		friend my_rational operator -(const my_rational&, const my_rational&);
		friend my_rational operator *(const my_rational&, const my_rational&);
		friend my_rational operator /(const my_rational&, const my_rational&);

		friend std::ostream& operator <<(std::ostream&, const my_rational&);

		friend bool operator ==(const my_rational&, const my_rational&);
		friend bool operator !=(const my_rational&, const my_rational&);
		friend bool operator <(const my_rational&, const my_rational&);
		friend bool operator <=(const my_rational&, const my_rational&);
		friend bool operator >(const my_rational&, const my_rational&);
		friend bool operator >=(const my_rational&, const my_rational&);

		operator double(void) const;
		operator int(void) const;
	};

}

#endif
