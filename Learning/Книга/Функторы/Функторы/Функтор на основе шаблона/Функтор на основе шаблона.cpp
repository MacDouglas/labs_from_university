// Функтор на основе шаблона.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
using namespace std;

template<int power> class polynomial {
private:
	double a[power + 1];
public:
	polynomial(double *b) {
		for (int i = 0; i <= power; i++) {
			a[i] = b[i];
		}
	}
	polynomial() {
		for (int i = 0; i <= power; i++) {
			a[i] = 0;
		}
	}
	int get_power() {
		return  power;
	}
	double &operator[](int k) {
		return a[k];
	}
	double operator() (double x){
		double s = 0, q = 1;
		for (int i = 0; i <= power; i++) {
			s += a[i] * q;
			q *= x;
		}
		return s;
	}
	//обобщеный операторный метод для вычисления произведения полиномов.
	template<int n>polynomial<power + n>operator*(polynomial<n> p) {
		const int m = power + n;
		polynomial<m> tmp;
		for (int i = 0; i <= power; i++) {
			for (int j = 0; j <= n; j++) {
				tmp[i + j] += a[i] * p[j];
			}
		}
		return tmp;
	}
	void coefs() {
		for (int i = 0; i <= power; i++) {
			cout << a[i] << "\t";
		}
		cout << endl;
	}
};

int main()
{
	srand(100);
	const int n = 2;
	const int m = 3;
	double nums[n + 1] = { 3,-2,1 };
	cout << "Polynom;s";
	polynomial<n> p(nums);
	cout << "p:\t";
	p.coefs();
	polynomial<m>q;
	cout << "q:\t";
	q.coefs();
	for (int i = 0; i <= q.get_power(); i++) {
		q[i] = rand() % 5 - 2;
	}
	cout << "q:\t";
	q.coefs();
	cout << "p*q=\t";
	(p*q).coefs();
	polynomial<n + m>r;
	r = p * q;
	cout << "r:\t";
	r.coefs();
	cout << "Result's of polynom's:" << endl;
	double x = -2, dx = 1;
	for (int k = 1; k <= 5; k++) {
		cout << "p(" << x << ")=" << p(x) << "\t";
		cout << "q(" << x << ")=" << q(x) << "\t";
		cout << "r(" << x << ")=" << r(x) << "\t";
		cout << "(p*q)(" << x << ")=" << (p*q)(x) << endl;
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
