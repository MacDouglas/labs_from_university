//Создать файл из 15 целых чисел. Написать программу, которая реализует метод закрытого хеширования с двойным хеширования
//И хеш функцией, основанная на методе умножения. Занести данные, хранящиеся в файле в хештаблицу. 
//Вывести построенную хеш таблицу на экран. Организовать поиск данных в хештаблице.
#include "pch.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
const int m = 15;

int h(int k) {
	double A = 0.6180339, *p;
	double B = k * A;
	p = &B;
	double res = m*(modf(B,p));
	int b = (int)res;
	return b;
}
int H(int k, int i) {
	int j = (h(k) + i * h(k)) % m;
	return j;
}
int hash_insert(int *T,int k) {
	int i = 0, j = 0;
	do {
		j = H(k, i);
		if (T[j] == NULL) {
			T[j] = k;
			cout << T[j] << endl;
			return j;
		}
		else
			i++;
	} while (i != m);
	cout <<"k="<< k << " i="<< i <<" Table is overfull " << endl;
}
int hash_search(int *T, int k) {
	int i = 0, j = 0;
	do {
		j = H(k, i);
		if (T[j] == k) {
			cout << "a[" << j << "]=" << T[j] << " i=" << i << endl;
			return j;
		}
		else
			i++;
	} while ((T[j] == NULL) || (i != m));
	cout << "k=" << k << " i=" << i << " Table is over " << endl;
	return NULL;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int a[m],i = 0, k = 0;
	
	for (int j = 0; j < m; j++)
		a[j] = NULL;

	fstream F;
	F.open("test.txt");

	while (!F.eof()) {
		F >> k;
		hash_insert(a, k);
	}

	F.close();
	cout << endl;
	for (int j = 0; j < m; j++) {
		cout << "a[ "<<j<<" ]= "<<a[j] << endl;
	}
	cout << "Enter a key= ";
	cin >> k;
	hash_search(a, k);

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
