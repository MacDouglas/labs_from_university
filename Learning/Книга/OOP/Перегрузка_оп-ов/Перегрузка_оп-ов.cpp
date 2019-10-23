// Перегрузка_оп-ов.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
	double find_value(double m, double r, double t) { //Вычисление итоговой суммы депозита (закрытый)
		double res = m;
		for (int i = 1; i <= t; i++) {
			res = res * (1 + r / 100);
		}
		return res;
	}
	void show_table(bool style = false) {			//Отображение полей таблицы (закрытый)
		cout << "|  Вкладчик\t" << "|  Сумма\t" << "|  Время\t";
		if (style) {
			cout << "|  Сумма\t" << "|  Время\t";
		}
		cout  << "|  % \t" << "|  Всего  |\n";
	}
	void show_data(double m, int t) {        //Отображение файтических данных (2 аргумента)(закрытый)
		cout << "| " << name << "\t";
		cout << "| " << money << "\t";
		cout << "| " << time << "\t";
		cout << "| " << m << "\t";
		cout << "| " << time-t << "\t";
		cout << "| " << rate << "\t";
		cout << "| " << result(m,t) << "|\n";
		cout << endl;
	}
	void show_data() {
		cout << "| " << name << "\t";
		cout << "| " << money << "\t";
		cout << "| " << time << "\t";
		cout << "| " << rate << "\t";
		cout << "| " << result() << "|\n";
		cout << endl;
	}
	double result() {
		return find_value(money, rate, time);
	}
	double result(double m, int t) {
		double m1, m2;
		m1 = find_value(money, rate, time);
		if (t > time) {
			return m1;
		}
		else {
			m2 = find_value(m, rate, time - t);
			return m1 + m2;
		}
	}
public:
	void set_all(string n, double m, double r, int t) {
		name = n;
		money = m;
		rate = r;
		time = t;
	}
	void set_all(string n) {
		set_all(n, 100, 13, 3);
	}
	void show(double m, int t) {
		show_table(true);
		show_data(m, t);
	}
	void show(double m) {
		show(m, 1);
	}
	void show() {
		show_table();
		show_data();
	}
	bank_acc(string name) {
		set_all(name);
		show();
	}
	bank_acc(string name, double m, double r, int t) {
		set_all(name, m, r, t);
		show();
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");

	bank_acc ivanov("Иванов И.И.");
	ivanov.show(30, 2);
	ivanov.show(29);

	bank_acc petrov("Петров П.П.", 90, 18, 4);
	petrov.set_all("Сидоров С.С.");
	petrov.show();
	petrov.show(50, 5);

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
