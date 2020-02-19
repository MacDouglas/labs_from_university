#pragma once
#ifndef POLYNOM_H
#define POLYNOM_H

#include <vector>
#include <iostream>
#include <functional>

namespace math_subjects
{
	template <class T = double>
	class polynom
	{
	private:
		std::vector<T> data;
		static const T zero;

		static bool compareZero(const T&); 
	public:

		polynom(const T& a0 = zero);
		polynom(std::initializer_list< std::pair<const T&, unsigned int> >);
		polynom(const polynom&);
		polynom(polynom&&);

		~polynom(void);


		bool operator !(void) const;
		size_t get_degree(void) const;

		const T& operator [](size_t idx) const;
		T& operator [](size_t idx);

		polynom& operator = (const polynom<T>&);
		polynom& operator = (polynom&&);
		polynom& operator = (const T&);

		polynom& operator += (const polynom&);
		polynom& operator -= (const polynom&);
		polynom& operator *= (const polynom&);

		polynom& operator /=(const polynom&);
		polynom& operator %=(const polynom&);

		template <class T>
		friend polynom<T> operator +(const polynom<T>&, const polynom<T>&);

		template <class U>
		friend polynom<U> operator -(const polynom<U>&, const polynom<U>&);

		template <class U>
		friend polynom<U> operator *(const polynom<U>&, const polynom<U>&);

		template <class U>
		friend std::pair< polynom<U>, polynom<U> > modf(const polynom<U>&, const polynom<U>&);

		template <class U>
		friend polynom<U> operator %(const polynom<U>&, const polynom<U>&);

		template <class U>
		friend polynom<U> operator /(const polynom<U>&, const polynom<U>&);

		T operator ()(const T&) const;
		polynom& norm(void);

		template <class U>
		friend std::ostream& operator <<(std::ostream&, const polynom<U>&);
	};
}

#include "polynom.cpp"

#endif
