// Функтор.Массив Функций.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;
const double pi = 3.141592;
class FArrey {
private:
	int n;
	double my_exp(double x) {
		double s = 0, q = 1;
		for (int i = 0; i <= n; i++) {
			s += q;
			q *= x / (i + 1);
		}
		return s;
	}
	double my_sin(double x) {
		double s = 0, q = x;
		for (int i = 0; i <= n; i++) {
			s += q;
			q *= (-1)*x*x/(2*i+2)/(2*i+3);
		}
		return s;
	}
	double my_cos(double x) {
		double s = 0, q = 1;
		for (int i = 0; i <= n; i++) {
			s += q;
			q *= (-1)*x*x / (2 * i + 1) / (2 * i + 2);
		}
		return s;
	}
	class F {
	private:
		int index;
		FArrey *p;
	public:
		F(int m, FArrey *p) {
			index = m % 3;
			this->p = p;
		}
		double operator()(double x) {
			if (index == 0)return p->my_exp(x);
			if (index == 1)return p->my_sin(x);
			return p->my_cos(x);
		}
	};
public:
	FArrey(int n) {
		this->n = n;
	}
	F operator[](int k) {
		F tmp(k, this);
		return tmp;
	}

};

int main()
{
	FArrey mf(10);
	cout << "exp(1)= " << mf[0](1) << endl;
	cout << "sin(pi/6)= " << mf[1](pi/6) << endl;
	cout << "exp(pi/3)= " << mf[2](pi/3) << endl;
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
