#include <iostream>
#include <list>

using namespace std;

double findArr(double** A, double **a, int n,int pos) {
	for (int i = 0; i < n; i++) {
		a[pos][i] = A[pos][i];
	}
	return **a;
}


int main()
{
	list<double> a = { 1,2,3,4 };
	list<double> it = a.begin();
	advance(it, 2);
	double b = *it;

	

	return 0;
}