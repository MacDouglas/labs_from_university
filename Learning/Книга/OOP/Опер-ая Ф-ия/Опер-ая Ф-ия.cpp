// Опер-ая Ф-ия.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
	double total() {
		double s = money;
		int t = 1;
		while (t <= time) {
			s *= (1 + rate / 100);
			t++;
		}
		return s;
	}
public:
	void set(string n, double m, double r, int t) {
		name = n;
		money = m;
		rate = r;
		time = t;
	}
	bank_acc(string n = "Anonimus", double m = 0, double r = 0, int t = 0) {
		set(n, m, r, t);
	}
	void show() {
		cout << "Данные по банковскому счету.\n";
		cout << "Вкладчик:\t" << name << endl;
		cout << "Сумма:\t" << money << endl;
		cout << "Ставка %Ж\t" << rate << endl;
		cout << "Время:\t" << time << endl;
		cout << "Всего:\t" << total() << endl;
		cout << endl;
	}
	friend bank_acc operator+(bank_acc, int);
	friend bank_acc operator+(bank_acc, double);
	friend bank_acc operator*(bank_acc, double);
	friend double operator!(bank_acc);
	friend bank_acc operator-(bank_acc, bank_acc);
};
bank_acc operator+(bank_acc obj, int t) {
	bank_acc tmp;
	tmp.set(obj.name, obj.money, obj.rate, obj.time + t);
	return tmp;
}
bank_acc operator+(bank_acc obj, double m) {
	bank_acc tmp;
	tmp.set(obj.name, obj.money+m, obj.rate, obj.time);
	return tmp;
}
bank_acc operator*(bank_acc obj, double x) {
	bank_acc tmp;
	tmp.set(obj.name, obj.money, obj.rate+x, obj.time);
	return tmp;
}
double operator!(bank_acc obj) {
	return obj.total();
}
double operator-(bank_acc obj,bank_acc tmp) {
	return !obj - !tmp;
}
int main()
{
	bank_acc ivanov("Ivanov I.I.", 100, 12, 3);
	ivanov.show();
	bank_acc fellow;
	fellow = ivanov + 2;
	fellow.show();
	((ivanov + 25.0) * 4).show();
	double dif = fellow - ivanov;
	cout << "Difference:\t" << dif << endl;
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
