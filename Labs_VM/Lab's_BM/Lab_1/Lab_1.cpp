// Lab_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "PolStr.h"
#include <string>
#include <cmath>
#include <fstream>

#include "method's.h"

using namespace std;
using namespace maths_methods;

int main()
{
	int key;
	char  str1[1024];
	char* str2;

	double x, fx, e;
	double a, b, eps;

	ifstream fin("input.txt");
	if (!fin.is_open()) {
		throw "File don't open!";
	}
	else {
		fin >> key;
		fin >> str1;
		fin >> a;
		fin >> b;
		fin >> eps;
		fin.close();
	}

	try {
		str2 = CreatePolStr(str1, 0);
		if (key == 1)
			x = dihotomy(str2, a, b, eps, fx, e);
		if (key == 2)
			x = chord(str2, a, b, eps, fx, e);
		if (key == 3)
			x = newton(str2, a, b, eps, fx, e);
		if (key == 4)
			x = combined(str2, a, b, eps, fx, e);
		if (key == 5)
			x = iteration(str2, a, b, eps, fx, e);
		if (key == 6)
			x = golden(str2, a, b, eps, fx, e);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	//cout.precision(-log10(eps));
	//cout<< "x= " << x << "f(x)= " << fx << endl;

	ofstream fout("output.txt");
	fout.precision(-log10(eps));
	fout << fixed << "x= " << x << "\n";
	fout << fixed << "f(x)= " << fx << "\n";
	fout << "eps= " << scientific << e;

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
