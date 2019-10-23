// Функтор для работы с полиномом.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class polynomial {
private:
	double *a;
	int power;
public:
	polynomial(double  *b, int p) {
		power = p;
		a = new double[power + 1];
		for (int i = 0; i <= power; i++) {
			a[i] = b[i];
		}
	}
	polynomial(int p = 0) {
		power = p;
		a = new double[power + 1];
		for (int i = 0; i <= power; i++) {
			a[i] = 0;
		}
	}
	polynomial(const polynomial &p) {
		power = p.get_power();
		a = new double[power + 1];
		for (int i = 0; i <= power; i++) {
			a[i] = p[i];
		}
	}
	~polynomial() {
		delete[] a;
	}
	int get_power() const{
		return power;
	}
	void coefs() const{
		for (int i = 0; i <= power; i++) {
			cout << a[i] << "\t";
		}
		cout << endl;
	}
	double &operator[](int k) const{
		return a[k];
	}
	double operator()(double x) {
		double s = 0, q = 1;
		for (int i = 0; i <= power; i++) {
			s += a[i] * q;
			q *= x;
		}
		return s;
	}
	polynomial operator*(polynomial p) {
		int n = p.get_power();
		int m = power + n;
		polynomial t(m);
		for (int i = 0; i <= power; i++) {
			for (int j = 0; j <= n; j++) {
				t[i + j] += a[i] * p[j];
			}
		}
		return t;
	}
	polynomial operator=(polynomial p) {
		delete[]a;
		power = p.get_power();
		a = new double[power + 1];
		for (int i = 0; i <= power; i++) {
			a[i] = p[i];
		}
		return *this;
	}

};

int main()
{
	srand(100);
	const int n = 2;
	double nums[n + 1] = { 3,-2,1 };
	cout << "Polynom's" << endl;
	polynomial p(nums, n);
	p.coefs();
	polynomial q(n + 1);
	q.coefs();
	for (int i = 0; i <= n + 1; i++) {
		q[i] = rand() & 5 - 2;
	}
	q.coefs();
	polynomial r;
	r = p * q;
	r.coefs();
	cout << "Result's of polynom's" << endl;
	double x = -2, dx = 1;
	for (int k = 1; k <= 5; k++) {
		cout << "P(" << x << ") = " << p(x) << "\t";
		cout << "Q(" << x << ") = " << q(x) << "\t";
		cout << "R(" << x << ") = " << r(x) << endl;
		x += dx;
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
