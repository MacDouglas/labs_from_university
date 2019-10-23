// Преобр-е Хафа.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "pch.h"
#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void houghLine(IplImage* original, float accuracy = 0.1)
{
	assert(original != 0);

	IplImage * src = 0, *rgb = 0;
	IplImage * bin = 0;
	IplImage * phase = 0;

	src = cvCloneImage(original);

	// заведём цветную картинку
	rgb = cvCreateImage(cvGetSize(src), 8, 3);
	cvConvertImage(src, rgb, CV_GRAY2BGR);

	// бинарная картинка - для контуров
	bin = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
	cvCanny(src, bin, 50, 200);

	cvNamedWindow("bin", 1);
	cvShowImage("bin", bin);

	// максимальное расстояние от начала координат - это длина диагонали
	int RMax = cvRound(sqrt((double)(src->width * src->width + src->height * src->height)));

	// картинка для хранения фазового пространства Хафа (r, f)
	// 0 < r < RMax
	// 0 < f < 2*PI
	phase = cvCreateImage(cvSize(RMax, 180), IPL_DEPTH_16U, 1);
	cvZero(phase);

	int x = 0, y = 0, r = 0, f = 0;
	float theta = 0;

	// пробегаемся по пикселям изображения контуров
	for (y = 0; y < bin->height; y++) {
		uchar* ptr = (uchar*)(bin->imageData + y * bin->widthStep);
		for (x = 0; x < bin->width; x++) {
			if (ptr[x] > 0) { // это пиксель контура?
					// рассмотрим все возможные прямые, которые могут 
					// проходить через эту точку
				for (f = 0; f < 180; f++) { //перебираем все возможные углы наклона
					short* ptrP = (short*)(phase->imageData + f * phase->widthStep);
					for (r = 0; r < RMax; r++) { // перебираем все возможные расстояния от начала координат
						theta = f * CV_PI / 180.0; // переводим градусы в радианы

						// Если решение уравнения достаточно хорошее (точность больше заданой)
						if (abs(((y)* sin(theta) + (x)* cos(theta)) - r) < accuracy) {
							ptrP[r]++; // увеличиваем счетчик для этой точки фазового пространства.
						}
					}
				}
			}
		}
	}

	cvNamedWindow("phase", 1);
	cvShowImage("phase", phase);

	// увеличим фазовую картинку
	IplImage* phaseImage = cvCreateImage(cvSize(phase->width * 3, phase->height * 3), IPL_DEPTH_16U, 1);
	cvResize(phase, phaseImage);

	cvNamedWindow("phaseImage", 1);
	cvShowImage("phaseImage", phaseImage);

	// Выбираем точку фазового пространства которая набрала наибольшее число попаданий
	unsigned int MaxPhaseValue = 0;
	float Theta = 0;
	int R = 0;
	for (f = 0; f < 180; f++) { //перебираем все возможные углы наклона
		short* ptrP = (short*)(phase->imageData + f * phase->widthStep);
		for (r = 0; r < RMax; r++) { // перебираем все возможные расстояния от начала координат
			if (ptrP[r] > MaxPhaseValue) {
				MaxPhaseValue = ptrP[r];
				Theta = f;
				R = r;
			}
		}
	}

#if 1
	printf("[M] %d\n", MaxPhaseValue);

	// нормировка
	float scaler = 0xFFFFFFFF / (float)MaxPhaseValue;
	for (y = 0; y < phaseImage->height; y++) {
		short* ptr = (short*)(phaseImage->imageData + y * phaseImage->widthStep);
		for (x = 0; x < phaseImage->width; x++) {
			ptr[x] *= scaler;
		}
	}
	cvNamedWindow("phaseImage2", 1);
	cvShowImage("phaseImage2", phaseImage);
#endif

	// Рисуем линию по точкам для  R, Teta которые получили в результате преобразования
	Theta = Theta * CV_PI / 180.0;
	for (y = 0; y < rgb->height; y++) {
		uchar* ptr = (uchar*)(rgb->imageData + y * rgb->widthStep);
		for (x = 0; x < rgb->width; x++) {
			if (cvRound(((y)* sin(Theta) + (x)* cos(Theta))) == R) {
				ptr[3 * x] = 0;
				ptr[3 * x + 1] = 0;
				ptr[3 * x + 2] = 255;
			}
		}
	}

	cvNamedWindow("line", 1);
	cvShowImage("line", rgb);

	// освобождаем ресурсы
	cvReleaseImage(&src);
	cvReleaseImage(&rgb);

	cvReleaseImage(&bin);
	cvReleaseImage(&phase);
	cvReleaseImage(&phaseImage);
}

int main(int argc, char* argv[])
{
	IplImage* original = 0;

	original = cvLoadImage("winnie.jpg", 0);

	assert(original != 0);

	// покажем изображения
	cvNamedWindow("original", 1);
	cvShowImage("original", original);

	houghLine(original);

	cvWaitKey(0);

	cvReleaseImage(&original);

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
