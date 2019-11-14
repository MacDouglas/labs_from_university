#ifndef MATRIX_H
#define MATRIX_H

#include <iostream> 

namespace math_subjects {

	class Matrix
	{
	protected:
		double* matrix;
		int rows, cols, id;
		static int counter;
		void identification();

	private:

		void create_Matrix(int rows, int cols, double a);
		void create_Matrix(int rows, int cols, const double* a, int = 1);
		void swap(Matrix& a);
	public:
		explicit Matrix();
		explicit Matrix(int rows, int cols, double num = 0);
		explicit Matrix(int rows, int cols, double* a);
		explicit Matrix(int size, double a = 0);
		explicit Matrix(int size, double* a);
		Matrix(const Matrix& other);
		Matrix(Matrix&& other);

		int get_rows() const;
		int get_cols() const;
		int get_id() const;
		static int get_counter();
		~Matrix();
		bool sum_ans(const Matrix& b) const;
		bool multip_ans(const Matrix& b)const;
		double find_max() const;
		double find_min() const;
		double* operator[](int num);
		const double* operator[](int num) const;
		Matrix& operator=(const Matrix& other);
		Matrix& operator=(Matrix&& other);
		Matrix& operator+=(const Matrix& b);
		Matrix& operator-=(const Matrix& b);
		Matrix& operator*=(double scal);
		Matrix& operator*=(const Matrix& b);
		friend Matrix operator+(const Matrix& a, const Matrix& b);
		friend Matrix operator-(const Matrix& a, const Matrix& b);
		friend Matrix operator*(const Matrix& a, const Matrix& b);
		friend Matrix operator*(const Matrix& a, double k);
		friend Matrix operator*(double k, const Matrix& a);
		friend std::ostream& operator <<(std::ostream& stream, const Matrix& a);
	};
}
#endif MATRIX_H