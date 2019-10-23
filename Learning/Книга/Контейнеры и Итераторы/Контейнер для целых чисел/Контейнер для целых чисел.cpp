// Контейнер для целых чисел.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;
class Vector {
	int length;
	int *v;
public:
	Vector(int s, int val = 0) {
		length = s;
		v = new int[length];
		for (int i = 0; i < length; i++) {
			v[i] = val;
		}
	}
	~Vector() {
		delete[]v;
	}
	int size() {
		return length;
	}
	int &operator[](int k) {
		return v[k];
	}
	void insert(int m, int val) {
		int k = m;
		if (m < 0)k = 0;
		if (m > length)k = length;
		int *t, i;
		t = new int[length + 1];
		for (i = 0; i < k; i++) {
			t[i] = v[i];
		}
		t[k] = val;
		for (i = k + 1; i <= length; i++) {
			t[i] = v[i - 1];
		}
		delete[]v;
		v = t;
		length++;
	}
	void clear() {
		delete[]v;
		v = 0;
		length = 0;
	}
	void erase(int m) {
		int k = m, i;
		if (m < 0) k = 0;
		if (m >=length) k = length-1;
		int *t;
		t = new int[length - 1];
		for (i = 0; i < k; i++) {
			t[i] = v[i];
		}
		for (i = k; i < length - 1; i++) {
			t[i] = v[i + 1];
		}
		delete[]v;
		v = t;
		length--;
	}
	void push_back(int val) {
		insert(length, val);
	}
	void push_front(int val) {
		insert(0, val);
	}
	void pop_back() {
		erase(length);
	}
	void pop_front() {
		erase(0);
	}
	void show() {
		if (length == 0) {
			cout << "Haven't result's" << endl;
			return;
		}
		for (int i = 0; i < length; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");
	Vector a(5, 1);
	cout << "Количество элементов: " << a.size() << endl;
	a.show();
	a.insert(3, 0);
	cout << "Количество элементов: " << a.size() << endl;
	a.show();
	a.clear();
	a.show();
	a.insert(0, 0);
	for (int i = 1; i <= 5; i++) {
		a.push_back(i);
		a.push_front(-i);
	}
	a.show();
	a.erase(5);
	a.show();
	a.pop_back();
	a.pop_front();
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
