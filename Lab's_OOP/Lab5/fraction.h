#ifndef FRACTION_H
#define FRACTION_H

#include <utility>
#include <iostream>
#include <cmath>

namespace math_subjects
{
	class fraction
	{
	private:
		int num;
		int denom;

		static int gcd(int, int);
		static int lcm(int, int);

	public:
		fraction(int n = 0, int d = 1);
		fraction(const fraction&) = default;
		fraction(fraction&&) = default;

		~fraction(void)
		{}

		int get_num(void) const;
		int get_denom(void) const;

		fraction& norm(void);

		std::pair<int, fraction> decompose(void) const;

		fraction& operator +=(const fraction&);
		fraction& operator -=(const fraction&);
		fraction& operator *=(const fraction&);
		fraction& operator /=(const fraction&);

		fraction& operator =(const fraction&) = default;
		fraction& operator =(fraction&&) = default;

		fraction& operator =(int);

		friend fraction operator +(const fraction&, const fraction&);
		friend fraction operator -(const fraction&, const fraction&);
		friend fraction operator *(const fraction&, const fraction&);
		friend fraction operator /(const fraction&, const fraction&);

		friend std::ostream& operator <<(std::ostream&, const fraction&);

		friend bool operator ==(const fraction&, const fraction&);
		friend bool operator !=(const fraction&, const fraction&);
		friend bool operator <(const fraction&, const fraction&);
		friend bool operator <=(const fraction&, const fraction&);
		friend bool operator >(const fraction&, const fraction&);
		friend bool operator >=(const fraction&, const fraction&);

		operator double(void) const;
		operator int(void) const;
	};

}

#endif
