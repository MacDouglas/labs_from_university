// Перегрузка оп-ра=.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

class my {
public:
	int *nums;
	int size;
	my(int size) {
		this->size = size;
		nums = new int[this->size];
		for (int i = 0; i < this->size; i++) {
			nums[i] = 0;
		}
	}
	my(my &obj) {
		size = obj.size;
		nums = new int[size];
		for (int i = 0; i < size; i++) {
			nums[i] = obj.nums[i];
		}
	}
	~my() {
		delete[]nums;
	}
	void show() {
		for (int i = 0; i < size; i++) {
			cout << nums[i] << " ";
		}
		cout << endl;
	}
	my &operator=(my &obj) {
		delete[]this->nums;
		this->size = obj.size;
		this->nums = new int[this->size];
		for (int i = 0; i < this->size; i++) {
			this->nums[i] = obj.nums[i];
		}
		return *this;
	}
};

int main()
{
	my A(5);
	my B(A);
	A.show();
	B.show();
	//B = A;
	//B.show();
	A.nums[2] = 123;
	A.show();
	B.show();
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
