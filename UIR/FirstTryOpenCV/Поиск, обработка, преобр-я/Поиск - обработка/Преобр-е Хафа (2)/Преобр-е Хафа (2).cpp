// Преобр-е Хафа (2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "pch.h"
#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <math.h>

int main(int argc, char* argv[])
{
	IplImage* src = 0;
	IplImage* dst = 0;
	IplImage* color_dst = 0;


	src = cvLoadImage("winnie.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	// хранилище памяти для хранения найденных линий
	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* lines = 0;
	int i = 0;


	dst = cvCreateImage(cvGetSize(src), 8, 1);  //нахождение границ Кенни
	color_dst = cvCreateImage(cvGetSize(src), 8, 3);  //Нахождение преобр-я Хафа

	// детектирование границ
	cvCanny(src, dst, 50, 200, 3);

	// конвертируем в цветное изображение
	cvCvtColor(dst, color_dst, CV_GRAY2BGR);

	// нахождение линий
	lines = cvHoughLines2(dst, storage, CV_HOUGH_PROBABILISTIC, 1, CV_PI / 180, 50, 50, 10);

	// нарисуем найденные линии
	for (i = 0; i < lines->total; i++) {
		CvPoint* line = (CvPoint*)cvGetSeqElem(lines, i);
		cvLine(color_dst, line[0], line[1], CV_RGB(255, 0, 0), 3, CV_AA, 0);
	}

	// показываем
	cvNamedWindow("Source", 1);
	cvShowImage("Source", src);

	cvNamedWindow("Hough", 1);
	cvShowImage("Hough", color_dst);

	// ждём нажатия клавиши
	cvWaitKey(0);

	// освобождаем ресурсы
	cvReleaseMemStorage(&storage);
	cvReleaseImage(&src);
	cvReleaseImage(&dst);
	cvReleaseImage(&color_dst);
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
