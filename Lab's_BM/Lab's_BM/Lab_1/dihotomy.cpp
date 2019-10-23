#include "dihotomy.h"


double dihotomy(char* str, double a, double b, double eps, double& value, double& result)
{
	double c;
	do {
		c = (a + b) / 2;
		if (EvalPolStr(str, a) * EvalPolStr(str, c) < 0) {
			b = c;
		}
		else {
			a = c;
		}
		result = fabs(EvalPolStr(str, (a + b) / 2));	//абс-ая погрешность по функции
		value = fabs((b - a) / 2);						//абс-ая погрешность по аргументу
	}
	while (result > eps || value > eps);
	return c;
}
