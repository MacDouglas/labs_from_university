#include "pch.h"
#include "Matrix.h"
using namespace std;

namespace matrix_space {
	int Matrix::i = 1;
	Matrix::Matrix(): Matrix(0,0,0) {}                
	Matrix::Matrix(int rows, int cols, double num = 0) { //С заданными компонентами(число,массив)
		this->rows = rows;
		this->cols = cols;
		matrix = new double*[rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new double[cols];
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = num;
			}
		}
		identification();
	}
	Matrix::Matrix(int size,double num=0, double *a=0){ //С заданными компонентами(число,массив)
		this->rows = size;
		this->cols = size;
		matrix = new double*[size];
		for (int i = 0; i < size; i++) {
			matrix[i] = new double[size];
			for (int j = 0; j < size; j++) {
				matrix[i][j] = num;
			}
		}
		identification();
	}
	Matrix::Matrix(const Matrix &other) {
		this->rows = other.rows;
		this->cols = other.cols;
		this->matrix = new double*[other.rows];
		for (i = 0; i < this->rows; i++) {
			matrix[i] = new double[other.cols];
			for (int j = 0; j < this->cols; j++) {
				this->matrix[i][j] = other.matrix[i][j];
			}
		}
		identification();
	}
	void Matrix::identification() { //При копировании не увеличивает на 1
		id = i++;
		cout << "Конструктор матрицы - " << id << endl;
	}
	void Matrix::show() const{
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	double * Matrix::operator[](int num)
	{
		return matrix[num];
	}
	Matrix & Matrix::operator=(const Matrix & other)
	{
		if (this->matrix != nullptr)
		{
			for (int i = 0; i < rows; i++) {
				delete[]matrix[i];
			}
			delete[] this->matrix;
		}
		rows = other.rows;
		cols = other.cols;
		this->matrix =new double*[rows];
		for (i = 0; i < rows; i++) {
			matrix[i] = new double[cols];
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = other.matrix[i][j];
			}
		}
		return *this;
	}
	Matrix & Matrix::operator+=(const Matrix &b) {
		if (!sum_ans(b))
			return *this;
		else
		{
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					matrix[i][j] += b.matrix[i][j];
				}
			}
		}
		return *this;
	}
	Matrix & Matrix::operator-=(const Matrix &b) {
		if (!sum_ans(b))
			return *this;
		else
		{
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					matrix[i][j] -= b.matrix[i][j];
				}
			}
		}
		return *this;
	}
	Matrix & Matrix::scal_multip(double scal)
	{
		for (int i = 0; i < rows; i++) {	
			for (int j = 0; j < cols; j++) {
				matrix[i][j] *= scal;
			}
		}
		return *this;
	}
	
	/* & Matrix::operator*=(const Matrix &b) {
		if (!multip_ans(b)) {
			return *this;
		}
		else
		{
			double **nums, tmp;
			for (int i = 0; i < rows; i++){
				nums = new double*[i];
				for (int j = 0; j < b.cols; j++) {
					tmp = 0;
					for (int l = 0; l < rows; l++) {
						tmp += matrix[i][l] * b.matrix[l][j];
					}
					nums[i][j] = tmp;
				}
			}
			for (i = 0; i < rows; i++){
				delete[]matrix[i];
			}
			delete[]matrix;
			
			matrix = new double*[rows];
			for (i = 0; i < rows; i++) {
				matrix[i] = new double[i];
				for (int j = 0; j < b.cols; j++) {
					matrix[i][j] = nums[i][j];
				}
			}
			for (i = 0; i < rows; i++) {
				delete[]nums[i];
			}
			delete[]nums;
			return *this;
		}
	}*/
	
	Matrix::~Matrix()
	{
		for (int i = 0; i < rows; i++) {
			delete[]matrix[i];
		}
		delete[]matrix;
		cout << "Деструктор матрицы - " << id << endl;
	}
	bool Matrix::sum_ans(const Matrix & b) const {  //Убрать 2 ретерна, оставить 1 
		return (cols == b.cols && rows == b.rows);
	}
	bool Matrix::multip_ans(const Matrix &b)const {
		if (cols != b.rows) 
			return false;
		return true;
	}
	double Matrix::find_max() const{
		double max=matrix[0][0];
		for (int i = 0; i < cols; i++) {
			for (int j = 0; j < rows; j++) {
				if (max < matrix[i][j])
					max = matrix[i][j];
			}
		}
		return max;
	}
	double Matrix::find_min()const {
		double min = matrix[0][0];
		for (int i = 0; i < cols; i++) {
			for (int j = 0; j < rows; j++) {
				if (min > matrix[i][j])
					min = matrix[i][j];
			}
		}
		return min;
	}

} 