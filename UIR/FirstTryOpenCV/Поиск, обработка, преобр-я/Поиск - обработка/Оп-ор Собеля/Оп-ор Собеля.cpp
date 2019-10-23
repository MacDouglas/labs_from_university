//Оператор Собеля — это дискретный дифференциальный оператор, вычисляющий приближение градиента яркости изображения.
//Оператор вычисляет градиент яркости изображения в каждой точке.
//Так находится направление наибольшего увеличения яркости и величина её изменения в этом направлении.
//Результат показывает, насколько «резко» или «плавно» меняется яркость изображения в каждой точке, а значит, вероятность нахождения точки на грани,
//а также ориентацию границы.

#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdlib.h>
#include <stdio.h>

IplImage* image = 0;
IplImage* dst = 0;
IplImage* dst2 = 0;

int xorder = 1;
int xorder_max = 2;

int yorder = 1;
int yorder_max = 2;

//
// функция-обработчик ползунка - 
// порядок производной по X
void myTrackbarXorder(int pos) {
	xorder = pos;
}

//
// функция-обработчик ползунка - 
// порядок производной по Y
void myTrackbarYorder(int pos) {
	yorder = pos;
}

int main(int argc, char* argv[])
{
	image = cvLoadImage("winny.jpg", 1);
	// создаём картинки
	dst = cvCreateImage(cvSize(image->width, image->height), IPL_DEPTH_16S, image->nChannels);
	dst2 = cvCreateImage(cvSize(image->width, image->height), image->depth, image->nChannels);

	assert(image != 0);

	// окно для отображения картинки
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("sobel", CV_WINDOW_AUTOSIZE);


	int aperture = argc == 3 ? atoi(argv[2]) : 3;

	cvCreateTrackbar("xorder", "original", &xorder, xorder_max, myTrackbarXorder);
	cvCreateTrackbar("yorder", "original", &yorder, yorder_max, myTrackbarYorder);

	while (1) {

		// проверяем, чтобы порядок производных по X и Y был отличен от 0
		if (xorder == 0 && yorder == 0) {
			printf("[i] Error: bad params for cvSobel() !\n");
			cvZero(dst2);
		}
		else {
			// применяем оператор Собеля
			cvSobel(image, dst, xorder, yorder, aperture);
			// преобразуем изображение к 8-битному
			cvConvertScale(dst, dst2);
		}

		// показываем картинку
		cvShowImage("original", image);
		cvShowImage("sobel", dst2);

		char c = cvWaitKey(33);
		if (c == 27) { // если нажата ESC - выходим
			break;
		}
	}

	// освобождаем ресурсы
	cvReleaseImage(&image);
	cvReleaseImage(&dst);
	cvReleaseImage(&dst2);
	// удаляем окна
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
