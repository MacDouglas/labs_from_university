#include "pch.h"
#include "Matrix.h"
using namespace std;

namespace math_subjects {
	int Matrix::counter = 0;

	Matrix::Matrix() {
		cols = rows = 0;
		matrix = 0;//NULL
		identification();
	}
	Matrix::Matrix(int rows, int cols, double a) { // Квадратная с числом
		create_Matrix(rows, cols, a);
	}
	Matrix::Matrix(int rows, int cols, double* a) { // Квадратная с числом
		create_Matrix(rows, cols, a);
	}
	Matrix::Matrix(int size, double a) {  // Прямоугольная с числом
		create_Matrix(size, size, a);
	}
	Matrix::Matrix(int size, double* a) {  // Прямоугольная с массивом
		create_Matrix(size, size, a);
	}
	Matrix::Matrix(const Matrix& other) {
		create_Matrix(other.rows, other.cols, other.matrix);
	}
	Matrix::Matrix(Matrix&& other) {  //Коннструктор переноса
		matrix = other.matrix;
		cols = other.cols;
		rows = other.rows;

		other.matrix = nullptr;
		other.rows = 0;
		other.cols = 0;
	}
	void Matrix::create_Matrix(int rows, int cols, const double* a, int off)
	{
		identification();

		this->rows = rows;
		this->cols = cols;
		if (this->cols < 0 || this->rows < 0) {
			throw "Не корректный размер матрицы" + to_string(id);
		}

		matrix = new double[this->rows * this->cols];
		if (!a) {
			for (int i = 0, size = this->rows * this->cols; i < size; i++) {
				matrix[i] = 0;
			}
		}
		else if (a) {
			for (int i = 0, size = this->rows * this->cols; i < size; i++) {
				matrix[i] = *a;
				a += off;
			}
		}
	}
	void Matrix::create_Matrix(int rows, int cols, double a)
	{
		create_Matrix(rows, cols, &a, 0);
	}
	void Matrix::swap(Matrix& a)
	{
		std::swap(matrix, a.matrix);
		std::swap(cols, a.cols);
		std::swap(rows, a.rows);
	}

	Matrix::~Matrix()
	{
		cout << "Деструктор матрицы - " << id << endl;
		if (matrix)
			delete[] matrix;
	}
	void Matrix::identification()
	{
		id = ++counter;
		cout << "Конструктор матрицы - " << id << endl;
	}
	int Matrix::get_rows() const
	{
		return rows;
	}
	int Matrix::get_cols() const
	{
		return cols;
	}
	int Matrix::get_id() const
	{
		return id;
	}
	int Matrix::get_counter()
	{
		return Matrix::counter;
	}
	bool Matrix::sum_ans(const Matrix& b) const
	{
		return (cols == b.cols && rows == b.rows);
	}
	bool Matrix::multip_ans(const Matrix & b)const
	{
		return (cols == b.rows);
	}

	double Matrix::find_max() const
	{
		if (!matrix) {
			throw "Нельзя найти макс. элемент в матрице " + to_string(id) + ", так как матрица не инициализирована!";
		}

		double max = matrix[0];
		for (int i = 1, size = rows * cols; i < size; i++) {
			if (max < matrix[i])
				max = matrix[i];
		}
		return max;
	}

	double Matrix::find_min() const
	{
		if (!matrix)
		{
			throw "Нельзя найти макс.элемент в матрице " + to_string(id) + ", так как матрица не инициализирована!";
		}

		double min = matrix[0];
		for (int i = 1, size = rows * cols; i < size; i++) {
			if (min > matrix[i])
				min = matrix[i];
		}

		return min;
	}

	double* Matrix::operator[](int num)
	{
		if (num >= rows || num < 0)
		{
			throw "Элемент не существует в матрицe " + to_string(id);
		}
		return matrix + num * rows;
	}
	const double* Matrix::operator[](int num) const
	{
		if (num >= rows || num < 0)
		{
			throw "Элемент не существует в матрице № !" + to_string(id);
		}

		return matrix + num * rows;
	}

	Matrix& Matrix::operator=(const Matrix & other)
	{
		if (cols * rows != other.cols * other.rows)
		{
			if (matrix)
				delete[] matrix;
			if (other.matrix)
			{
				matrix = new double[other.cols * other.rows];
			}
			else
				matrix = NULL;
		}
		cols = other.cols;
		rows = other.rows;
		for (int i = 0, size = cols * rows; i < size; i++)
			matrix[i] = other.matrix[i];

		return *this;
	}
	Matrix& Matrix::operator=(Matrix && other) 
	{
		if (this != &other) return *this;

		if (matrix)
			delete[] matrix;

		matrix = other.matrix;
		cols = other.cols;
		rows = other.rows;

		other.matrix = nullptr;
		other.cols = 0;
		other.rows = 0;

		return *this;
	}
	Matrix& Matrix::operator+=(const Matrix & b) {
		if (!sum_ans(b))
			throw "Операция += невозможна, т.к. размеры матриц " + to_string(id) + " и " + to_string(b.get_id()) + " не совпадают!";

		for (int i = 0, size = rows * cols; i < size; i++)
			matrix[i] += b.matrix[i];

		return *this;
	}
	Matrix& Matrix::operator-=(const Matrix & b) {
		if (!sum_ans(b))
			throw "Операция -= невозможна, т.к. размеры матриц " + to_string(id) + " и " + to_string(b.get_id()) + " не совпадают!";

		for (int i = 0, size = rows * cols; i < size; i++)
			matrix[i] -= b.matrix[i];

		return *this;
	}
	Matrix& Matrix::operator*=(double scal)
	{
		if (cols < 0 || rows < 0)
			throw "Не корректный размер матрицы" + to_string(id);

		for (int i = 0, size = rows * cols; i < size; i++)
			matrix[i] *= scal;

		return *this;
	}
	Matrix & Matrix::operator*=(const Matrix & b) {
		if (!multip_ans(b))
			throw "Операция *= невозможна, т.к. размеры матриц " + to_string(id) + " и " + to_string(b.get_id()) + " не совпадают!";

		Matrix tmp(cols, b.rows);
		for (int i = 0; i < cols; i++)
			for (int j = 0; j < b.rows; j++)
				for (int k = 0; k < rows; k++)
					tmp.matrix[i * cols + j] += matrix[i * cols + k] * b.matrix[k * b.cols + j];

		*this = std::move(tmp);
		return *this;
	}
	Matrix operator+(const Matrix & a, const Matrix & b) {
		return Matrix(a) += b;
	}
	Matrix operator-(const Matrix & a, const Matrix & b) {
		return Matrix(a) -= b;
	}
	Matrix operator*(const Matrix & a, const Matrix & b) {
		return Matrix(a) *= b;
	}
	Matrix operator*(const Matrix & a, double k) {
		return Matrix(a) *= k;
	}
	Matrix operator*(double k, const Matrix & a) {
		return Matrix(a) *= k;
	}
	ostream& operator<<(ostream & ostream, const Matrix & a) {
		std::streamsize width = ostream.width();
		for (int i = 0; i < a.rows; i++) {
			for (int j = 0; j < a.cols; j++) {
				ostream.width(width);
				ostream << a.matrix[i * a.cols + j];
				if (!width)
					std::cout << " ";
			}
			ostream << endl;

		}
		return ostream;
	}

}