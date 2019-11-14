#include "methods.h"
#include "Matrix.h"

using namespace std;
using namespace math_subjects;

namespace maths_methods {

	int orthogonalization(double** matrix, int n) {
		
		double** z, ** u,*x;
		z = new double* [n]; u = new double* [n]; x = new double[n];
		
		
		for (int i = 0; i < n; i++) {
			z[i] = new double[n]; u[i] = new double[n]; x[i] = 0;

			for (int j = 0; j < n; j++) {
				z[i][j] = 0; u[i][j] = 0; 
			}
		}

		for (int i = 0; i < n; i++) {
			findArrU(n, i, u, matrix,z);
			findArrZ(u, z, n, i);
		}

		printMatr(u, n , 7);
		printMatr(z, n, 7);

		findArreyX(z, x, n);

		for (int i = 0; i < n; i++) {
			delete[] z[i]; 
			delete[] u[i];
		}
		delete[] z; 
		delete[] u; 
		delete[] x;
		
		return 0;
	}

	double findArreyX(double** z,double *x, int n) {

		for (int i = 0; i < n; i++) {
			x[i] = z[n-1][i] / z[n-1][n-1];
		}
		printArray(x, n - 1, 5);
		return *x;
	}

	double findArrU(int n, int pos, double** u, double **A, double **z) { //Доделать после else
		double tmp,vector;
		if (pos == 0) {
			
			for (int i = 0; i < n; i++) 
				u[pos][i] = A[pos][i];
		
			return **u;
		}
		else {
			for (int k = 0; k < n; k++)
				u[pos][k] = A[pos][k];

			for (int j = 0; j < pos; j++) {
				vector = findVector(n, pos, j, A, z);

				for (int i = 0; i < n; i++) {
					tmp =  vector * z[j][i];
					u[pos][i] -= tmp;
				}
				
			}

			return **u;
		}
	}
	double findArrZ(double** u, double** z, int n, int pos) {
		double tmp = findSQRT(n,pos,u);

		for (int i = 0; i < n; i++) {
			z[pos][i] = u[pos][i] / tmp;
		}
		return **z;
	}
	double findSQRT(int n, int rank, double** a) {

		double tmp,result = 0;
		int i = 0;

		while (i < n) {
			tmp = a[rank][i] * a[rank][i];
			result += tmp;
			i++;
		}

		return sqrt(result);
	}
	double findVector(int n, int posa,int posz, double** a, double** z) {
		
		double tmp, result = 0;
		int i = 0;

		while (i < n) {
			tmp = a[posa][i] * z[posz][i];
			result += tmp;
			i++;
		}

		return result;
	}
	void printMatr(double** matr, int n, int CalcDigCount) {
		
		ofstream fout;
		fout.open("output.txt", ios::app);

		cout << endl;
		fout << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << setprecision(CalcDigCount) << matr[i][j] << " \t";
				fout << setprecision(CalcDigCount) << matr[i][j] << " \t";
			}
			cout << endl;
			fout << endl;
		}
		fout.close();
	}
	void printArray(double* arr, int n, int CalcDigCount) {
		
		ofstream fout;
		fout.open("output.txt",ios::app);

		cout << endl;
		fout << endl;
		for (int i = 0; i < n; i++) {
			cout << setprecision(2) << arr[i] << " \t";
			fout << setprecision(CalcDigCount) << arr[i] << " \t";
		}
		cout << endl;
		fout.close();
	}
	
}