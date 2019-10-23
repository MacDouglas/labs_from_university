#ifndef VECTOR_H
#define VECTOR_H

#include "inheritance.h"
#include "matrix.h"
#include <iostream> 

namespace math_subjects {

	class Vector : public Base
	{
	private:

	protected:

	public:
		Vector();
		explicit Vector(int size, double a = 0);
		Vector(int size, const double* a);
		Vector(const Vector& other);
		Vector(const Base& other);
		Vector(Base&& other);
		Vector(Vector&& other);
		~Vector();

		int getSize() const;
		int findRank(const Base & other) const ;
		int findRank(Base&& other);

		double& operator[](int num);
		double operator[](int num) const;

		Vector& operator=(const Vector& other);

		Vector& operator=(const Base& other);
		Vector& operator=(Base&& other);
		Vector& operator=(Vector&& other);
	};
}
#endif VECTOR_H
