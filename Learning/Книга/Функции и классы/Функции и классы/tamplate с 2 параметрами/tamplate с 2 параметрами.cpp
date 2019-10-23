// tamplate с 2 параметрами.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

class int_class {
public:
	int code;
	void show() {
		cout << "Field code= " << code << endl;
	}
	int_class(int code = 0) {
		this->code = code;
	}
};
class char_class {
public:
	char symb;
	void show() {
		cout << "Field symb= " << symb << endl;
	}
	char_class(char symb = 'a') {
		this->symb = symb;
	}
};
template<class X, class Y>X *get_obj(X obj, Y field) {
	cout << "Begin func get_obj()" << endl;
	X *tmp;
	tmp = new X(field);
	tmp->show();
	return tmp;
}

int main()
{
	int_class objI;
	char_class objC,*pnt;
	get_obj(objI, 100)->show();
	pnt = get_obj(objC, 'z');
	pnt->show();
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
