#include "pch.h"

using namespace std;

class BirthDay
{
public:
	BirthDay(int m, int d, int y) :month(m), day(d), year(y) {} //Быстрый конструктор 

	void PrintDate() {
		cout << month << "\t" << day << "\t" << year << endl;
	}
	friend void SomeFunc(BirthDay &obj);          //Дружественная Функция friend
private:
	int month;
	int day;
	int year;
};

class Person {
private:
	string name;
	BirthDay bd;
public:
	Person(string n,BirthDay b):name(n),bd(b){}
	void PrintInfo() {
		cout << name << endl;
		bd.PrintDate();                      //Сама композиция
	}
};

void SomeFunc(BirthDay &obj) {
	obj.month = 10;
	obj.day = 20;
	obj.year = 2001;
	obj.PrintDate();
}
int main()
{
	BirthDay bd(2, 15, 1999);
	Person p("Elias", bd);
	p.PrintInfo();
	
	SomeFunc(bd);              //Вызов функции friend
	p.PrintInfo();

}
