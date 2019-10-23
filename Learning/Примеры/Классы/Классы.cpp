
#include "stdafx.h"

using namespace std;

class CoffeGrinder       //Инкапсуляция
{
public:
	void start()	
	{
		bool t = voltage();
		if (t)
			cout << "\nGrinder is done" << endl;
	}

private:
	bool voltage()
	{
		return true;
	}


};

class Point
{
private:
	int x;
	int y;

public:
	Point()                    //Конструктор по умолчанию
	{
		x = 0;
		y = 0;
	}
	Point(int ValueX, int valueY) //Конструктор
	{
		x = ValueX;
		y = valueY; 
	}
	void show()                   //Метод
	{
		cout << "X=" << x << endl;
		cout << "Y=" << y << endl;
	}
	void SetX(int x)         //Setter
	{
		this->x = x;
	} 

	void SetY(int ValueY)
	{
		y = ValueY;
	}

	int GetX()                    //Getter
	{
		return x;
	}

	int GetY()
	{
		return y;
	}

};

class Myslass2
{
private:
	int *data;
	int Size;
public:
	Myslass2(int size)
	{
		this->Size = size;
		this->data = new int[size];
		for (int i = 0; i < size; i++)
			data[i] = i;

		cout << "Contsruktor sozdan " << this << endl;
	}
	Myslass2(const Myslass2 &other)           //Конструктор копирования
	{
		this->Size = other.Size;
		this->data = new int[other.Size];

		for (int i = 0; i < other.Size; i++)
			this->data[i] = other.data[i];
		cout << "Constructor copyrovaniya" << this << endl;

	}
	Myslass2 & operator= (const Myslass2 &other)
	{
		cout << "Вызвался opertor =" << this << endl;
		
		this->Size = other.Size;
		if (this->data != nullptr)
		{
			delete[] this->data;
		}
		this->data = new int[other.Size];

		for (int i = 0; i < other.Size; i++)
			this->data[i] = other.data[i];
		
		return *this;
	}
	~Myslass2()
	{
		cout << "Destructor vizav" << this << endl;
		delete[] data;
	}

};

class Myslass
{
public:
	Myslass(int data)
	{
		this->data = data;
		cout << "Contsruktor sozdan" << this << endl;
	}
	~Myslass()
	{
		cout << "Destructor vizav" << this << endl;
	}
private:
	int data;
};



int main()
{
	setlocale(LC_ALL, "RUS");
	/*Point a(5, 5);
	a.show();
	a.SetX(10);
	a.SetY(15);
	a.show();
	int m, n;
	m = a.GetX();
	n = a.GetY();
	cout << "m=" << m << "\nn=" << n << endl;

	CoffeGrinder b;
	//b.start;*/

	Myslass2 a(5);
	Myslass2 b(4);
	Myslass2 c(3);

	a = b = c;

	return 0;
}

