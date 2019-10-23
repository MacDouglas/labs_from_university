// Изменение размера изо-я.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"

using namespace std;
using namespace cv;

IplImage *img = 0;
IplImage *dst[4];

int main()
{
	img = cvLoadImage("test.jpg", 1);
	assert(img != 0);
	for (int i = 0; i < 4; i++) {
		dst[i] = cvCreateImage(cvSize(img->width / 3, img->height / 3), img->depth, img->nChannels);
		cvResize(img, dst[i], i);

	}
	cvNamedWindow("origin", CV_WINDOW_AUTOSIZE);
	cvShowImage("origin", img);
	char buf[1];
	for (int i = 0; i < 4; i++) {
		*buf = i + '0';
		cvNamedWindow(buf, CV_WINDOW_AUTOSIZE);
		cvShowImage(buf, dst[i]);
	}
	cvWaitKey(0);
	cvReleaseImage(&img);
	for (int i = 0; i < 4; i++) {
		cvReleaseImage(&dst[i]);
	}
	cvDestroyAllWindows();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
