// Выделение области интерфейса 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
using namespace std;
using namespace cv;

IplImage *img = 0;
IplImage *src;

int main()
{
	img = cvLoadImage("stop.jpg", 1);
	assert(img != 0);
	cvNamedWindow("origin", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("ROI", CV_WINDOW_AUTOSIZE);

	int x = 120, y = 50;
	
	src = cvLoadImage("img2.jpg", 1);
	assert(img != 0);

	int width = src->width;
	int height = src->height;
	cvShowImage("origin", img);
	cvSetImageROI(img, cvRect(x, y, width, height));
	cvZero(img);
	cvCopy(src, img);
	cvResetImageROI(img); //
	cvShowImage("ROI", img);

	cvWaitKey(0);
	cvReleaseImage(&img);
	cvReleaseImage(&src);
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
