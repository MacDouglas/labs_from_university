#include "cusplot.h"
#include "ui_cusplot.h"
#include <time.h>

void cusplot::firstBuild(double A,double w,double a,double f){

    srand(time_t(nullptr));

    double randDA,randDW;

    if(coordinateY.isEmpty()){
        for (int i=0;i<100;i++){

            randDA = static_cast<double>(rand() % (100 - (-100) + 1) + (-100)) / 100;
            randDW = static_cast<double>(rand() % (100 - (-100) + 1) + (-100)) / 100;

            dA = A*(1+a*randDA);       //Считается амплитуда с шумами
            dw = w*(1+a*randDW);

        coordinateX.push_back(i);
        coordinateY.push_back(dA*sin(coordinateX[i]*dw+f));
        }

    }else {
        for (int i=0;i<100;i++){
            randDA = static_cast<double>(rand() % (100 - (-100) + 1) + (-100)) / 100;
            randDW = static_cast<double>(rand() % (100 - (-100) + 1) + (-100)) / 100;

            dA = A*(1+a*randDA);       //Считается амплитуда с шумами
            dw = w*(1+a*randDW);

            coordinateX[i] = i;
            coordinateY[i] = dA*sin(coordinateX[i]*dw+f);
        }

    }

    // Добавляем график на полотно
    wGraphic->addGraph(wGraphic->xAxis, wGraphic->yAxis);
    wGraphic->graph(0)->setData(coordinateX,coordinateY);     // Устанавливаем координаты точек графика

}

void cusplot::initialization()
{
    A = ui->lineEdit_A->text();
    w = ui->lineEdit_w->text();
    a = ui->lineEdit_a->text();
    f = ui->lineEdit_f->text();

    if(A == nullptr && w == nullptr && a==nullptr && f == nullptr)
    {
        QMessageBox::warning(this,"Внимание, возможна ошибка","Амплитуда,омега,коэф. а не имеют значений");
    }
    else
    {
        initCusPlot();
    }

}
