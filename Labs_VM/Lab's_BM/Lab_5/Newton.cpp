#include "Newton.h"
#include "PolStr.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace math {

	Newton::Newton()
	{
		k = 0;
		n = 0;
		s = 0;
		a = 0;
		b = 0;
		m = 0;
		t = 0;
		fx = NULL;
		bufsize = 0;
	}
	Newton::Newton(std::ifstream& input)
	{
		input >> k;
		input >> n;
		input >> s;
		input >> a;
		input >> b;
		x.resize(n + 1);
		for (int i = 0; i < x.size(); i++)
			input >> x[i];
		y.resize(n + 1);
		for (int i = 0; i < y.size(); i++)
			input >> y[i];
		input >> m;
		resx.resize(n + 1);
		for (int i = 0; i < resx.size(); i++)
			input >> resx[i];
		input >> t;
		std::string buf;
		input.seekg(2, std::ios::cur);
		std::getline(input, buf);
		bufsize = buf.size() + 1;
		fx = new char[bufsize];
		buf.copy(fx, bufsize);
		fx[buf.size()] = '\0';
		/*x.erase(x.begin());
		for(int i = 0; i < x.size(); i++)
			std::cout << x[i] << ' ';*/
	}
	Newton::~Newton()
	{
		if (fx)
			delete[] fx;
	}

	double dy(vector<double> Y, vector<double> X)
	{
		/*list<double>::iterator itY = Y.begin();			
		list<double>::iterator itX = X.begin();			
		advance(itY, 0);								
		advance(itX, 0);								
		double Y0 = *itY, Y1 = *++itY;					
		double X0 = *itX, X1 = *++itX;					
*/

		if (Y.size > 2)
		{
			vector<double> Yleft(Y);			//
			vector<double> Xleft(X);			//
			
			Xleft.erase(Xleft.begin());			//
			Yleft.erase(Yleft.begin());			//
			
			vector<double> Yright(Y);
			vector<double> Xright(X);
			
			Xright.erase(Y.size - 1);
			Yright.erase(Y.size - 1);
			
			return (dy(Yleft, Xleft) - dy(Yright, Xright)) / (X[X.size - 1] - X[0]);
		}
		else if (Y.size == 2)
		{
			return (Y[1] - Y[0]) / (X[1] - X[0]);
		}
		else
		{
			throw "Not available parameter";
		}
	}

	double GetValue(vector<double> X, vector <double> Y, double x)
	{
		double res = Y[0];
		double buf;
		vector<double> Xlist;					//Заменил list на vector
		vector<double> Ylist;					//
		for (int i = 1; i < Y.size; i++)
		{
			//Xlist = new List<double>();
			//Ylist = new List<double>();
			vector<double> Xlist;
			vector<double> Ylist;
			buf = 1;
			for (int j = 0; j <= i; j++)
			{
				Xlist.push_back(X[j]);
				Ylist.push_back(Y[j]);
				if (j < i)
					buf *= x - X[j];
			}
			res += dy(Ylist, Xlist) * buf;
		}
		return res;
	}

	double Factorial(int arg)
	{
		double res = 1;
		for (int i = 2; i <= arg; i++)
		{
			res *= i;
		}
		return res;
	}

	double dy_h(vector<double> Y, vector<double> X, int number, int index)
	{
		if (number > 1)
		{
			return (dy_h(Y, X, number - 1, index + 1) - dy_h(Y, X, number - 1, index));
		}
		else if (number == 1)
		{
			return (Y[index + 1] - Y[index]);
		}
		else
		{
			throw "Not available parameter";
		}
	}

	double GetValue(vector<double> X, vector <double>Y, double x, double h)
	{
		double res = Y[0];
		double buf;
		//List<double> Xlist = new List<double>(X);
		//List<double> Ylist = new List<double>(Y);
		vector<double> Xlist(X);
		vector<double> Ylist(Y);
		double q = (x - X[0]) / h;
		buf = 1;
		for (int i = 1; i < Y.size() ; i++)
		{
			buf *= (q - i + 1) / i;
			res += dy_h(Ylist, Xlist, i, 0) * buf;
		}
		return res;
	}


}