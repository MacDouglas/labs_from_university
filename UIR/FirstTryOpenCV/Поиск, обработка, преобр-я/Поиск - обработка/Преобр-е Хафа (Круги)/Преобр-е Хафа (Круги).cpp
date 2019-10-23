// Преобр-е Хафа (Круги).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "pch.h"
#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
//#include <math.h>

int main(int argc, char* argv[])
{
	IplImage* image = 0;

	image = cvLoadImage("winnie.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	assert(image != 0);

	// загрузим оригинальное изображении
	IplImage * src = cvLoadImage("winnie.jpg");

	// хранилище памяти для кругов
	CvMemStorage * storage = cvCreateMemStorage(0);
	// сглаживаем изображение		
	cvSmooth(image, image, CV_GAUSSIAN, 5, 5);
	// поиск кругов
	CvSeq * results = cvHoughCircles(
		image,
		storage,
		CV_HOUGH_GRADIENT,
		2,
		image->width / 5
	);
	// пробегаемся по кругам и рисуем их на оригинальном изображении
	for (int i = 0; i < results->total; i++) {
		float* p = (float*)cvGetSeqElem(results, i);
		CvPoint pt = cvPoint(cvRound(p[0]), cvRound(p[1]));
		cvCircle(src, pt, cvRound(p[2]), CV_RGB(0xff, 0, 0));
	}
	// показываем
	cvNamedWindow("cvHoughCircles", 1);
	cvShowImage("cvHoughCircles", src);

	// ждём нажатия клавиши
	cvWaitKey(0);

	// освобождаем ресурсы
	cvReleaseMemStorage(&storage);
	cvReleaseImage(&image);
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
