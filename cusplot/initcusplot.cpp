#include "cusplot.h"
#include "ui_cusplot.h"

void cusplot::initCusPlot()
{
    // Инициализируем объект полотна для графика ...
    wGraphic = new QCustomPlot();
    ui->gridLayout_2->addWidget(wGraphic,1,0,1,1); // ... и устанавливаем

    // Инициализируем вертикальную линию
    verticalLine = new QCPCurve(wGraphic->xAxis, wGraphic->yAxis);

    // Подключаем сигналы событий мыши от полотна графика к слотам для их обработки
    connect(wGraphic, &QCustomPlot::mousePress, this, &cusplot::slotMousePress);
    connect(wGraphic, &QCustomPlot::mouseMove, this, &cusplot::slotMouseMove);

    // создаём вектора для вертикальной линии
     QVector<double> x1(2) , y1(2);
     x1[0] = 0;
     y1[0] = -50;
     x1[1] = 0;
     y1[1] = 50;

    verticalLine->setName("Vertical");      // Устанавливаем ей наименование
    verticalLine->setData(x1, y1);          // И устанавливаем координаты

    firstBuild(A.toDouble(),w.toDouble(),a.toDouble(),f.toDouble());                  //Вызов функции считающего синус и отоброжающего фу-ии синуса на графике

    // Инициализируем трассировщик
    tracer = new QCPItemTracer(wGraphic);
    tracer->setGraph(wGraphic->graph(0));   // Трассировщик будет работать с графиком

    // Подписываем оси координат
    wGraphic->xAxis->setLabel("x");
    wGraphic->yAxis->setLabel("y");

    // Устанавливаем максимальные и минимальные значения координат
    wGraphic->xAxis->setRange(0,120);
    wGraphic->yAxis->setRange(-15,15);

    // Отрисовываем содержимое полотна
    wGraphic->replot();
}

void cusplot::slotMousePress(QMouseEvent *event)
{
    // Определяем координату X на графике, где был произведён клик мышью
    double coordX = wGraphic->xAxis->pixelToCoord(event->pos().x());

    // Подготавливаем координаты по оси X для переноса вертикальной линии
    QVector<double> x(2), y(2);
    x[0] = coordX;
    y[0] = -50;
    x[1] = coordX;
    y[1] = 50;

    // Устанавливаем новые координаты
    verticalLine->setData(x, y);

    // По координате X клика мыши определим ближайшие координаты для трассировщика
    tracer->setGraphKey(coordX);

    // Выводим координаты точки графика, где установился трассировщик, в lineEdit
    ui->lineEdit->setText("x: " + QString::number(tracer->position->key()) +
                          " y: " + QString::number(tracer->position->value()));
    wGraphic->replot();
}

void cusplot::slotMouseMove(QMouseEvent *event)
{

    if(QApplication::mouseButtons()) slotMousePress(event);
}
