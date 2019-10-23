// Совпадающ. наз. наслед. членов.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class alpha {
public:
	string name;
	alpha(string name) {
		this->name = name;
	}
	void get_name() {
		cout << "Class Alpha ---" << name << endl;
	}
};
class bravo {
public:
	string name;
	bravo(string name) {
		this->name = name;
	}
	void get_name() {
		cout << "Class Bravo ---" << name << endl;
	}
};
class charlie :public alpha, public bravo {
public:
	string name;
	charlie(string x,string y,string name) :alpha(x), bravo(y) {
		this->name = name;
	}
	void get_name() {
		cout << "Method from Charlie" << endl;
		alpha::get_name();
		bravo::get_name();
		cout << "Class Charlie ---" << name << endl;
		cout << "Method's done" << endl;
	}
};
int main()
{
	charlie obj("AAAlpha", "BBBravo", "CCCharlie");
	obj.get_name();
	obj.alpha::get_name();
	obj.bravo::get_name();
	cout << obj.alpha::name << endl;
	cout << obj.bravo::name << endl;

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
