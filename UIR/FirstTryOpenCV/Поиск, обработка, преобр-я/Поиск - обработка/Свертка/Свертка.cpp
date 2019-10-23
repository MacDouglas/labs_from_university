// Свертка.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdlib.h>
#include <stdio.h>

IplImage* image = 0;
IplImage* dst = 0;

int main(int argc, char* argv[])
{

	image = cvLoadImage("test1.jpg", 1);

	assert(image != 0);

	// клонируем картинку 
	dst = cvCloneImage(image);

	// окно для отображения картинки
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("cvFilter2D", CV_WINDOW_AUTOSIZE);

	float kernel[9];
	kernel[0] = -0.1;
	kernel[1] = -0.1;
	kernel[2] = -0.1;

	kernel[3] = -0.1;
	kernel[4] = 2;
	kernel[5] = -0.1;

	kernel[6] = -0.1;
	kernel[7] = -0.1;
	kernel[8] = -0.1;

	// матрица
	CvMat kernel_matrix = cvMat(3, 3, CV_32FC1, kernel);

	// накладываем фильтр
	cvFilter2D(image, dst, &kernel_matrix, cvPoint(-1, -1));

	// показываем картинку
	cvShowImage("original", image);
	cvShowImage("cvFilter2D", dst);

	// ждём нажатия клавиши
	cvWaitKey(0);

	// освобождаем ресурсы
	cvReleaseImage(&image);
	cvReleaseImage(&dst);
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
