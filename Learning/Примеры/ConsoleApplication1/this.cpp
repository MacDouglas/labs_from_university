#include "pch.h"
#include <iostream>
using namespace std;

class MyClass {
private:
	// var;
	int *data;
	int Size;
public:
	//(int a) :var(a) {}
	MyClass(int size){

		this->Size = size;
		this->data = new int[size];
		for (int i = 0; i < size; i++)
			data[i] = i;

		cout << "Contsruktor sozdan " << this << endl;
	}
	MyClass(const MyClass &other)           //Конструктор копирования
	{
		this->Size = other.Size;
		this->data = new int[other.Size];

		for (int i = 0; i < other.Size; i++)
			this->data[i] = other.data[i];
		cout << "Constructor copyrovaniya" << this << endl;
	}
	~MyClass()
	{
		cout << "Destructor vizav" << this << endl;
		delete[] data;
	}
	/*void PrintInfo() {
		cout << var << endl;
		cout << this->var << endl;
		//cout << *(this).var << endl;
	}*/
};

int main()
{
	MyClass obj(5);
	//.PrintInfo();
	MyClass a(obj);

	return 0;
}
