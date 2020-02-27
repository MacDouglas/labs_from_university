#include "cusplot.h"
#include "ui_cusplot.h"


cusplot::cusplot(QWidget *parent) : QMainWindow(parent), ui(new Ui::cusplot)
{
    ui->setupUi(this);

}

cusplot::~cusplot()
{
    delete ui;
}

void cusplot::on_startButton_clicked()
{
    initialization();          //Считывание значений из полей программы и отрисовка графика.

}

void cusplot::on_smoothButton_clicked()
{
    if(coordinateX.isEmpty()== true && coordinateY.isEmpty() == true){
         QMessageBox::warning(this,"Внимание! ","Введите начальные координаты Синуса!");

    }
    else
    {
        smoothFilter(coordinateY.size()-1,2);

        wGraphic->addGraph(wGraphic->xAxis, wGraphic->yAxis);
        wGraphic->graph(0)->setData(coordinateX,outputSmooth);
        wGraphic->replot();
    }
}

void cusplot::on_findAllMax_clicked()
{
    if(outputSmooth.isEmpty() == true){
        QMessageBox::warning(this,"Внимание! ","Необходимо вычислить скользящее среднее!");
    }
    else{

        findAllMax();

        wGraphic->addGraph(wGraphic->xAxis, wGraphic->yAxis);
        wGraphic->graph(0)->setData(posMax,pointsMax);
        wGraphic->replot();
    }


}

void cusplot::on_findAllMin_clicked()
{
    if(outputSmooth.isEmpty() == true){
        QMessageBox::warning(this,"Внимание! ","Необходимо вычислить скользящее среднее!");
    }
    else{

        findAllMin();

        wGraphic->addGraph(wGraphic->xAxis, wGraphic->yAxis);
        wGraphic->graph(0)->setData(posMin,pointsMin);
        wGraphic->replot();
    }
}

void cusplot::on_pushButton_clicked()
{
    if(pointsMergeMaxMin.isEmpty() == true){
        QMessageBox::warning(this,"Внимание! ","Необходимо вычислить mergeMaxMin !");
    }
    else{

        FindMergeMaxAndMin();

        //wGraphic->addGraph(wGraphic->xAxis, wGraphic->yAxis);
        //wGraphic->graph(0)->setData(posMerge,pointsMergeMaxMin);
        //wGraphic->replot();
    }

}
