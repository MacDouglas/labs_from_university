#include "stdafx.h"

struct StackNode
{
	int info;
	StackNode *next;
};
StackNode *Stack1;
StackNode *Stack2;

void init1()
{
	Stack1 = NULL;
}
void init2()
{
	Stack2 = NULL;
}
int isEmpty1()
{
	if (Stack1 == NULL)
		return 1;
	else
		return 0;
}
int isEmpty2()
{
	if (Stack2 == NULL)
		return 1;
	else
		return 0;
}
void Push1(char a)
{
	StackNode *p;
	p = new StackNode;
	p->info = a;
	p->next = Stack1;
	Stack1 = p;
}

void Push2(char a)
{
	StackNode *p;
	p = new StackNode;
	p->info = a;
	p->next = Stack2;
	Stack2 = p;
}

int Pop1()
{
	int val = 0;
	StackNode *p;
	if (isEmpty1 == 0)
		val = Stack1->info;
	p = Stack1;
	Stack1 = p->next;
	return (val);
}

int Pop2()
{
	int val = 0;
	StackNode *p;
	if (isEmpty2 == 0)
		val = Stack2->info;
	p = Stack2;
	Stack2 = p->next;
	return (val);
}

using namespace std;
int main()
{
	string path = "test.txt";
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error with openning" << endl;
	}
	else
	{
		cout << "File was opened" << endl;
		char ch,a,b,o;
		while (fin.get(ch))
		{
			if (ch == 1 || ch == 0)
				Push1(ch);
			if (ch == '+' || ch == '*')
				Push2(ch);
			if (ch == ')')
			{
				a = Pop1();
				b = Pop2();
				o = Pop2();
				if (o == '*')
					a = a * b;
				if (o == '+')
					a = a + b;
				if (isEmpty1() == 1 && isEmpty2() == 1)
				{
					cout << a << endl;
					break;
				}
				else
				{
					Push1(a);
					cout << "Stack's not empty. Find a error" << endl;
				}


			}

			//cout << ch;
		}
	}
	fin.close();

	return 0;
}