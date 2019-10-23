﻿// Client_lab_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "client.h"


using namespace std;
using namespace clients_objects;

int main()
{
	client A(1080);
	cout << "Sin = " << A.get_param() << endl;

	client B(1180);

	cout << "Cos = " << B.get_param() << endl;
	cout << "Tan = Sin/cos = " << tan(A.get_param() / B.get_param()) << endl;
	
	client C(1280);
	cout << "Div = " << C.get_param() << endl;
	cout << "Tan = num1/num2 = " << tan(C.get_param()) << endl;

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
