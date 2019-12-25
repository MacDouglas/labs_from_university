#include <limits>
#include <cmath>
#include <exception>

namespace maths
{
    template <class T>
    const T t_polynomial<T>::zero = T();

    // signature
    template <class T>
    bool t_polynomial<T>::cmp_zero(const T& value)
    {
        return value == zero;
    }
    
    template <class T>
    t_polynomial<T>::t_polynomial(size_t degree, temp_filler<T> fun)
    {
        data.resize(degree + 1);
        if (fun) // signature
        {        
            for (int i = 0; i <= degree; i++)
            {
                data[i] = fun(i);
            }
        }	
    }
    
    template <class T>
    t_polynomial<T>::t_polynomial(const T& a0)
    {
	data.push_back(a0);
    }

    template <class T>
    t_polynomial<T>::t_polynomial(std::initializer_list< std::pair<const T&, unsigned int> > elems)
    {
	for (auto e : elems)	   
	{
	    if (e.second >= data.size())
		data.resize(e.second + 1);

	    data[e.second] = e.first;
	}
    }

    template <class T>
    t_polynomial<T>::t_polynomial(const t_polynomial<T>& cp)
    {
	data = cp.data;
    }

    template <class T>
    t_polynomial<T>::t_polynomial(t_polynomial<T>&& mv)
    {
	data = std::move(mv.data);
    }

    template <class T>
    t_polynomial<T>::~t_polynomial(void) {}

    template <class T>
    std::ostream& operator <<(std::ostream& out, const t_polynomial<T>& op)
    {
        int deg = op.get_degree();
        
        for (int i = deg; i >= 0; --i)
    	{
	    if (!op.cmp_zero(op.data[i]) || !i)
            {
		out << op.data[i];
                if (i) out << "x^" << i << " + ";
            }
    	}

    	return out;
    }

    template <class T>
    T t_polynomial<T>::operator ()(const T& x) const
    {
        T res = data[0];
	int deg = get_degree();
        T power = x;
	
	for (int i = 1; i < deg; i++)
	{
	    res += data[i] * power;
	    power *= x;
	}

	return res;
    }

    template <class T>
    t_polynomial<T>& t_polynomial<T>::norm(void)
    {
        int deg = get_degree();
	while (deg && cmp_zero(data[deg])) deg--;

	data.resize(deg + 1);

        return *this;
    }

    template <class T>
    bool t_polynomial<T>::operator !(void) const
    {
	return (!get_degree() && cmp_zero(data[0]));
    }

    template <class T>
    size_t t_polynomial<T>::get_degree(void) const
    {
        return data.size() - 1;
    }
    
    template <class T>
    const T& t_polynomial<T>::operator [](size_t idx) const
    {        
        if (idx > get_degree())
            return t_polynomial<T>::zero;
        
	return data[idx];
    }

    template <class T>
    T& t_polynomial<T>::operator [](size_t idx)
    {
	if (idx > get_degree())
            data.resize(idx + 1);            
        
	return data[idx];
    }

    template <class T>
    t_polynomial<T>& t_polynomial<T>::operator =(const T& x)
    {
	data.resize(1);
	data[0] = x;

	return *this;
    }

    template <class T>
    t_polynomial<T>& t_polynomial<T>::operator =(const t_polynomial<T>& op)
    {
	if (this != &op)
	    data = op.data;
	return *this;
    }

    template <class T>
    t_polynomial<T>& t_polynomial<T>::operator =(t_polynomial<T>&& mv)
    {
        if (this != &mv)
            data = std::move(mv.data);
        return *this;
    }

    template <class T>
    t_polynomial<T>& t_polynomial<T>::operator += (const t_polynomial<T>& op)
    {
	int opsize = op.data.size();
	
        if (data.size() < opsize)
	    data.resize(opsize);
	
	for (int i = 0; i < opsize; ++i)
	{
	    data[i] += op.data[i];
	}

	norm();
	return *this;
    }

    template <class T>
    t_polynomial<T>& t_polynomial<T>::operator -= (const t_polynomial<T>& op)
    {
	int opsize = op.data.size();
	
        if (data.size() < opsize)
	    data.resize(opsize);
	
	for (int i = 0; i < opsize; ++i)
	{
	    data[i] -= op.data[i];
	}

	norm();
	return *this;
    }

    // signature?
    template <class T>
    t_polynomial<T>& t_polynomial<T>::operator *=(const t_polynomial<T>& op)
    {
        T in = t_polynomial<T>::zero;
        
	int deg1 = get_degree();
	int deg2 = op.get_degree();
	int degt = deg1+deg2;
	data.resize(degt + 1);

        int c1, c2;
        
	for (int total = degt; total >= 0; total--) // total - текущая заполняемая степень
	{
	    c1 = std::min(total, deg1);
	    c2 = (c1 == total ? 0 : total - deg1);

	    while (c2 <= deg2 && c1 >= 0)
	    {
		in += data[c1] * op.data[c2];
		c1--;
		c2++;
	    }

	    data[total] = in;
            in = zero;	    
	}
	return *this;
    }

    template <class T>
    t_polynomial<T>& t_polynomial<T>::operator /=(const t_polynomial<T>& op)
    {
        auto swp = modf(*this, op).first;
        std::swap(*this, swp);
	return *this;
    }

    template <class T>
    t_polynomial<T>& t_polynomial<T>::operator %=(const t_polynomial<T>& op)
    {
        auto swp = modf(*this, op).second;
        std::swap(*this, swp);
	return *this;
    }

    template <class T>
    t_polynomial<T> operator + (const t_polynomial<T>& op1, const t_polynomial<T>& op2)
    {
	t_polynomial<T> ret = op1;

	ret += op2;

	return ret;
    }

    template <class T>
    t_polynomial<T> operator - (const t_polynomial<T>& op1, const t_polynomial<T>& op2)
    {
	t_polynomial<T> ret = op1;

	ret -= op2;

	return ret;
    }

    template <class T>
    t_polynomial<T> operator * (const t_polynomial<T>& op1, const t_polynomial<T>& op2)
    {
	t_polynomial<T> ret = op1;

	ret *= op2;

	return ret;
    }

    // signature
    template <class T>
    std::pair< t_polynomial<T>, t_polynomial<T> > modf(const t_polynomial<T>& op1, const t_polynomial<T>& op2)
    {
	if (op2.cmp_zero(op2.data.back()))
	    throw std::invalid_argument("Ошибка при делении полиномов: Делитель равен 0");

	int deg1 = op1.get_degree();
	int deg2 = op2.get_degree();

	int diff = deg1 - deg2;
	
	t_polynomial<T> rem = op1;
        if (diff >= 0)
	{
	    t_polynomial<T> res(diff);

	    for (int rsize = diff; rsize >= 0; --rsize)
	    {
		res[rsize] = rem.data[rsize + deg2] / op2.data[deg2];
		for (int subidx = rsize + deg2; subidx >= rsize; --subidx)
		{
		    rem[subidx] -= res[rsize] * op2[subidx - rsize];
		}
	    }

	    rem.norm();
	    res.norm();
	    return std::make_pair(res, rem);
	}
	else
	{
	    return std::make_pair(t_polynomial<T>(), rem);
	}
    }

    template <class T>
    t_polynomial<T> operator /(const t_polynomial<T>& op1, const t_polynomial<T>& op2)
    {
	return modf(op1, op2).first;
    }

    template <class T>
    t_polynomial<T> operator %(const t_polynomial<T>& op1, const t_polynomial<T>& op2)
    {
	return modf(op1, op2).second;
    }

    // signature
    /* Специализации для вещественных типов (сравнение с 0) */

    /* double */

    template <>
    bool t_polynomial<double>::cmp_zero(const double& value)
    {
        return std::abs(value) < std::numeric_limits<double>::epsilon();
    }

    /* float */

    template <>
    bool t_polynomial<float>::cmp_zero(const float& value)
    {
        return std::abs(value) < std::numeric_limits<float>::epsilon();
    }

    /* long double */

    template <>
    bool t_polynomial<long double>::cmp_zero(const long double& value)
    {
        return std::abs(value) < std::numeric_limits<long double>::epsilon();
    }
}
