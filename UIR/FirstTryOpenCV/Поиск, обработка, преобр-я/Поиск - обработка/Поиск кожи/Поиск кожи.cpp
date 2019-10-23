// Поиск кожи.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cvaux.h> // для CvAdaptiveSkinDetector

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	IplImage* image = 0, *dst = 0, *mask = 0;

	// имя картинки задаётся первым параметром
	char* filename = argc >= 2 ? argv[1] : "Image0.jpg";
	// получаем картинку
	image = cvLoadImage(filename, 1);

	printf("[i] image: %s\n", filename);
	assert(image != 0);

	// покажем изображение
	cvNamedWindow("original");
	cvShowImage("original", image);

	// картинка для хранения изображения
	dst = cvCloneImage(image);

	// детектор кожи
	CvAdaptiveSkinDetector filter(1, CvAdaptiveSkinDetector::MORPHING_METHOD_ERODE); // MORPHING_METHOD_ERODE_DILATE

	// картинка для хранения результата (маски)
	mask = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);

	// обработка
	filter.process(image, mask);

	// покажем маску
	cvNamedWindow("mask");
	cvShowImage("mask", mask);

	// пробегаемся по всем пикселям изображения
	// и увеличиваем у пикселей картинки, где установлена маска
	// зелёную компоненту до максимума
	for (int y = 0; y < dst->height; y++) {
		uchar* ptr = (uchar*)(dst->imageData + y * dst->widthStep); // изображение
		uchar* ptrM = (uchar*)(mask->imageData + y * mask->widthStep); // маска
		for (int x = 0; x < dst->width; x++) {
			if (ptrM[x]) { // маска установлена
					// 3 канала 
					//ptr[3*x] = ; // B
				ptr[3 * x + 1] = 255; // G
				//ptr[3*x+2] = ; // R
			}
		}
	}

	// покажем картинку
	cvNamedWindow("dst");
	cvShowImage("dst", dst);

	// ждём нажатия клавиши
	cvWaitKey(0);

	// освобождаем ресурсы
	cvReleaseImage(&image);
	cvReleaseImage(&dst);
	cvReleaseImage(&mask);

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
