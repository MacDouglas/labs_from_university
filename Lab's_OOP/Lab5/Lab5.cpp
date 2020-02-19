#include <iostream>
#include <vector>
#include "polynom.h"
#include "fraction.h"

using namespace math_subjects;

int main()
{
	polynom<> d = {{1.0, 2}, {2.4, 4}, {19.2, 0}};
	std::cout << d << std::endl;

	polynom<fraction> a = {{fraction(5, 4), 0}, {fraction(23, 10), 1}};

	polynom<fraction> b = a;
	polynom<fraction> c = a * b;

	std::cout << "multiplication:\n" << a << "\n" << c << std::endl;
	std::cout << "c%a=" << c % a << std::endl;
	std::cout << "inner methods:\n" << a[1].get_num() << ' ' << a[1].get_denom() << std::endl;
	a[3] = 2;
	std::cout << a << '\n' << std::endl;

	return 0;
}