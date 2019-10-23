/*
Holder a(Holder(1));	//Перемещение

Holder b(a);			//Копирование

Holder c(std::move(b));	//Перемещение

a = b;					//Копирование

b = std::move(c);		//Перемещение

c = Holder(1);			//Перемещение
*/

#include <iostream>


using namespace std;

class Holder
{
public:

	Holder(int size)         
	{
		m_data = new int[size];
		m_size = size;
	}
	Holder(const Holder& other)
	{
		m_data = new int[other.m_size];  // (1)
		std::copy(other.m_data, other.m_data + other.m_size, m_data);  // (2)
		m_size = other.m_size;
	}
	Holder& operator=(const Holder& other)
	{
		if (this == &other) return *this;  // (1)
		delete[] m_data;  // (2)
		m_data = new int[other.m_size];
		std::copy(other.m_data, other.m_data + other.m_size, m_data);
		m_size = other.m_size;
		return *this;  // (3)
	}
	Holder& operator=(Holder&& other)     // <-- rvalue reference in input  
	{
		if (this == &other) return *this;

		swap(other);
		/*delete[] m_data;         // (1)

		m_data = other.m_data;   // (2)
		m_size = other.m_size;

		other.m_data = nullptr;  // (3)
		other.m_size = 0;*/

		return *this;
	}
	Holder(Holder&& other)     // <-- rvalue reference in input
	{
		swap(other);
		//m_data = other.m_data;   // (1)
		//m_size = other.m_size;
		//other.m_data = nullptr;  // (2)
		//other.m_size = 0;
	}
	void swap(Holder& a) {
		std::swap(m_data, a.m_data);
		std::swap(m_size, a.m_size);
	}
	~Holder()                
	{
		delete[] m_data;
	}

private:

	int* m_data = nullptr;
	size_t m_size = 0;
};

int main()
{
	Holder h1(5);                // regular constructor
	Holder h2(h1);                  // copy constructor (lvalue in input)
	Holder h3(std::move(h2)); // move constructor (rvalue in input) (1) 

	h2 = h3;                        // assignment operator (lvalue in input)
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
