// Мно-ое наследование.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class alpha {
private:
	string name;
public:
	alpha(string txt) {
		name = txt;
	}
	void hi() {
		cout << "Object Alpha createrd ---" << name << endl;
	}
};
class bravo {
private:
	string name;
public:
	bravo(string txt) {
		name = txt;
	}
	void hello() {
		cout << "Object Bravo created ---" << name << endl;
	}
};
	class charlie :public alpha, protected bravo {
	public:
		charlie(string x, string y) :alpha(x), bravo(y) {
			cout << "Object Charlie created ---" << endl;
		}
		void show() {
			hi();
			hello();
		}
	};

int main()
{
	charlie obj("Alpha", "Bravo");
	obj.show();
	cout << "****************" << endl;
	obj.hi();
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
