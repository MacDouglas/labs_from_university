#ifndef CUSPLOT_H
#define CUSPLOT_H

#include <QMainWindow>
#include <qcustomplot.h>

#include <QDebug>
#include <QApplication>
#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QMessageBox>
#include <QVector>

#include <math.h>

namespace Ui {
class cusplot;
}

class cusplot : public QMainWindow
{
    Q_OBJECT

public:
    explicit cusplot(QWidget *parent = nullptr);
    ~cusplot();

private:
    Ui::cusplot *ui;
    QCustomPlot *wGraphic;              // Объявляем объект QCustomPlot
    QCPCurve *verticalLine;             // Объявляем объект для вертикальной линии
    QCPItemTracer *tracer;              // Трасировщик по точкам графика

    double dA,dw;                       //Расчетная переменная Амплитуды и фазы

    QVector<double> coordinateX,coordinateY,x1,y1;                          //Координаты X,Y - Исходные координаты
    QVector<double> inputSmooth,outputSmooth,pointsMax,pointsMin,posMax,posMin;         //Массивы для скользящего среднего, Значений минимума/максимума, позиций минимума/максимума

    QString A,w,a,f;            //

    void initialization();
    void initCusPlot();
    void firstBuild(double A,double w,double a,double f);

    void findAllMax();
    void findAllMin();

    void smoothFilter(int n,int window);
    void createSmoothMass(int n,int window);
    void resizeSmoothMass(int n,int window);


private slots:
    void slotMousePress(QMouseEvent * event);
    void slotMouseMove(QMouseEvent * event);
    void on_startButton_clicked();
    void on_smoothButton_clicked();
    void on_findAllMax_clicked();
    void on_findAllMin_clicked();
};

#endif // CUSPLOT_H
