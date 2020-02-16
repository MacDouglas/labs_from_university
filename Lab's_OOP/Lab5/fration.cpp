#include "rational.hpp"

namespace math_subjects
{
	ration::ration(int n, int d)
	{
		if(!d)
			throw std::invalid_argument("Ошибка: знаменатель не может быть равен 0");
		num = n;
		denom = d;
		norm();
	}

	int ration::gcd(int a, int b)
	{
		return !b ? a : gcd(b, a % b);
	}

	int ration::lcm(int a, int b)
	{
		return a / gcd(a, b) * b;
	}

	ration& ration::norm(void)
	{
		int cd = gcd(num, denom);
		num /= cd;
		denom /= cd;

		if(denom < 0)
		{
			num = -num;
			denom = -denom;
		}
		return *this;
	}

	int ration::get_num(void) const
	{
		return num;
	}

	int ration::get_denom(void) const
	{
		return denom;
	}

	std::pair<int, ration> ration::decompose(void) const
	{
		ration frac(num % denom, denom);
		return std::make_pair(num / denom, frac);
	}

	ration& ration::operator +=(const ration& op)
	{
		num = num * op.denom + op.num * denom;
		denom *= op.denom;

		return this->norm();
	}

	ration& ration::operator -=(const ration& op)
	{
		num = num * op.denom - op.num * denom;
		denom *= op.denom;

		return this->norm();
	}

	ration& ration::operator *=(const ration& op)
	{
		denom *= op.denom;
		num *= op.num;

		return this->norm();
	}

	ration& ration::operator /=(const ration& op)
	{
		if(!(op.num))
			throw std::invalid_argument("Ошибка при делении: делитель равен нулю");

		denom *= op.num;
		num *= op.denom;

		return this->norm();
	}

	ration& ration::operator =(int op)
	{
		num = op;
		denom = 1;
		return *this;
	}

	ration operator + (const ration& op1, const ration& op2)
	{
		ration ret = op1;
		ret += op2;
		return ret;
	}

	ration operator - (const ration& op1, const ration& op2)
	{
		ration ret = op1;
		ret -= op2;
		return ret;
	}

	ration operator * (const ration& op1, const ration& op2)
	{
		ration ret = op1;
		ret *= op2;
		return ret;
	}

	ration operator / (const ration& op1, const ration& op2)
	{
		ration ret = op1;

		ret /= op2;

		return ret;
	}

	std::ostream& operator <<(std::ostream& out, const ration& op)
	{
		return out << op.num << '/' << op.denom;
	}

	ration::operator double(void) const
	{
		return (double) num / (double) denom;
	}

	ration::operator int(void) const
	{
		return num / denom;
	}

	bool operator == (const ration& op1, const ration& op2)
	{
		return op1.num == op2.num && op1.denom == op2.denom;
	}

	bool operator != (const ration& op1, const ration& op2)
	{
		return !(op1 == op2);
	}

	bool operator < (const ration& op1, const ration& op2)
	{
		long long int cmp = op1.num * op2.denom - op2.num * op1.denom;
		return cmp < 0LL;
	}

	bool operator <= (const ration& op1, const ration& op2)
	{
		return op1 < op2 || op1 == op2;
	}

	bool operator > (const ration& op1, const ration& op2)
	{
		return !(op1 <= op2);
	}

	bool operator >= (const ration& op1, const ration& op2)
	{
		return !(op1 < op2);
	}
}
