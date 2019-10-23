// Заливка части изображения.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
using namespace std;
using namespace cv;

void fill(IplImage*src, CvPoint seed, CvScalar color = CV_RGB(255, 0, 0)) {
	assert(src);
	CvConnectedComp comp;
	cvFloodFill(src, seed, color, cvScalarAll(10), cvScalarAll(10), &comp, CV_FLOODFILL_FIXED_RANGE + 8, 0);
	cout << "filled area: " << comp.area << endl;
}
void myMouseCallback(int event, int x, int y, int flags, void *param) {
	IplImage *img = (IplImage*)param;
	switch (event)
	{
	case CV_EVENT_MOUSEMOVE:break;
	case CV_EVENT_LBUTTONDOWN:
		fill(img, cvPoint(x, y));
		break;
	case CV_EVENT_LBUTTONUP:
		break;
	}
}
int main()
{
	IplImage *src = 0, *dst = 0;
	src = cvLoadImage("test1.jpg", 1);
	assert(src != 0);
	cvNamedWindow("origin", 1);
	cvSetMouseCallback("origin", myMouseCallback, (void*)src);
	while (1) {
		cvShowImage("origin", src);
		char c = cvWaitKey(33);
		if (c == 27) {
			break;
		}
	}
	cvReleaseImage(&src);
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
