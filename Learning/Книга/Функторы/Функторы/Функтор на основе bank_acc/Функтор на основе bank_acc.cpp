// Функтор на основе bank_acc.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

class bank_acc {
private:
	double money;
	double rate;
	int time;
public:
	double operator()() {
		double res = money;
		for (int i = 1; i <= time; i++) {
			res = res * (1 + rate / 100);
		}
		return res;
	}
	void operator()(double m, double r, int t) {
		money = m;
		rate = r;
		time = t;
	}
	bank_acc(double m=100, double r=13, int t=3) {
		(*this)(m, r, t);
	}
};

int main()
{
	bank_acc ivanov;
	cout << "Ivanov= " << ivanov() << endl;
	ivanov(120, 12, 2);
	cout << "Ivanov= " << ivanov() << endl;
	bank_acc petrov(90, 18, 4);
	cout << "Petrov= " << petrov() << endl;
	petrov(130, 15, 5);
	cout << "Petrov= " << petrov() << endl;
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
