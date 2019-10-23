// Переопределение м-ов.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

class point2D {
public:
	double x, y;
	void set(double x, double y) {
		this->x = x;
		this->y = y;
	}
	void show() {
		cout << "Point 2D (" << x << ";" << y << ").\n";
	}
	double dist() {
		return sqrt(x*x + y * y);
	}
	void get_info() {
		show();
		cout << "Distance to point " << dist() << endl;
	}
};
class point3D :public point2D {
public:
	double z;
	void set(double x, double y,double z) {
		point2D::set(x, y);
		this->z = z;
	}
	void show() {
		cout << "Point 3D (" << x << ";" << y << ";" << z << ").\n";
	}
	double dist() {
		return sqrt(x*x + y*y + z*z);
	}
	void get_info() {               //Если не переопределить, будет вызываться для данных Point2D
		show();
		cout << "Distance to point " << dist() << endl;
	}
};

int main()
{
	point2D A;
	A.set(3, 4);
	A.get_info();
	point3D B;
	B.set(3, 4,5);
	B.show();
	B.get_info();
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
