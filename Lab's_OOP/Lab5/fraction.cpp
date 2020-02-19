#include "fraction.h"

namespace math_subjects
{
	fraction::fraction(int n, int d)
	{
		if (!d)
			throw std::invalid_argument("Ошибка: знаменатель не может быть равен 0");
		num = n;
		denom = d;
		norm();
	}

	int fraction::gcd(int a, int b)
	{
		return !b ? a : gcd(b, a % b);
	}

	int fraction::lcm(int a, int b)
	{
		return a / gcd(a, b) * b;
	}

	fraction& fraction::norm(void)
	{
		int cd = gcd(num, denom);
		num /= cd;
		denom /= cd;

		if (denom < 0)
		{
			num = -num;
			denom = -denom;
		}
		return *this;
	}

	int fraction::get_num(void) const
	{
		return num;
	}

	int fraction::get_denom(void) const
	{
		return denom;
	}

	std::pair<int, fraction> fraction::decompose(void) const
	{
		fraction frac(num % denom, denom);
		return std::make_pair(num / denom, frac);
	}

	fraction& fraction::operator +=(const fraction& op)
	{
		num = num * op.denom + op.num * denom;
		denom *= op.denom;

		return this->norm();
	}

	fraction& fraction::operator -=(const fraction& op)
	{
		num = num * op.denom - op.num * denom;
		denom *= op.denom;

		return this->norm();
	}

	fraction& fraction::operator *=(const fraction& op)
	{
		denom *= op.denom;
		num *= op.num;

		return this->norm();
	}

	fraction& fraction::operator /=(const fraction& op)
	{
		if (!(op.num))
			throw std::invalid_argument("Ошибка при делении: делитель равен нулю");

		denom *= op.num;
		num *= op.denom;

		return this->norm();
	}

	fraction& fraction::operator =(int op)
	{
		num = op;
		denom = 1;
		return *this;
	}

	fraction operator + (const fraction& op1, const fraction& op2)
	{
		fraction ret = op1;
		ret += op2;
		return ret;
	}

	fraction operator - (const fraction& op1, const fraction& op2)
	{
		fraction ret = op1;
		ret -= op2;
		return ret;
	}

	fraction operator * (const fraction& op1, const fraction& op2)
	{
		fraction ret = op1;
		ret *= op2;
		return ret;
	}

	fraction operator / (const fraction& op1, const fraction& op2)
	{
		fraction ret = op1;

		ret /= op2;

		return ret;
	}

	std::ostream& operator <<(std::ostream& out, const fraction& op)
	{
		return out << op.num << '/' << op.denom;
	}

	fraction::operator double(void) const
	{
		return (double)num / (double)denom;
	}

	fraction::operator int(void) const
	{
		return num / denom;
	}

	bool operator == (const fraction& op1, const fraction& op2)
	{
		return op1.num == op2.num && op1.denom == op2.denom;
	}

	bool operator != (const fraction& op1, const fraction& op2)
	{
		return !(op1 == op2);
	}

	bool operator < (const fraction& op1, const fraction& op2)
	{
		long long int cmp = op1.num * op2.denom - op2.num * op1.denom;
		return cmp < 0LL;
	}

	bool operator <= (const fraction& op1, const fraction& op2)
	{
		return op1 < op2 || op1 == op2;
	}

	bool operator > (const fraction& op1, const fraction& op2)
	{
		return !(op1 <= op2);
	}

	bool operator >= (const fraction& op1, const fraction& op2)
	{
		return !(op1 < op2);
	}
}
