#ifndef METHODS_H
#define METHODS_H

#include <iostream>
#include "PolStr.h"
#include <string>
#include <cmath>
#include <stdexcept>

namespace maths_methods {

	double dihotomy(char* str, double a, double b, double eps, double& value, double& result);

	double chord(char* str, double a, double b, double eps, double& value, double& result);

	double golden(char* str, double a, double b, double eps, double& value, double& result);

	double newton(char* str, double a, double b, double eps, double& value, double& result);

	double iteration(char* str, double a, double b, double eps, double& value, double& result);

	double combined(char* str, double a, double b, double eps, double& value, double& result);

}
#endif 