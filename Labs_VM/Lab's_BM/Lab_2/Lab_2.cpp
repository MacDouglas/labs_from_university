#include "methods.h"
#include "Matrix.h"

using namespace std;
using namespace maths_methods;
using namespace math_subjects;

int main()
{
	double** a,*b, *x;
	int m,n, epsSize = 3;
	double eps = 0.001, tmp;

	ifstream fin("input.txt");
	if (!fin.is_open()) {
		throw "File don't open!";
	}
	else {

		fin >> m;
		fin >> n;
		a = new double*[n];
		b = new double[n];
		x = new double[n];

		for (int i = 0; i < n; i++) {
			
			a[i] = new double[n];
			
			for (int j = 0; j < n + 1; j++) {
				
				fin >> tmp;
				
				if (j == n) {
					b[i] = tmp;
				}
				else {
					a[i][j] = tmp;
				}
			}
		}

		fin.close();
	}

	initOrthogonalization(n, initMatrix(n,a,b), a, b);

	//ofstream fout("output.txt");
	//fout.precision(-log10(eps));
	//fout << fixed << "x= " << x << "\n";
	//fout << fixed << "f(x)= " << fx << "\n";
	//fout << "eps= " << scientific << e;

	
	//fout.close();

	clear(a, n);
	delete[] b; 
	delete[] x;


	return 0;
}