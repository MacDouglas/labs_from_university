#include "pch.h"
#include <iostream>
#include <vector>


using namespace std;

double* findAllMax(double* input, int n) {

	int max = 0, pos = 0;
	double* posMax = new double[n], * pointMax = new double[n];

	for (int i = 0, j = 0; i < n - 1; i++) {

		if ((input[i + 1] > input[i]) && (input[i + 2] > input[i + 1]) && (input[i + 2] > input[i])) {
			max = input[i + 2];
			pos = i + 2;

		}
		else if (max != 0) {
			pointMax[j] = max;
			posMax[j] = pos;

			j++;
			max = 0;
		}
	}
	return pointMax;
}
double* findAllMin(double* input, int n) {

	int min = 0, pos = 0;
	double* posMin = new double[n], * pointMin = new double[n];

	for (int i = 0, j = 0; i < n - 1; i++) {

		if ((input[i + 1] < input[i]) && (input[i + 2] < input[i + 1]) && (input[i + 2] < input[i])) {
			min = input[i + 2];
			pos = i + 2;

		}
		else if (min != 0) {
			pointMin[j] = min;
			posMin[j] = pos;

			j++;
			min = 0;
		}
	}
	return pointMin;
}
double smooth(double* input, double* output, int n, int window)
{
	int i, j, z, k1, k2, hw;
	double tmp;
	if (fmod(window, 2) == 0) window++;
	hw = (window - 1) / 2;
	output[0] = input[0];

	for (i = 1; i < n; i++) {
		tmp = 0;
		if (i < hw) {
			k1 = 0;
			k2 = 2 * i;
			z = k2 + 1;
		}
		else if ((i + hw) > (n - 1)) {
			k1 = i - n + i + 1;
			k2 = n - 1;
			z = k2 - k1 + 1;
		}
		else {
			k1 = i - hw;
			k2 = i + hw;
			z = window;
		}

		for (j = k1; j <= k2; j++) {
			tmp = tmp + input[j];
		}
		output[i] = tmp / z;
	}
	return *output;
}



int main()
{
	srand(time(NULL));
	double randDA, randDW, dA, dw;
	double A = 10, w = 0.2, a = 0.01;
	double* input, * output;
	input = new double[100];
	output = new double[100];

	for (int i = 0; i < 100; i++) {

		randDA = static_cast<double>(rand() % (100 - (-100) + 1) + (-100)) / 100;
		randDW = static_cast<double>(rand() % (100 - (-100) + 1) + (-100)) / 100;

		dA = A * (1 + a * randDA);       //Считается амплитуда с шумами
		dw = w * (1 + a * randDW);

		input[i] = dA * sin(i * dw);		
		//cout << input[i]<< endl;

	}
	smooth(input, output, 100, 2);

	double* f;
	f = findAllMax(output, 100);
	int i = 0;
	
	for (size_t i = 0; i < 100; i++)
	{
		cout << f[i] << endl;
	}

	
	delete[] input; delete[] output; 
	return 0;
}