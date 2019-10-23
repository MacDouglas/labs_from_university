#ifndef MATRIX_H
#define MATRIX_H

#include "inheritance.h"
#include "vector.h"
#include <iostream> 


namespace math_subjects {

	class Matrix : public Base
	{
	private:

	protected:

	public:
		Matrix();
		Matrix(int rows, int cols, double a = 0);
		Matrix(int rows, int cols, const double* a);
		explicit Matrix(int size, double a = 0);
		Matrix(int size, const double* a);
		Matrix(const Matrix& other);
		Matrix(const Base& other);
		Matrix(Base&& other);
		Matrix(Matrix&& other);
		~Matrix();

		int getCols() const;
		int getRows() const;

		double* operator[](int num);
		const double* operator[](int num) const;

		Matrix& operator=(const Base& other);
		Matrix& operator=(Base&& other);
		Matrix& operator=(Matrix&& other);
	};

}
#endif MATRIX_H