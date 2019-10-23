// Двумерный масс. как поле объекта.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class Matrix {
	double **matrix;
	int rank;
	int s(int a, int b) {
		if (b < a)return 0;
		else return 1;
	}
public:
	Matrix(int r) {
		rank = r;
		matrix = new double*[rank];
		for (int i = 0; i < rank; i++) {
			matrix[i] = new double[rank];
			for (int j = 0; j < rank; j++) {
				matrix[i][j] = 0;
			}
		}
	}
	~Matrix() {
		for (int i = 0; i < rank; i++) {
			delete[]matrix[i];
		}
		delete[]matrix;
	}
	double *operator[](int k) {
		return matrix[k];
	}
	void show() {
		for (int i = 0; i < rank; i++) {
			for (int j = 0; j < rank; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	Matrix *getMinor(int i, int j) {
		int k, l;
		int r = rank - 1;
		Matrix *t;
		t = new Matrix(r);
		for (k = 0; k < r; k++) {
			for (l = 0; l < r; l++) {
				(*t)[k][l] = matrix[k + s(i, k)][l + s(j, l)];
			}
		}
		return t;
	}
	double det() {
		if (rank == 2) {
			return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
		}
		else {
			int sgn = 1;
			double d = 0;
			Matrix *t;
			for (int j = 0; j < rank; j++) {
				t = getMinor(0, j);
				d += sgn * matrix[0][j] * (t->det());
				sgn *= -1;
				delete t;
			}
			return d;
		}
	}
};

int main()
{
	const int n = 3;
	int i, j;
	double m[][n] = { {1,2,3},{4,5,6},{7,8,9} };
	Matrix a(n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = m[i][j];
		}
	}
	cout << "Matrix A: " << endl;
	a.show();
	cout << "det(A)= " << a.det() << endl;
	int k = 5;
	Matrix b(k);
	srand(100);
	for (i = 0; i < k; i++) {
		for (j = 0; j < k; j++) {
			b[i][j] = rand()%3;
		}
	}
	cout << "Matrix B: " << endl;
	b.show();
	cout << "det(B)= " << b.det() << endl;
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
