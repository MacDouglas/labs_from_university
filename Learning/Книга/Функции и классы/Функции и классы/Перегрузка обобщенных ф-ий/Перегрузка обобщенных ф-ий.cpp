// Перегрузка обобщенных ф-ий.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
}objA("First"),objB("Second");
template<class X, class Y> void show(X a, Y b) {
	cout << "Function with 2 argument's different type" << endl;
	cout << "1 argument: " << a << endl;
	cout << "2 argument: " << b << endl;
}
template<class X> void show(X a, X b) {
	cout << "Function with 2 argument's single type" << endl;
	cout << "1 argument: " << a << endl;
	cout << "2 argument: " << b << endl;
}
template<class X> void show(X a) {
	cout << "Function with 1 argument" << endl;
	cout << "1 argument: " << a << endl;
}
template<class Y> void show(alpha a, Y b) {
	cout << "Function with 2 argument's (1-object)" << endl;
	cout << "1 argument: " << a.name << endl;
	cout << "2 argument: " << b << endl;
}
template<class X> void show(X a, alpha b) {
	cout << "Function with 2 argument's (2-object)" << endl;
	cout << "1 argument: " << a << endl;
	cout << "2 argument: " << b.name << endl;
}
void show(alpha a, alpha b) {
	cout << "Function with 2 argument's (object's)" << endl;
	cout << "1 argument: " << a.name << endl;
	cout << "2 argument: " << b.name << endl;
}
void show(alpha a) {
	cout << "Function with 1 argument(object Alpha)" << endl;
	cout << "1 argument: " << a.name << endl;
}
void show() {
	cout << "Function hasn't argument's" << endl;
}

int main()
{
	show(100, "Text");
	cout << endl;
	show(12.4, 10.3);
	cout << endl;
	show(200);
	cout << endl;
	show(objA, 'z');
	cout << endl;
	show('A',objB);
	cout << endl;
	show(objA);
	cout << endl;
	show();
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
