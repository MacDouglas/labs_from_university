// Числовой массив.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

class my {
private:
	int n;
	int *fibs;
public:
	my(int n) {
		if (n < 3) {
			this->n = 3;
		}
		else {
			this->n = n;
		}
		fibs = new int[this->n];
		fibs[0] = 1;
		fibs[1] = 1;
		for (int i = 2; i < this->n; i++) {
			fibs[i] = fibs[i - 1] + fibs[i - 2];
		}
	}
	~my() {
		cout << "Delete object with element's =" << n << endl;
		delete[]fibs;
	}
	void show() {
		for (int i = 0; i < n; i++) {
			cout << fibs[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	my objA(15), objB(-5);
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
