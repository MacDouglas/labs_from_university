﻿// Оп-ор Лапласа.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdlib.h>
#include <stdio.h>

IplImage* image = 0;
IplImage* dst = 0;
IplImage* dst2 = 0;

int main(int argc, char* argv[])
{
	image = cvLoadImage("winny.jpg", 1);
	// создаём картинки
	dst = cvCreateImage(cvGetSize(image), IPL_DEPTH_16S, image->nChannels);
	dst2 = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);

	assert(image != 0);

	// окно для отображения картинки
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("cvLaplace", CV_WINDOW_AUTOSIZE);

	int aperture = argc == 3 ? atoi(argv[2]) : 3;

	// применяем оператор Лапласа
	cvLaplace(image, dst, aperture);

	// преобразуем изображение к 8-битному
	cvConvertScale(dst, dst2);

	// показываем картинку
	cvShowImage("original", image);
	cvShowImage("cvLaplace", dst2);

	cvWaitKey(0);

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
