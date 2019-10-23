#include "pch.h"
#include "vector.h"

using namespace std;

namespace math_subjects {
	Vector::Vector() : Base() {}

	Vector::Vector(int size, double a) : Base(size, 1, a) {}
	Vector::Vector(int size, const double* a) : Base(size, 1, a) {}

	Vector::Vector(const Vector& other) : Base(other) {}
	Vector::Vector(const Base& other) {
		operator=(other);
	}

	Vector::Vector(Base&& other) {
		operator=(std::move(other));
	}
	Vector::Vector(Vector&& other) : Base(std::move(other)) {}

	Vector::~Vector()
	{
		cout << "Деструктор объекта класса Vector - " << id << endl;
	}
	int Vector::getSize() const
	{
		return rows;
	}
	int Vector::findRank(const Base & other) const
	{
		Matrix a(other);
		int _cols = a.getCols();

		return _cols;
	}
	int Vector::findRank(Base && other) 
	{
		Matrix a(std::move(other));
		int _cols = a.getCols();
		other = std::move(a);

		return _cols;
	}
	double& Vector::operator[](int num) {
		if (num >= rows || num < 0)
		{
			throw "Элемент в векторе - " + to_string(id) + " не существует!";
		}

		return matrix[num];
	}
	double Vector::operator[](int num) const {
		if (num >= rows || num < 0)
		{
			throw "Элемент в векторе - " + to_string(id) + " не существует!";
		}

		return matrix[num];
	}
	Vector& Vector::operator=(const Vector& other)
	{	
		if (this != &other) return *this;

		Base::operator=(other);

		return *this;
	}
	Vector& Vector::operator=(const Base & other)
	{
		
		if (findRank(other) > 1)
			throw "Невозможно присвоить матрицу №" + to_string(other.get_id()) + " вектору №" + to_string(id) + " так как матрица имеет не корректный размер";

		if (!findtype(other))
			return *this;

		if (this != &other) return *this;

		Base::operator=(other);

		return *this;
	}
	Vector& Vector::operator=(Base && other)
	{
		if (findRank(std::move(other)) > 1)
			throw "Невозможно присвоить матрицу №" + to_string(other.get_id()) + " вектору №" + to_string(id) + " так как матрица имеет не корректный размер";

		if (!findtype(other))
			return *this;

		if (this != &other) return *this;

		Base::operator = (std::move(other));

		return *this;
	}
	Vector& Vector::operator=(Vector && other)
	{
		if (this != &other) return *this;

		Base::operator = (std::move(other));

		return *this;
	}
}