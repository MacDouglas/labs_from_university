// Лаба_8(Графы_а-м Прима).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//С помощью ал-а Прима найти мин. покрывающее дерево для несвязного неориент. графа
//Вывести на экран ребра, вошедшие в искомое дерево и вес построенного дерева.
//Использовать списки смежности. Искомый граф вводится из файла.

#include "pch.h"
using namespace std;

const int INF = 1000000000; // значение "бесконечность"

int main()
{
	int result = 0; //длина всех ребер мин остова
	
	ifstream input_graph("graph.txt");
	int n, m;//кол-во вершин, кол-во ребер
	input_graph >> n;
	input_graph >> m;
	vector< vector< pair<int, int> > >g(n);
	int v1, v2, weight;//вершина1, вершина2, вес ребра между ними(длина)
	
	for (int i = 0; i < m; ++i) {//список смежности
		input_graph >> v1;
		input_graph >> v2;
		input_graph >> weight;
		g[v1 - 1].push_back(make_pair(v2 - 1, weight));
		g[v2 - 1].push_back(make_pair(v1 - 1, weight));
	}
	/*set< pair<int, int> > u; //обход (длина=dl, вершина)
	vector<int> dl(n, -1); //длина от остова до вершин.
	vector<int> used(n);
	dl[0] = 0;
	
	u.insert(make_pair(0, 0));
	
	while (!u.empty()) { //обход за n log(m)
		int k = u.begin()->second;
		
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

	//int n;
	//vector < vector < pair<int, int> > > g;
	//const int INF = 1000000000; // значение "бесконечность"

	// алгоритм
	vector<int> min_e(n, INF), sel_e(n, -1);
	min_e[0] = 0;
	set < pair<int, int> > q;
	q.insert(make_pair(1, 0));
	for (int i = 0; i < n; ++i) {
		if (q.empty()) {
			cout << "No MST!";
			exit(0);
		}
		int v = q.begin()->second;
		q.erase(q.begin());

		if (sel_e[v] != -1)
			cout << v << " " << sel_e[v] << endl;

		for (size_t j = 0; j < g[v].size(); ++j) {
			int to = g[v][j].first,
				cost = g[v][j].second;
			if (cost < min_e[to]) {
				q.erase(make_pair(min_e[to], to));
				min_e[to] = cost;
				sel_e[to] = v;
				q.insert(make_pair(min_e[to], to));
			}
		}
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
