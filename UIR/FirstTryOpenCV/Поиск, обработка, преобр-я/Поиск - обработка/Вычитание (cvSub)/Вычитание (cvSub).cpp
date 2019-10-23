// Вычитание (cvSub).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "pch.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdlib.h>
#include <stdio.h>

/* dst(mask) = src(mask) - value = src(mask) + (-value)
CV_INLINE  void  cvSubS(const CvArr* src, CvScalar value, CvArr* dst,
	const CvArr* mask CV_DEFAULT(NULL))
{
	cvAddS(src, cvScalar(-value.val[0], -value.val[1], -value.val[2], -value.val[3]),
		dst, mask);
}*/
/* dst(mask) = value - src(mask)
CVAPI(void)  cvSubRS(const CvArr* src, CvScalar value, CvArr* dst,
	const CvArr* mask CV_DEFAULT(NULL));
	*/
int main(int argc, char* argv[])
{
	IplImage* src = 0, * dst = 0, * dst2 = 0;

	// получаем картинку в градациях серого
	src = cvLoadImage("winnie.jpg", 0);

	assert(src != 0);

	// покажем изображение
	cvNamedWindow("original", 1);
	cvShowImage("original", src);

	// получим бинарное изображение
	dst2 = cvCreateImage(cvSize(src->width, src->height), IPL_DEPTH_8U, 1);
	cvCanny(src, dst2, 50, 200);

	cvNamedWindow("bin", 1);
	cvShowImage("bin", dst2);

	//cvScale(src, dst);
	cvSub(src, dst2, dst2);
	cvNamedWindow("sub", 1);
	cvShowImage("sub", dst2);


	// ждём нажатия клавиши
	cvWaitKey(0);

	// освобождаем ресурсы
	cvReleaseImage(&src);
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
