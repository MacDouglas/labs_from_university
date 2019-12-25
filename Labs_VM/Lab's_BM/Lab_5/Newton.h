#ifndef NEWTON_H
#define NEWTON_H

#include <fstream>
#include <vector>
#include <list>
#include <math.h>

namespace math {
	class Newton
	{
	private:
		int k, n, m, a, b, bufsize;
		char s, t, * fx;
		std::vector<double> x, y, resx;
	public:
		Newton();
		Newton(std::ifstream&);
		~Newton();

		friend double dy(vector<double> Y, vector<double> X);
		friend double dy_h(vector<double> Y, vector<double> X, int number, int index);
		
		friend double GetValue(vector<double> X, vector <double> Y, double x);
		friend double GetValue(vector<double> X, vector <double>Y, double x, double h);

		friend double Factorial(int arg);
	};
}

	

#endif 

