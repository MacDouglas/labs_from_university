// Индекс-ый об-кт, как рез-ат метода.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

const int siz = 5;

class my {
private:
	double nums[siz];
	double avr() {
		double s = 0;
		for (int i = 0; i < siz; i++) {
			s += nums[i];
		}
		s /= siz;
		return s;
	}
public:
	my(double n[siz] = NULL) {
		if (n == NULL) return;
		for (int i = 0; i < siz; i++) {
			nums[i] = n[i];
		}
	}
	double operator[](int i) {
		return nums[i];
	}
	void show() {
		cout << "| ";
		for (int i = 0; i < siz; i++) {
			cout << nums[i] << "| ";
		}
		cout << endl;
	}
	my shift() {
		double m[siz];
		double a = avr();
		for (int i = 0; i < siz; i++) {
			m[i] = nums[i] - a;
		}
		my tmp(m);
		return tmp;
	}

};

int main()
{
	double x[siz] = { 1.1,3.3,-0.2,2.7,5.1 };
	my obj(x);
	obj.show();
	cout << "*******************" << endl;
	obj.shift().show();
	my array;
	array = obj.shift();
	cout << "| ";
	for (int i = siz-1; i >=0; i--) {
		cout << array[i] << "| ";
	}
	cout << endl;
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
