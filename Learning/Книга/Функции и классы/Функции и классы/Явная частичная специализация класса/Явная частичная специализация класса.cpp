// Явная частичная специализация класса.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
template<class X, class Y> class my {
public:
	X first;
	Y second;
	my(X first, Y second) {
		this->first = first;
		this->second = second;
	}
	void show() {
		cout << "Field first: " << first << endl;
		cout << "Field second: " << second << endl;
	}
};
template<class X> class my<X,string> {
public:
	X first;
	string name;
	my(X first, string name) {
		this->first = first;
		this->name = name;
	}
	void show() {
		cout << "Field first: " << first << endl;
		cout << "Field text : " << name << endl;
	}
};
template<> class my<int,string> {
public:
	int first;
	string name;
	my(int first, string name) {
		this->first = first;
		this->name=name;
	}
	void show() {
		cout << "Field int: " << first << endl;
		cout << "Field text: " << name << endl;
	}
};

int main()
{
	my<int, char> A(123, 'I');
	A.show();
	my<char, string> B('A', "Text");
	B.show();
	my<int, string> C(100, "New text");
	C.show();
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
