// Указатель на метод.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
class MyClass {
private:
	string name;
	string first(char sym) {
		string s = "Object " + name + ". ";
		string txt = "First method: ";
		return s + txt + sym;
	}
	string second(char sym) {
		string s = "Object " + name + ". ";
		string txt = "Second method: ";
		return s + txt + sym;
	}
	string third(char sym) {
		string s = "Object " + name + ". ";
		string txt = "Third method: ";
		return s + txt + sym;
	}
public:
	MyClass(string name) {
		this->name = name;
	}
	string(MyClass::*getMeth(int m))(char) {
		int k = (m - 1) % 3 + 1;
		if (k == 1) return &MyClass::first;
		if (k == 2)return &MyClass::second;
		return &MyClass::third;
	}
};

int main()
{
	MyClass A("Alpha");
	MyClass B("Bravo");
	string(MyClass::*f)(char);
	for (int i = 0; i <= 6; i++) {
		f = A.getMeth(i);
		cout << (A.*f)('A' + i - 1) << endl;
		cout << (B.*f)('B' + i - 1) << endl;
		cout << endl;
	}
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
