#include "pch.h"
#include "vector.h"

using namespace std;

namespace lab
{
	Vector::Vector() : Base()
	{
	}

	Vector::Vector(int size, double a) : Base(size, 1, a)
	{
	}
	Vector::Vector(int size, const double* a) : Base(size, 1, a)
	{
	}

	Vector::Vector(const Vector& other) : Base(other)
	{
	}
	Vector::Vector(const Base& other) : Base(other)
	{

	}

	Vector::Vector(Base&& other) : Base(std::move(other))
	{
	}
	Vector::Vector(Vector&& other) : Base(std::move(other))
	{
	}

	Vector::~Vector()
	{
		cout << "ƒеструктор объекта класса Vector - " << id << endl;
	}
	int Vector::getSize() const
	{
		return rows;
	}

	double& Vector::operator[](int num)
	{
		if (num >= rows || num < 0)
		{
			throw "Ёлемент в векторе - " + to_string(id) + " не существует!";
		}

		return matrix[num];
	}
	double Vector::operator[](int num) const
	{
		if (num >= rows || num < 0)
		{
			throw "Ёлемент в векторе - " + to_string(id) + " не существует!";
		}

		return matrix[num];
	}
	Vector& Vector::operator=(const Base& other)
	{
		if (this != &other) return *this;

		Base::operator=(other);

		return *this;
	}
	Vector& Vector::operator=(Base&& other)
	{
		if (this != &other) return *this;

		Base::operator = (std::move(other));

		return *this;
	}
	Vector& Vector::operator=(Vector&& other)
	{
		if (this != &other) return *this;

		Base::operator = (std::move(other));

		return *this;
	}
}