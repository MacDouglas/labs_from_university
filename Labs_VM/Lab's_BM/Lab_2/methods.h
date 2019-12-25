#ifndef METHODS_H
#define METHODS_H

#include <iostream>
#include "PolStr.h"
#include "Matrix.h"
#include <string>
#include <cmath>
#include <stdexcept>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace math_subjects;
namespace maths_methods {

	double** initMatrix(int n, double** a, double* b);

	void printMatr(double** matr, int n, int CalcDigCount);
	void printArray(double* arr, int n, int CalcDigCount);
	void printNumber(double a, int calcDigCount);
	
	void initOrthogonalization(int n, double** a, double** A, double* b);
	double* orthogonalization(double** matr, int n,double *x);
	void findInverseMatr(int n, double** a, double* b, double* x);
	double* takeColumn(int n, int pos, double** E, double* b);
	double** insertColumn(int n, int pos, double** _A, double* x);

	double* findArreyX(double** z, double* x, int n);
	double** findArrU(int n, int pos, double** u, double** a, double** A);
	double findArrZ(int n, int pos,double** u, double** z);
	
	double findSQRT(int n, int rank, double** a);								//||u||
	double findVector(int n, int posa, int posz, double** a, double** z);		//(ai,zi) - векторное произведение

	double* vectorOfResidual(int n, double** A, double* b, double* x);
	double normOfResidual(double* a,int n);
	double** matrixOfResidual(int n, double** AX);
	double normOfMatrix(double** a, int n);
	
	double sqr(double x);
	void clear(double** a, int n);
	double** matrix_multi(double** A, double** B, int n);
	double** createUnitMatrix(int n);
}
#endif 

