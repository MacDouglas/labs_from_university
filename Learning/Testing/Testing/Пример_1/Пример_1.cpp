// Пример_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>


using namespace std;

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


double* findAllMax(double* input,int n) {

	double max = 0, pos = 0;
	double* posMax = new double[n], * pointMax = new double[n];

	for (int i = 0, j=0; i < n - 1; i++) {

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

	double min = 0, pos = 0;
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


int main()
{
	srand(time(NULL));
	double randDA, randDW, dA, dw;
	double A = 10, w = 0.2, a = 0.01;
	double* input, * output,*pointMax = new double[100];
	vector<double>input, output;
	input = new double[100];
	output = new double[100];

	for (int i = 0; i < 100; i++) {

		randDA = static_cast<double>(rand() % (100 - (-100) + 1) + (-100)) / 100;
		randDW = static_cast<double>(rand() % (100 - (-100) + 1) + (-100)) / 100;

		dA = A * (1 + a * randDA);       //Считается амплитуда с шумами
		dw = w * (1 + a * randDW);

		input[i] = dA * sin(i * dw);
		//cout << input[i]<< endl;
		
		//x.push_back(i);
		//y.push_back(dA * sin(x[i] * dw + f));
	}
	smooth(input, output, 100, 2);

	double* f;
	f = findAllMax(output, 100);
	int i = 0;
	while (f != nullptr) {
		cout << f[i]<<endl;
		i++;
	}
	/*int i = 0;
	while (pointMax != NULL) {
		cout << pointMax[i] << endl;
		i++;
		}
	for (int i = 0; i < 100; i++) {
		cout << output[i] << endl;
	}*/
	
	delete[] input; delete[] output; delete[] pointMax;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
