#include "stdafx.h"

using namespace std;

struct list 
{
	int info;
	struct list *next; 
	struct list *prev;
};

list *init(int a) 
{ 
	struct list *lst;
	lst = new list;
	lst->info = a;
	lst->next = NULL;
	lst->prev = NULL;
	return(lst);
}

list *addelem(list *lst, int number) 
{
	struct list *temp, *p;
	temp = new list;
	p = lst->next; // сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->info = number; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий узел
	temp->prev = lst; // созданный узел указывает на предыдущий узел
	if (p != NULL)
		p->prev = temp;
	return(temp);
}
list *deletelem(list *lst) 
{
	struct list *prev, *next;
	prev = lst->prev; // узел, предшествующий lst
	next = lst->next; // узел, следующий за lst
	if (prev != NULL)
		prev->next = lst->next; // переставляем указатель
	if (next != NULL)
		next->prev = lst->prev; // переставляем указатель
	free(lst); // освобождаем память удаляемого элемента
	return(prev);
}
list *deletehead(list *root) {
	struct list *temp;
	temp = root->next;
	temp->prev = NULL;
	free(root);   // освобождение памяти текущего корня
	return(temp); // новый корень списка
}
void listprint(list *lst)     //Вывод в прямом порядке
{
	struct list *p;
	p = lst;
	if (p) 
	{
		do
		{
			printf("%d ", p->info); 
			p = p->next;
		} while (p != NULL);
	}
}
void listprintr(list *lst)    //Вывод в обратном порядке 
{
	struct list *p;
	p = lst;
	while (p->next != NULL)
		p = p->next;  // переход к концу списка
	do {
		printf("%d ", p->info); // вывод значения элемента p
		p = p->next; // переход к следующему узлу
	} while (p != NULL); // условие окончания обхода
}
struct list *swap(struct list *lst1, struct list *lst2, struct list *head) {
	// Возвращает новый корень списка
	struct list *prev1, *prev2, *next1, *next2;
	prev1 = lst1->prev;  // узел предшествующий lst1
	prev2 = lst2->prev;  // узел предшествующий lst2
	next1 = lst1->next; // узел следующий за lst1
	next2 = lst2->next; // узел следующий за lst2
	if (lst2 == next1)  // обмениваются соседние узлы
	{
		lst2->next = lst1;
		lst2->prev = prev1;
		lst1->next = next2;
		lst1->prev = lst2;
		if (next2 != NULL)
			next2->prev = lst1;
		if (lst1 != head)
			prev1->next = lst2;
	}
	else if (lst1 == next2)  // обмениваются соседние узлы
	{
		lst1->next = lst2;
		lst1->prev = prev2;
		lst2->next = next1;
		lst2->prev = lst1;
		if (next1 != NULL)
			next1->prev = lst2;
		if (lst2 != head)
			prev2->next = lst1;
	}
	else  // обмениваются отстоящие узлы
	{
		if (lst1 != head)  // указатель prev можно установить только для элемента,
			prev1->next = lst2; // не являющегося корневым
		lst2->next = next1;
		if (lst2 != head)
			prev2->next = lst1;
		lst1->next = next2;
		lst2->prev = prev1;
		if (next2 != NULL) // указатель next можно установить только для элемента,
			next2->prev = lst1; // не являющегося последним
		lst1->prev = prev2;
		if (next1 != NULL)
			next1->prev = lst2;
	}
	if (lst1 == head)
		return(lst2);
	if (lst2 == head)
		return(lst1);
	return(head);
}
void ClearList(struct list *Head) {
	if (Head) {
		if (Head->next)
		{
			do {
				Head = deletehead(Head);
			} while (Head->next);
		}
		free(Head);
	}
}

int main() 
{
	setlocale(LC_ALL, "RUS");
	list *head = NULL, *cur1 = NULL, *cur2=NULL;
	int Counter = 0,num=0;
	while (1) 
	{
		cout << "Введи элемент:"<< endl;
		cin >>num;
		Counter++;
		if (num == 401)
			break;
		if (Counter == 1) 
		{
			head = init(num);
			cur1 = head;
		}
		else 
		{
			cur1 = addelem(cur1, num);    
			cur2 = cur1;
		}

	}

	listprint(head);                              
	cur1 = head;
	int x, y, s=1;
	
	while ((cur1->next) && (cur2->prev))
	{
		x = cur1->info;
		y = cur2->info;
		s = (x * x - y * y);
		s *= s;

		cur1 = cur1->next;
		cur2 = cur2->prev;
	}

	cout << "Summ=" << s << endl;
	ClearList(head);

	system("pause");
	return 0;
}

