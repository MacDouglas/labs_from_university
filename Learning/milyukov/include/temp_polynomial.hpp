#ifndef OOP_LAB5C_POLYNOMIAL // signature
#define OOP_LAB5C_POLYNOMIAL

#include <vector>
#include <iostream>
#include <functional>

namespace maths
{
    // signature
    template <class T>
    using temp_filler = std::function<T(int)>;
     
    template <class T = double>
    class t_polynomial
    {
    private:
	std::vector<T> data;
        static const T zero;

        static bool cmp_zero(const T&); // сравнивает с 0
    public:
        t_polynomial(const T& a0 = zero);
	explicit t_polynomial(size_t degree, temp_filler<T> fun = temp_filler<T>());
	
	t_polynomial(std::initializer_list< std::pair<const T&, unsigned int> >);
	t_polynomial(const t_polynomial&);
	t_polynomial(t_polynomial&&);
	
	~t_polynomial(void);

	template <class U>
        friend std::ostream& operator <<(std::ostream&, const t_polynomial<U>&);
	
	bool operator !(void) const; // проверка на равенство 0
        size_t get_degree(void) const;
	
        const T& operator [](size_t idx) const; // достает коэффициент при idx-ном члене
        T& operator [](size_t idx);

	t_polynomial& operator = (const t_polynomial<T>&);
	t_polynomial& operator = (t_polynomial&&);
	t_polynomial& operator = (const T&);
	
	t_polynomial& operator += (const t_polynomial&);
	t_polynomial& operator -= (const t_polynomial&);
	t_polynomial& operator *= (const t_polynomial&);
	
	t_polynomial& operator /=(const t_polynomial&);
	t_polynomial& operator %=(const t_polynomial&);

	template <class U>
	friend t_polynomial<U> operator +(const t_polynomial<U>&, const t_polynomial<U>&);

	template <class U>
	friend t_polynomial<U> operator -(const t_polynomial<U>&, const t_polynomial<U>&);

	template <class U>
	friend t_polynomial<U> operator *(const t_polynomial<U>&, const t_polynomial<U>&);

	template <class U>
	friend std::pair< t_polynomial<U>, t_polynomial<U> > modf(const t_polynomial<U>&, const t_polynomial<U>&);

	template <class U>
	friend t_polynomial<U> operator %(const t_polynomial<U>&, const t_polynomial<U>&);

	template <class U>
	friend t_polynomial<U> operator /(const t_polynomial<U>&, const t_polynomial<U>&);
        
        T operator ()(const T&) const;
	t_polynomial& norm(void);
    };
}

// так надо чтобы шаблоны не ломались
// (реализация шаблонов должна быть в одном файле с объявлениями)
#include "temp_polynomial.cpp"

#endif
