// Морфологические преобразования.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
using namespace std;
using namespace cv;

IplImage *img = 0;
IplImage *dst = 0;
IplImage *erode = 0;
IplImage *dilate = 0;
int rad = 1;
int rad_max = 10;

void myTrackbarRadius(int pos) {
	rad = pos;
}

int iterations = 1;
int iterations_max = 10;
void myTrackbarIterations(int pos) {
	iterations = pos;
}
int main()
{
	img = cvLoadImage("test1.jpg", 1);
	dst = cvCloneImage(img);
	erode = cvCloneImage(img);
	dilate = cvCloneImage(img);
	assert(img != 0);

	cvNamedWindow("origin", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("erode", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("dilate", CV_WINDOW_AUTOSIZE);
	cvCreateTrackbar("Radius", "origin", &rad, rad_max, myTrackbarRadius);
	cvCreateTrackbar("Iterations", "origin", &iterations, iterations_max, myTrackbarIterations);
	while (1) {
		cvShowImage("origin", img);
		IplConvKernel *Kern = cvCreateStructuringElementEx(rad * 2 + 1, rad * 2 + 1, rad, rad, CV_SHAPE_ELLIPSE);
		cvErode(img, erode, Kern, iterations);
		cvDilate(img, dilate, Kern, iterations);
		cvShowImage("erode", erode);
		cvShowImage("dilate", dilate);
		cvReleaseStructuringElement(&Kern);
		char c = cvWaitKey(33);
		if (c == 27) {
			break;
		}
	}
	cvReleaseImage(&img);
	cvReleaseImage(&dst);
	cvReleaseImage(&erode);
	cvReleaseImage(&dilate);
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
