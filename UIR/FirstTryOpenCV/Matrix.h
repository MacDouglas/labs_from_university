#include "pch.h"

namespace matrix_space {

	class Matrix
	{
	private:
		double **matrix; //Указатель на указатель
		int rows; //Строки
		int cols; //Стобцы
		static int i;
		int id;
		void identification();
	public:
		Matrix();
		Matrix(int rows,int cols, double num);
		Matrix(int size, double num, double * a);
		Matrix(const Matrix &other);
		void show() const;
		double *operator[](int num);
		Matrix &operator=(const Matrix &other);
		Matrix & operator+=(const Matrix & b);
		Matrix & operator-=(const Matrix & b);
		Matrix & scal_multip(double scal);
		Matrix & operator*=(const Matrix & b);
		~Matrix();
		bool sum_ans(const Matrix &b) const;
		bool multip_ans(const Matrix &b)const;
		double find_max()const;
		double find_min() const;
	};

}