#include "methods.h"
#include "Matrix.h"

using namespace std;
using namespace math_subjects;

namespace maths_methods {

	void initOrthogonalization(int n,double **A,double **a,double *b) {
		double* x;
		x = new double[n+1];							//Вектор решения

		printMatr(A, n + 1, 5);						//Расширенная матрица A'
	
		orthogonalization(A, n + 1,x);				//Матрица U,Z, вектор решения

		vectorOfResidual(n, a, b, x);				//Вектор невязки

		clear(A, n + 1);

		findInverseMatr(n, a, b,x);					//Обратная матрица

	}

	void findInverseMatr(int n, double** a, double* b, double* x) {

		double** _A, **f,**AX;
		_A = new double* [n];
		
		f = createUnitMatrix(n);
		for (int k = 0; k < n; k++)
			_A[k] = new double[n];

		for (int i = 0; i < n; i++) {
			
			orthogonalization(initMatrix(n, a, takeColumn(n,i,f,b)),n+1,x);

			insertColumn(n, i, _A, x);
		}

		printMatr(_A, n, 5);
		AX = matrix_multi(a, _A, n);
		printMatr(AX,n,5);

		matrixOfResidual(n, AX);

		clear(AX, n);
		clear(_A, n);
		clear(f, n);
	}
	
	double* orthogonalization(double** matrix, int n,double *x) {
		
		double** z, ** u;
		z = new double* [n]; u = new double* [n];
		
		
		for (int i = 0; i < n; i++) {
			z[i] = new double[n]; 
			u[i] = new double[n];

			for (int j = 0; j < n; j++) {
				z[i][j] = 0; u[i][j] = 0; 
			}
		}

		for (int i = 0; i < n; i++) {
			findArrU(n, i, u, matrix,z);
			findArrZ(n, i, u, z);
		}

		printMatr(u, n , 7);
		printMatr(z, n, 7);

		findArreyX(z, x, n);				//Вектор решения

		clear(u, n);
		clear(z, n);
		
		return x;
	}
	double** createUnitMatrix(int n) {
		double** E;
		E = new double* [n];
		for (int i = 0; i < n; i++) {
			E[i] = new double[n];
			for (int j = 0; j < n; j++) {
				if (i == j)
					E[i][j] = 1;
				else
					E[i][j] = 0;
			}
		}
		return E;
	}
	
	double** insertColumn(int n, int pos, double** _A, double* x) {
		for (int i = 0; i < n; i++) {
			_A[i][pos] = x[i];
		}
		return _A;
	}
	double* takeColumn(int n, int pos, double** E, double* b) {

		for (int i = 0; i < n; i++) {
			b[i] = E[i][pos];
		}
		return b;
	}
	
	double* findArreyX(double** z,double *x, int n) {

		for (int i = 0; i < n; i++) {
			if (i == n - 1)
				x[i] = 1;
			else
				x[i] = z[n-1][i] / z[n-1][n-1];
		}
		printArray(x, n, 5);
		return x;
	}
	double** findArrU(int n, int pos, double** u, double **A, double **z) {
		double tmp,vector;
		
		if (pos == 0) {
			
			for (int i = 0; i < n; i++) 
				u[pos][i] = A[pos][i];							//u[0][j] = a1[0][j]

		}
		else {
			for (int k = 0; k < n; k++)
				u[pos][k] = A[pos][k];

			for (int j = 0; j < pos; j++) {
				vector = findVector(n, pos, j, A, z);			//

				for (int i = 0; i < n; i++) {
					tmp =  vector * z[j][i];
					u[pos][i] -= tmp;
				}
			}
		}
		return u;
	}
	double findArrZ(int n, int pos ,double** u, double** z) {
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
	void printNumber(double num, int CalcDigCount) {
		ofstream fout;
		fout.open("output.txt", ios::app);

		cout << endl;
		fout << endl;

			cout << "eps= " << scientific << num ;
			fout << "eps= " << scientific << num;

		cout << endl;
		fout.close();
	}

	double* vectorOfResidual(int n, double** A, double* b, double *x) {
		double* e, tmp,result;
		e = new double[n];

		for (int i = 0; i < n; i++) {
			result = 0;
			for (int j = 0; j < n; j++) {
				tmp = A[i][j] * x[j]; 
				result += tmp;
			}
			e[i] = result;
			e[i] -= b[i];
		}
		printArray(e, n, 5);

		printNumber(normOfResidual(e, n ), 5);	//Норма вектора невязки

		return e;
	}
	double normOfResidual(double* a,int n) {
		double result = 0,tmp;

		for (int i = 0; i < n; i++) {
			tmp = a[i];
			result += sqr(tmp);
		}

		return sqrt(result);

	}
	double normOfMatrix(double** a, int n) {
		double result = 0, tmp;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp = a[i][j];
				result += sqr(tmp);
			}
		}
		return sqrt(result);
	}
	double sqr(double x) {
		return x* x;
	}

	void clear(double** a, int n) {
		for (int i = 0; i < n; i++)
			delete[] a[i];
		delete[] a;
	}
	void clear(double* a) {
		delete[]a;
	}

	double** initMatrix(int n,double** a, double* b) {
		double** A;
		A = new double* [n + 1];
		for (int i = 0, sizei = n + 1; i < sizei; i++) {
			A[i] = new double[n + 1]; 

			for (int j = 0, sizej = n + 1; j < sizej; j++) {

				if (j == n) {
					if (i == n)
						A[i][j] = 1;
					else
						A[i][j] = -b[i];
				}
				else {
					if (i == n)
						if (j == n)
							A[i][j] = 1;
						else
							A[i][j] = 0;
					else
						A[i][j] = a[i][j];
				}

				
			}
		}

		printMatr(A, n + 1, 5);

		return A;
	}
	double** matrix_multi(double** A, double** B, int n)
	{
		double** result = new double* [n];
		//заполнение нулями
		for (int row = 0; row < n; row++) {
			result[row] = new double[n];
			for (int col = 0; col < n; col++) {
				result[row][col] = 0;
			}
		}

		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				for (int j = 0; j < n; j++) {
					result[row][col] += A[row][j] * B[j][col];
				}
			}
		}
		return result;
	}
	double** matrixOfResidual(int n, double** AX) {
		
		double** f;
		f = createUnitMatrix(n);

		double** result = new double* [n];
		//заполнение нулями
		for (int row = 0; row < n; row++) {
			result[row] = new double[n];
			for (int col = 0; col < n; col++) {
				result[row][col] = 0;
			}
		}
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				result[row][col] = AX[row][col] - f[row][col];
			}
		}
		clear(f, n);

		printNumber(normOfMatrix(result,n), 5);

		return result;
	}
}