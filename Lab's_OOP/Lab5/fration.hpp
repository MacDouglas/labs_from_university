#ifndef OOP_LAB4_RATIONAL_HEADER //signature
#define OOP_LAB4_RATIONAL_HEADER

#include <utility>
#include <iostream>
#include <cmath>

namespace math_subjects
{
	class ration
	{
	private:
		int num;
		int denom;

		//signature
		static int gcd(int, int);
		static int lcm(int, int);

	public:
		ration(int n = 0, int d = 1);
		ration(const ration&) = default;
		ration(ration&&) = default;

		~ration(void)
		{}

		int get_num(void) const;
		int get_denom(void) const;

		ration& norm(void); // приведение к каноническому виду
		//signature
		std::pair<int, ration> decompose(void) const;

		ration& operator +=(const ration&);
		ration& operator -=(const ration&);
		ration& operator *=(const ration&);
		ration& operator /=(const ration&);

		ration& operator =(const ration&) = default;
		ration& operator =(ration&&) = default;

		ration& operator =(int);

		friend ration operator +(const ration&, const ration&);
		friend ration operator -(const ration&, const ration&);
		friend ration operator *(const ration&, const ration&);
		friend ration operator /(const ration&, const ration&);

		friend std::ostream& operator <<(std::ostream&, const ration&);

		friend bool operator ==(const ration&, const ration&);
		friend bool operator !=(const ration&, const ration&);
		friend bool operator <(const ration&, const ration&);
		friend bool operator <=(const ration&, const ration&);
		friend bool operator >(const ration&, const ration&);
		friend bool operator >=(const ration&, const ration&);

		operator double(void) const;
		operator int(void) const;
	};

}

#endif
