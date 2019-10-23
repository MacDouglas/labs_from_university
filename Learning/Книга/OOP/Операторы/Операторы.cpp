// Операторы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class bank_acc {
private:
	string name;
	double money;
	double rate;
	int time;
	double find_value(double m, double r, int t) {
		if (t == 0) {
			return m;
		}
		else {
			return find_value(m, r, t - 1)*(1 + r / 100);
		}
	}
	double total() {
		return find_value(money, rate, time);
	}
public:
	void set(string n, double m, double r, int t) {
		name = n;
		money = m;
		rate = r;
		time = t;
	}
	bank_acc(string n, double m, double r, int t) {
		set(n, m, r, t);
	}
	bank_acc() {
		set("Anonimus", 0, 0, 0);
	}
	void show() {
		cout << "Данные по банковскому счету.\n";
		cout << "Вкладчик:\t" << name << endl;
		cout << "Сумма:\t" << money << endl;
		cout << "Ставка:\t" << rate << endl;
		cout << "Время:\t" << time << endl;
		cout << "Всего:\t" << total() << endl;
		cout << endl;
	}
	bank_acc operator+(int t) {
		bank_acc tmp;
		tmp.set(name, money, rate, time + t);
		return tmp;
	}
	bank_acc operator+(double m) {
		bank_acc tmp;
		tmp.set(name, money + m, rate, time);
		return tmp;
	}
	bank_acc operator*(double x) {
		bank_acc tmp;
		tmp.set(name, money, rate+x, time);
		return tmp;
	}
	double operator!() {
		return total();
	}
	double operator-(bank_acc tmp) {
		return total()-!tmp;
	}

};
int main()
{
	setlocale(LC_ALL, "RUS");

	bank_acc ivanov("Ivanov I.I.", 100, 12, 3);
	ivanov.show();
	bank_acc fellow;
	fellow = ivanov + 2;
	fellow.show();
	((ivanov + 25.0) * 4).show();
	double dif = fellow - ivanov;
	cout << dif << endl;
    
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
