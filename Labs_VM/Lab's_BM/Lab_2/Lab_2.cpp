#include "methods.h"
#include "Matrix.h"

using namespace std;
using namespace maths_methods;
using namespace math_subjects;

int main()
{
	double** a, * y, * x;
	int m,n, epsSize = 3;
	double eps = 0.001, tmp;

	ifstream fin("input.txt");
	if (!fin.is_open()) {
		throw "File don't open!";
	}
	else {

		fin >> m;
		fin >> n;
		a = new double* [n+1];

		for (int i = 0 , sizei = n + 1; i < sizei; i++) {
			
			a[i] = new double[n + 1];
			
			for (int j = 0, sizej = n + 1; j < sizej; j++) {
				
				fin >> tmp;
				
				if(j == n)
					a[i][j] = -tmp;
				else
					a[i][j] = tmp;
				
				if (i == n)
					if (j == n)
						a[i][j] = 1;
					else
						a[i][j] = 0;
			}
		}

		fin.close();
	}
	//fout << "matrix A = ";
	printMatr(a, n + 1, 5);

	orthogonalization(a, n + 1);

	//ofstream fout("output.txt");
	//fout.precision(-log10(eps));
	//fout << fixed << "x= " << x << "\n";
	//fout << fixed << "f(x)= " << fx << "\n";
	//fout << "eps= " << scientific << e;

	
	//fout.close();

	for (int i =  0; i < n + 1; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}