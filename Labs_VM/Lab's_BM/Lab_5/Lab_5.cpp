#include <iostream>
#include <fstream>
#include <list>
#include "Newton.h"

using namespace std;

double F(double x)
{
	return pow(x, 3) - 3 * pow(x, 2) - 8 * abs(x);
}

int main()
{

	vector<double> X = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18 };
	vector<double> Y;
	int n = X.size();
	Y.resize(n);

	double x = 3;
	for (int i = 0; i < X.size(); i++)
	{
		Y[i] = F(X[i]);
		cout << Y[i] << endl;
	}

	//*list <double> Y = {1, 2 ,2 , 3 ,41 ,4};
	//Y.begin() + 1;
	//ifstream input("input.txt");
	//if (!input)
	//	throw "Input file is not opened";
	//newton a(input);

	/*Newton interpolation = new Newton();
	double y = interpolation.GetValue(X, Y, x);
	cout << "Interpolation by Newton for x = {x}, Y = {y}";
	Console.WriteLine($"True value for X = {x}, Y = {F(x)}");
	Console.WriteLine($"dY value for X = {x}, dY = {Math.Abs(F(x) - y)}");
	Console.ReadLine();*/

	return 0;
}

