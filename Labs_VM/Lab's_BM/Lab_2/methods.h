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

	void printMatr(double** matr, int n, int CalcDigCount);
	void printArray(double* arr, int n, int CalcDigCount);

	int orthogonalization(double** matr, int n);

	double findArreyX(double** z, double* x, int n);
	double findArrU(int n, int pos, double** u, double** a, double** A);
	double findArrZ(double** u, double** z, int n, int pos);
	
	double findSQRT(int n, int rank, double** a);								//||u||
	double findVector(int n, int posa, int posz, double** a, double** z);		//(ai,zi) - векторное произведение
}
#endif 

