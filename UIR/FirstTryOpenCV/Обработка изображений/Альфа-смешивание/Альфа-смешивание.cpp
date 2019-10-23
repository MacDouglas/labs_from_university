// Альфа-смешивание.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
using namespace std;
using namespace cv;

IplImage *img;
IplImage *templ;
IplImage *dst;

int main()
{
	img = cvLoadImage("test2.jpg", 1);
	assert(img != 0);
	templ = cvLoadImage("test1.jpg", 1);
	assert(templ != 0);
	cvNamedWindow("origin", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("template", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("res", CV_WINDOW_AUTOSIZE);

	dst = cvCloneImage(templ);
	int width = templ->width, height = templ->height;
	cvShowImage("origin", img);
	cvShowImage("template", templ);
	int x = 0, y = 0;
	double alpha = 0.5, beta = 0.5;
	cvSetImageROI(img, cvRect(x, y, width, height));
	cvAddWeighted(img, alpha, templ, beta, 0.0, dst);
	cvResetImageROI(img);
	cvShowImage("res", dst);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvReleaseImage(&templ);
	cvReleaseImage(&dst);
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
