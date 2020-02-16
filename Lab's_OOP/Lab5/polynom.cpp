#pragma once
#ifndef POLYNOM
#define POLYNOM

#include "polynom.h"
#include <cmath>


namespace math_subjects
{
	template <class T>
	const T polynom<T>::zero = T();

	template <class T>
	bool polynom<T>::compareZero(const T& value)			// сравнивает с 0
	{
		return value == zero;
	}

	template <class T>
	polynom<T>::polynom(const T& a0)
	{
		data.push_back(a0);
	}

	template <class T>
	polynom<T>::polynom(std::initializer_list< std::pair<const T&, unsigned int> > elems)
	{
		for(auto i : elems)
		{
			if(i.second >= data.size())
				data.resize(i.second + 1);

			data[i.second] = i.first;
		}
	}

	template <class T>
	polynom<T>::polynom(const polynom<T>& a)
	{
		data = a.data;
	}

	template <class T>
	polynom<T>::polynom(polynom<T>&& a)
	{
		data = std::move(a.data);
	}

	template <class T>
	polynom<T>::~polynom(void){}

	template <class T>
	T polynom<T>::operator ()(const T& x) const
	{
		T res = data[0];
		int deg = get_degree();
		T power = x;

		for(int i = 1; i < deg; i++)
		{
			res += data[i] * power;
			power *= x;
		}

		return res;
	}

	template <class T>
	polynom<T>& polynom<T>::norm(void)
	{
		int deg = get_degree();
		while(deg && compareZero(data[deg])) deg--;

		data.resize(deg + 1);

		return *this;
	}

	template <class T>
	bool polynom<T>::operator !(void) const					// проверка на равенство 0
	{
		return (!get_degree() && compareZero(data[0]));
	}

	template <class T>
	size_t polynom<T>::get_degree(void) const
	{
		return data.size() - 1;
	}

	template <class T>
	const T& polynom<T>::operator [](size_t num) const
	{
		if(num > get_degree())
			return polynom<T>::zero;

		return data[num];
	}

	template <class T>
	T& polynom<T>::operator [](size_t num)
	{
		if(num > get_degree())
			data.resize(num + 1);

		return data[num];
	}

	template <class T>
	polynom<T>& polynom<T>::operator =(const T& x)
	{
		data.resize(1);
		data[0] = x;

		return *this;
	}

	template <class T>
	polynom<T>& polynom<T>::operator =(const polynom<T>& a)
	{
		if(this != &a)
			data = a.data;
		return *this;
	}

	template <class T>
	polynom<T>& polynom<T>::operator =(polynom<T>&& a)
	{
		if(this != &a)
			data = std::move(a.data);
		return *this;
	}

	template <class T>
	polynom<T>& polynom<T>::operator += (const polynom<T>& other)
	{
		int opsize = other.data.size();

		if(data.size() < opsize)
			data.resize(opsize);

		for(int i = 0; i < opsize; ++i)
		{
			data[i] += other.data[i];
		}

		norm();
		return *this;
	}

	template <class T>
	polynom<T>& polynom<T>::operator -= (const polynom<T>& other)
	{
		int opsize = other.data.size();

		if(data.size() < opsize)
			data.resize(opsize);

		for(int i = 0; i < opsize; ++i)
		{
			data[i] -= other.data[i];
		}

		norm();
		return *this;
	}
	

	template <class T> 
	const T& min (const T& a, const T& b) {
		return !(b<a)?a:b;     
	}

	template <class T>
	polynom<T>& polynom<T>::operator *=(const polynom<T>& other)
	{
		T in = polynom<T>::zero;

		int deg1 = get_degree();
		int deg2 = other.get_degree();
		int degt = deg1 + deg2;
		data.resize(degt + 1);

		int c1, c2;

		for(int i = degt; i >= 0; i--)				// i - текущая заполняемая степень
		{
			c1 = min(i, deg1);
			c2 = (c1 == i ? 0 : i - deg1);

			while(c2 <= deg2 && c1 >= 0)
			{
				in += data[c1] * other.data[c2];
				c1--;
				c2++;
			}

			data[i] = in;
			in = zero;
		}
		return *this;
	}

	template <class T>
	polynom<T>& polynom<T>::operator /=(const polynom<T>& other)
	{
		auto swp = modf(*this, other).first;
		std::swap(*this, swp);
		return *this;
	}

	template <class T>
	polynom<T>& polynom<T>::operator %=(const polynom<T>& other)
	{
		auto swp = modf(*this, other).second;
		std::swap(*this, swp);
		return *this;
	}

	template <class T>
	polynom<T> operator + (const polynom<T>& a, const polynom<T>& b)
	{
		polynom<T> res = a;
		res += b;

		return res;
	}

	template <class T>
	polynom<T> operator - (const polynom<T>& a, const polynom<T>& b)
	{
		polynom<T> res = a;
		res -= b;

		return res;
	}

	template <class T>
	polynom<T> operator * (const polynom<T>& a, const polynom<T>& b)
	{
		polynom<T> res = a;
		res *= b;

		return res;
	}

	template <class T>
	std::pair< polynom<T>, polynom<T> > modf(const polynom<T>& a, const polynom<T>& b)
	{
		if(b.compareZero(b.data.back()))
			throw std::invalid_argument("Ошибка при делении полиномов: Делитель равен 0");

		int deg1 = a.get_degree();
		int deg2 = b.get_degree();

		int difference = deg1 - deg2;

		polynom<T> rem = a;
		if(difference >= 0)
		{
			polynom<T> res(difference);

			for(int i = difference; i >= 0; --i)
			{
				res[i] = rem.data[i + deg2] / b.data[deg2];
				for(int j = i + deg2; j >= i; --j)
				{
					rem[j] -= res[i] * b[j - i];
				}
			}

			rem.norm();
			res.norm();
			return std::make_pair(res, rem);
		}
		else
		{
			return std::make_pair(polynom<T>(), rem);
		}
	}

	template <class T>
	polynom<T> operator /(const polynom<T>& a, const polynom<T>& b)
	{
		return modf(a, b).first;
	}

	template <class T>
	polynom<T> operator %(const polynom<T>& a, const polynom<T>& b)
	{
		return modf(a, b).second;
	}
	
	template <class T>
	std::ostream& operator <<(std::ostream& out, const polynom<T>& a)
	{
		int deg = a.get_degree();

		for (int i = deg; i >= 0; --i)
		{
			if (!a.compareZero(a.data[i]) || !i)
			{
				out << a.data[i];
				if (i) out << "x^" << i << " + ";
			}
		}

		return out;
	}
}
#endif POLYNOMIAL