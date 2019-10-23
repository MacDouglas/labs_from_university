// Сглаживание изображения.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
using namespace std;
using namespace cv;

IplImage *img=0;
IplImage *dst=0;

int main()
{
	img = cvLoadImage("test.jpg", 1);
	dst = cvCloneImage(img);
	assert(dst != 0);
	cvNamedWindow("oreginal", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("smooth", CV_WINDOW_AUTOSIZE);
	
	cvSmooth(img, dst, CV_GAUSSIAN, 3, 3);
	
	cvShowImage("original", img);
	cvShowImage("smooth", dst);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvReleaseImage(&dst);
	cvDestroyWindow("original");
	cvDestroyWindow("smooth");
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
