// testing.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;
struct g {
	int used;
	int data;
	int _long;
	g* next;
};

int used[6][6];
vector<g*> arr,w,tmp;
int num = 0, cnt = 0;
void CreateGraph() {
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			used[i][j] = 0;

	int a,Long, i = 0;
	ifstream in("test.txt");
	while (in >> a) {
		//cout << a << " ";
		g* temp;
		temp = new g;
		temp->data = a;
		in >> Long;
		temp->_long = Long;
		temp->next = NULL;
		arr.resize(i + 1);
		arr[i] = temp;
		while (in.peek() != '\n')
		{
			in >> a;
			g* p;
			p = new g;
			temp->next = p;
			p->data = a;
			in >> Long;
			p->_long = Long;
			p->next = NULL;
			temp->next = p;
			temp = p;
			//cout << a << " ";
		};
		//cout << endl;
		i++;
	};
	in.close();

}

int min_elem(int v) {
	
	g* tmp = arr[v - 1];
	if (!tmp) {
		cout << "Элементов нет" << endl;
		return 0;
	}
	int min = 10000000 , min_e=0;
	while (tmp != NULL) {
		if (min > tmp->_long) {
			min = tmp->_long;
			//min_e = tmp->data;
		}
		tmp = tmp->next;
	}
	cout <<"Min:"<< min_e << "[" << min << "]" << endl;
	return min_e;
}

int PRIM() {
	vector<g*>  W;
	vector<int> T(arr.size(),0);


	int min_e = 0, v = 1;

	W.resize(1);
	W[0] = arr[0];
	arr[0] = NULL;
	T[0] = 1;
	cout << "Островное дерево: " << T[0];

	while (W != arr) {
		int  min = 1000, j = 0, count_i = 0,count_j=0;
		
		for (int i = 0; i < v; i++) {
			g* temp = W[i]; j = 0;
			while (temp != NULL) {
				if ((used[i][j]==0)&&(min > temp->_long)) {
					min = temp->_long;
					min_e = temp->data;
					count_j = j;
					count_i = i;
				}
				temp = temp->next;
				j++;
			}
		}
		
		used[count_i][count_j] = 1;

		T[v]=min_e;
		W.resize(v+1);
		W[v] = arr[min_e-1];
		arr[min_e-1] = NULL;

		cout << " >> " << T[v];

		v++;
	}	
	return 0;
	/*
	set< pair<int, int> > u; //обход (длина=dl, вершина)
	vector<g*>  W,T,tmp;
	vector<int> dl(arr.size(), -1); //длина от остова до вершин.
	vector<int> used(arr.size());
	dl[0] = 0;

	//u.insert(make_pair(0, 0));
	W.resize(v + 1);
	W[0] = arr[0];

	while (W != arr) { //обход за n log(m)
		int v = u.begin()->second;
		result += u.begin()->first;//добавляем длину
		u.erase(u.begin());
		used[k] = 1;

		for (int j = 0; j < v[k].size(); ++j) {
			int i = v[k][j].first, len = v[k][j].second;

			if (!used[i] && (dl[i] == -1 || dl[i] > len)) {
				u.erase(make_pair(dl[i], i));
				dl[i] = len;
				u.insert(make_pair(dl[i], i));
				used[i] = -1;
				cout << v[k][j].first << " " << endl;
			}
		}
	}
	cout << result;
	return 0;*/
}


void del(int n, int key)
{

	if (arr[n - 1]->data == key)
	{
		g* tmp = arr[n - 1];
		arr[n - 1] = arr[n - 1]->next;
		delete tmp;
	}
	else
	{
		g* tmp = arr[n - 1];
		while (tmp)
		{
			if (tmp->next)
				if (tmp->next->data == key)
				{
					g* tmp2 = tmp->next;
					tmp->next = tmp->next->next;
					delete tmp2;
				}
			tmp = tmp->next;
		}
	}
}
void Print(int num)
{
	int count;

	for (int i = 0; i < num; i++)
	{

		count = 0;
		g* tmp = arr[i];

		while (tmp)
		{
			cout << tmp->data << "[" << tmp->_long << "] ";
			count++;
			tmp = tmp->next;
		}
		cout << endl;
		//if (count % 2 == 1)
			//return 0;
	}
}

int check_e(int num)
{

	int count;

	for (int i = 0; i < num; i++)
	{

		count = 0;
		g* tmp = arr[i];

		while (tmp)
		{
			cout << tmp->data << "["<<tmp->_long<<"] ";
			count++;
			tmp = tmp->next;
		}
		cout << endl;
		//if (count % 2 == 1)
			//return 0;
	}
	return 0;
}

void search_e()
{
	cout << "Установленна вершина по умолчанию 1. \nЭйлеров цикл: ";
	stack<int> St;
	int v = 1;//Вершина по умолчанию
	int u;
	St.push(v);
	while (!St.empty())
	{

		v = St.top();
		if (!arr[v - 1])
		{
			v = St.top();
			St.pop();
			cout << v << " ";
		}
		else
		{
			u = arr[v - 1]->data;
			St.push(u);
			del(v, u); del(u, v);
		}
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	CreateGraph();
	Print(arr.size());
	min_elem(1);
	PRIM();


	//if (check_e(arr.size()))
		//search_e();
	
	//else
		//cout << "Граф не является эйлеровым.";
	//cout << endl;
	//system("pause");

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
                              