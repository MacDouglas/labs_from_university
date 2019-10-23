// К-ор пр-го класса.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

class point2D {
public:
	double x, y;
	point2D(double x, double y) {
		cout << "Point 2D created (2 argument's)";
		this->x = x;
		this->y = y;
		show();
	}	
	point2D(double x) {
		cout << "Point 2D created (1 argument)";
		this->x = x;
		y = x;
		show();
	}
	point2D() {
		cout << "Point 2D created (0 argument's)";
		x = 0;
		y = 0;
		show();
	}
	virtual void show() {
		cout << "Point 2D (" << x << ";" << y << ").\n";
	}
};
class point3D :public point2D {
public:
	double z;
	point3D(double x,double y,double z):point2D(x,y) {
		cout << "Point 3D created (3 argument's)";
		this->z = z;
		show();
	}
	point3D(double x) :point2D(x) {
		cout << "Point 3D created (1 argument)";
		this->z = x;
		show();
	}
	point3D() :point2D() {
		cout << "Point 3D created (0 argument's)";
		this->z = 0;
		show();
	}
	point3D(point2D obj) {
		cout << "Point 3D created (argument - object)";
		x = obj.x;
		y = obj.y;
		z = 0;
		show();
	}
	void show() {
		cout << "Point 3D (" << x << ";" << y << ";" << z << ").\n";
	}
};

int main()
{
	point2D a;
	point2D b(1);
	point2D c(2, 3);
	cout << "*********************" << endl;
	point3D d;
	point3D e(4);
	point3D f(5, 6, 7);
	point3D g(c);

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
