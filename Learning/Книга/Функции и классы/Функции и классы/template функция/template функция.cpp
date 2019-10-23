// template функция.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class first {
public:
	string name;
	first(string name = " ") {
		this->name = name;
	}
	void show() {
		cout << "Text field: " << name << endl;
	}
};
class second {
public:
	int code;
	second(int code = 0) {
		this->code = code;
	}
	void show() {
		cout << "Code field: " << code << endl;
	}
};
template<class X>void swap_data(X &a, X &b) {
	X tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int a = 10, b = 5;
	swap_data(a,b);
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	char x = 'a', y = 'b';
	swap_data(x, y);
	cout << "x= " << x << endl;
	cout << "y= " << y << endl;
	first A("Object A"), B("Object B");
	swap_data(A, B);
	A.show();
	B.show();
	second objA(100), objB(200);
	swap_data(objA, objB);
	objA.show();
	objB.show();
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
