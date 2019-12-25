#include "temp_polynomial.hpp"
#include "rational.hpp"

#include <iostream>
#include <vector>

using namespace maths;

my_rational test(int i)
{
    return my_rational(i, 9);
}

int main(void)
{
    t_polynomial<my_rational> filler_test(9, test);
    std::cout << "Testing filler:\n" << filler_test << std::endl;

    t_polynomial<my_rational> empty(9);
    std::cout << empty << std::endl;
    
    t_polynomial<> default_d = {{1.0, 2}, {2.4, 4}, {19.2, 0}};
    std::cout << "Testing default template argument:\n" << default_d << std::endl;
    
    t_polynomial<my_rational> a = {{my_rational(5, 4), 0}, {my_rational(23, 10), 1}};

    t_polynomial<my_rational> b = a;
    t_polynomial<my_rational> c = a * b;
    /* не компилируется, т.к. разные классы */
    // t_polynomial<int> c = a;
    
    std::cout << "Testing multiplication:\n" << a << "\n" << c << std::endl;
    std::cout << "Testing inner methods:\n" << a[1].get_numer() << ' ' << a[1].get_denom() << std::endl;

    a[3] = 2;
    std::cout << "Testing assignment:\n" << a << '\n' << std::endl;
    
    return 0;
}
