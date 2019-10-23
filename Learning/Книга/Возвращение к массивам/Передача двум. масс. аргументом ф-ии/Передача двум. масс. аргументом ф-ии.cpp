// Передача двум. масс. аргументом ф-ии.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>

using namespace std;
const int Size = 4;


void show(int **p, int m, int n) {
	cout << "Dynamic matrix: " << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
}
void show(int p[][Size], int m) {
	cout << "Static matrix: " << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < Size; j++) {
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
}
void set(int **p, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			p[i][j]=rand()%10;
		}
	}
}
void set(int p[][Size], int m) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < Size; j++) {
			p[i][j] = rand() % 10;
		}
	}
}
int **create(int m, int n) {
	int **p;
	p = new int*[m];
	for (int i = 0; i < m; i++) {
		p[i] = new int[n];
	}
	return p;
}
void del(int **p, int m, int n) {
	for (int i = 0; i < m; i++) {
		delete[]p[i];
	}
	delete[]p;
}

int main()
{
	srand(100);
	int **A;
	A = create(3, 5);
	set(A, 3, 5);
	cout << "Matrix A:" << endl;
	show(A, 3, 5);
	int *B[2];
	int nums[] = { 1,2,3,4,5,6,7,8,9 };
	B[0] = nums;
	B[1] = A[0];
	cout << "Matrix B:" << endl;
	show(B, 2, 5);
	set(B, 2, 5);
	cout << "Matrix A changed 1 line" << endl;
	show(A, 3, 5);
	int C[2][Size];
	cout << "Matrix C:" << endl;
	set(C, 2);
	show(C, 2);
	del(A, 3, 5);
	return 0;
}
