// Массив ук-ей на фу-ю.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int n = 100;
const double pi = 3.141592;
double my_exp(double x) {
	double s = 0, q = 1;
	for (int k = 0; k <= n; k++) {
		s += q;
		q *= x / (k + 1);
	}
	return s;
}
double my_sin(double x) {
	double s = 0, q = x;
	for (int k = 0; k <= n; k++) {
		s += q;
		q *= (-1)*x*x / (2 * k + 2) / (2 * k + 3);
	}
	return s;
}
double my_cos(double x) {
	double s = 0, q = 1;
	for (int k = 0; k <= n; k++) {
		s += q;
		q *= (-1)*x*x / (2 * k + 1) / (2 * k + 2);
	}
	return s;
}

int main()
{
	double(*f[3])(double);
	string name[3] = { "exp","sin","cos" };
	double x[6] = { 0,pi / 6,pi / 4,pi / 3,1,pi / 2 };
	f[0] = my_exp;
	f[1] = my_sin;
	f[2] = my_cos;
	for (int i = 0; i < 3; i++) {
		cout << name[i] << ":\t";
		for (int j = 0; j < 6; j++) {
			cout << f[i](x[j]);
			cout << "  ";
		}
		cout << endl;
	}
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
