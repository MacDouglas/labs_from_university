#include "pch.h"
#include "polynom.h"
#include "fraction.h"

#include <vector>

using namespace math_subjects;
using namespace std;


int main(void)
{

	
	//fraction<double> a(1, -2);
	//fraction<double> b(2,1);
	//a *= b;

	//cout << a << endl;
	//cout << b << endl;
	//a.findInteger();
	//a += b;

	double str[] = { 3,-3 };
	double str1[] = { 42,12,-1 };

	fraction<polynom> a((1, str), 1);
	//polynom a(1, str);
	//polynom b(2, str1);

	//b = a;

	//cout << a << endl;
	//cout << b << endl;

	//a -= b;
	//b /= a;
	//a.deleteZeros();
	//cout << a;

	//cout << "Divide = " << a.divide() << endl;

	return 0;
}
