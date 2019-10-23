// Лаба_7(Графы).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Ориентированная матрица транзитивного замыкания с помощью ал-а Уоршалла 
//Матрица смежности

#include "pch.h"
using namespace std;

int i, j;

void printMatrix(int **matrix,int n) {
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Warshall(int **matrix, int n)
{
	printMatrix(matrix, n);
	//оператор min заменяется дизъюнкцией, сложение заменяется конъюнкцией
	
	for (int k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (matrix[i][j] == 0) {
					if ((matrix[i][k] == 1) && (matrix[k][j] == 1)) {
						matrix[i][j] = 1;
					}
				}
				else {
					matrix[i][j] = 1;
				}
				
	printMatrix(matrix, n);
}

void findDepth(int **matrix) {

	stack<int> Stack;
	int nodes[4]; 
	for (int i = 0; i < 4; i++) 
		nodes[i] = 0;
	
	Stack.push(0); 
	while (!Stack.empty())
	{ 
		int node = Stack.top(); 
		Stack.pop();

		if (nodes[node] == 2) 
			continue;
		nodes[node] = 2; 
		for (int j = 3; j >= 0; j--)
		{
			if (matrix[node][j] == 1 && nodes[j] != 2)
			{ 
				Stack.push(j); 
				nodes[j] = 1; 
			}
		}
		cout << node + 1 << endl; 
	}
	cin.get();
}

	int main()

{
	//int mas[4][4] = { {0,1,0,0},{0,0,0,1},{0,0,0,0},{1,0,1,0} };
	stack<int> Stack;
	int v , size = 0;
	ifstream input_graph("graph.txt");
	while (!(input_graph.eof())) {
		input_graph >> v;
		Stack.push(v);
		size++;
	}
	size = sqrt(size);
	int **mas;
	mas = new int*[size];
	for (int i = 0; i < size; i++) {
		mas[i] = new int[size];
	}
	input_graph.close();
	
	for (int i = size ; i > 0; i--) {
		for (int j = size ; j > 0; j--) {
			mas[i-1][j-1] = Stack.top();
				Stack.pop();
		}
	}

	Warshall(mas, 4);
	//findDepth(mas);

	for (int i = 0; i < size; i++) {
		delete[]mas[i];
	}
	delete[]mas;

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
