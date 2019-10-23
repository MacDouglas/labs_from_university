// Абстр. класс и чисто вирт. метод.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class base{
public:
	double pi;
	double s2;
	double s3;
	double size;
	string name;
	virtual double volume() = 0;
	virtual double area() = 0;
	void set(double size, string name) {
		this->size = size;
		this->name = name;
	}
	void show() {
		cout << "Figure: " << name << endl;
		cout << "Line size: " << size << endl;
		cout << "Volume: " << volume() << endl;
		cout << "Area: " << area() << endl;
	}
	base(double L, string txt) {
		pi = 3.141592;
		s2 = 1.414213;
		s3 = 1.732050;
		set(L, txt);
	}
};
class cube :public base {
public:
	cube(double L) :base(L, "Cube") {
		show();
	}
	double volume() {
		return size * size*size;
	}
	double area() {
		return 6 * size*size;
	}
};
class sphere : public base {
public:
	sphere(double L) :base(L, "Sphere") {
		show();
	}
	double volume() {
		return 4 * pi*size*size*size / 3;
	}
	double area() {
		return 4 * pi*size*size;
	}
};
class tetrahedron :public base {
public:
	tetrahedron(double L) :base(L, "Tetrahedron") {
		show();
	}
	double volume() {
		return s2 * size*size*size / 12;
	}
	double area() {
		return s3 * size*size;
	}
};

int main()
{
	cube a(10);
	sphere b(10);
	tetrahedron c(10);
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
