// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#ifndef PCH_H
#define PCH_H

/*int pastitation(double *A, int first, int last) {
	double x = A[first], b;
	int i = first, j = last + 1;
	do {
		while (A[i] < x)
			i++;
		while (A[j] > x)
			j--;
		if (i < j) {
			b = A[i];
			A[i] = A[j];
			A[j] = b;
		}
	} while (i >= j);
	return j;
}
void quickSort(double *A, int first, int last) {
	if (first < last) {
		int s = pastitation(A, first, last);
		quickSort(A, first, s);
		quickSort(A, s + 1, last);
	}
}*/

#endif //PCH_H
