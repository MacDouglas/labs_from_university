// Пер-ые баз. и мн-ых кл. при мно-ом насл.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
class alpha {
public:
	int code;
	alpha(int code = 0) {
		this->code = code;
	}
	void show() {
		cout << "Field code:" << code << endl;
	}
	void hi() {
		cout << "This is class Alpha" << endl;
	}
};
class bravo {
public:
	string name;
	bravo(string name = "") {
		this->name = name;
	}
	void show() {
		cout << "Field name: " << name << endl;
	}
	void hello() {
		cout << "This is class Bravo" << endl;
	}
};
class charlie : public alpha, public bravo {
public:
	charlie(int n, string txt) :alpha(n), bravo(txt) {}
	void say() {
		alpha::show();
		bravo::show();
	}
};

int main()
{
	alpha a;
	bravo b;
	charlie c(123, "BBBravo");
	c.say();
	a = c;
	b = c;
	a.hi();
	a.show();
	b.hello();
	b.show();
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
