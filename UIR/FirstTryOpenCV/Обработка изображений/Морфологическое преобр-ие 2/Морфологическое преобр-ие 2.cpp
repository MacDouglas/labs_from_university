// Морфологическое преобр-ие 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
using namespace std;
using namespace cv;

IplImage *img = 0;
IplImage *close = 0;
IplImage *open = 0;
IplImage *gradient = 0;
IplImage *tophat = 0;
IplImage *blackhat = 0;

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
	close = cvCloneImage(img);
	open = cvCloneImage(img);
	gradient = cvCloneImage(img);
	tophat = cvCloneImage(img);
	blackhat = cvCloneImage(img);
	assert(img != 0);

	cvNamedWindow("origin", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("CV_MOP_OPEN", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("CV_MOP_CLOSE", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("CV_MOP_GRADIENT", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("CV_MOP_TOPHAT", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("CV_MOP_BLACKHAT", CV_WINDOW_AUTOSIZE);

	cvCreateTrackbar("Radius", "origin", &rad, rad_max, myTrackbarRadius);
	cvCreateTrackbar("Iterations", "origin", &iterations, iterations_max, myTrackbarIterations);
	while (1) {
		cvShowImage("origin", img);
		IplConvKernel *Kern = cvCreateStructuringElementEx(rad * 2 + 1, rad * 2 + 1, rad, rad, CV_SHAPE_ELLIPSE);
		IplImage *temp=0;
		temp = cvCreateImage(cvSize(img->width, img->height), IPL_DEPTH_8U, 1);
		cvMorphologyEx(img, open, temp, Kern, CV_MOP_OPEN, iterations);
		cvMorphologyEx(img, close, temp, Kern, CV_MOP_CLOSE, iterations);
		cvMorphologyEx(img, gradient, temp, Kern, CV_MOP_GRADIENT, iterations);
		cvMorphologyEx(img, tophat, temp, Kern, CV_MOP_TOPHAT, iterations);
		cvMorphologyEx(img, blackhat, temp, Kern, CV_MOP_BLACKHAT, iterations);

		cvShowImage("CV_MOP_OPEN", open);
		cvShowImage("CV_MOP_CLOSE", close);
		cvShowImage("CV_MOP_GRADIENT", gradient);
		cvShowImage("CV_MOP_TOPHAT",tophat);
		cvShowImage("CV_MOP_BLACKHAT", blackhat);

		cvReleaseStructuringElement(&Kern);
		cvReleaseImage(&temp);

		char c = cvWaitKey(33);
		if (c == 27) {
			break;
		}
	}
	cvReleaseImage(&img);
	cvReleaseImage(&open);
	cvReleaseImage(&close);
	cvReleaseImage(&gradient);
	cvReleaseImage(&tophat);
	cvReleaseImage(&blackhat);
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
