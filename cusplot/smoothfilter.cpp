#include "cusplot.h"
#include "ui_cusplot.h"
#include "QDebug"

void cusplot::smoothFilter(int n,int window)
{
    if(coordinateY.isEmpty() == true)
        throw ("Input vector is empty. Please init data");

    else                                            //Если выходной массив пустой, создать новый
        if(outputSmooth.isEmpty() == true)
            createSmoothMass(n,window);

        else
            resizeSmoothMass(n,window);             //Иначе вычислить элемнты заново


    //wGraphic->addGraph(wGraphic->xAxis, wGraphic->yAxis);
    //wGraphic->graph(0)->setData(coordinateX,outputSmooth);
    //wGraphic->replot();
}

void cusplot::createSmoothMass(int n,int window){
    int i,j,z,k1,k2,hw;
    double tmp;

    if(fmod(window,2) == 0.0)
        window++;
    hw=(window-1)/2;

    outputSmooth.push_back(coordinateY[0]);
    for (i=0;i<n;i++)
    {
        tmp=0;
        if(i<hw)
        {
            k1=0;
            k2=2*i;
            z=k2+1;
        }
        else if((i+hw)>(n-1))
        {
            k1=i-n+i+1;
            k2=n-1;
            z=k2-k1+1;
        }
        else
        {
            k1=i-hw;
            k2=i+hw;
            z=window;
        }

        for (j=k1;j<=k2;j++)
        {
            tmp+=coordinateY[j];
        }
        //tmp/=z;
        //output[i].insert(i,tmp);

        outputSmooth.push_back(tmp/z);
    }
}

void cusplot::resizeSmoothMass(int n,int window){
    int i,j,z,k1,k2,hw;
    double tmp;

    if(fmod(window,2) == 0.0)
        window++;

    hw=(window-1)/2;

    outputSmooth[0] = coordinateY[0];
    for (i=0 ; i<n ; i++)
    {
        tmp=0;
        if(i<hw)
        {
            k1=0;
            k2=2*i;
            z=k2+1;
        }
        else if((i+hw)>(n-1))
        {
            k1=i-n+i+1;
            k2=n-1;
            z=k2-k1+1;
        }
        else
        {
            k1=i-hw;
            k2=i+hw;
            z=window;
        }
        for (j=k1;j<=k2;j++)
            tmp += coordinateY[j];

        outputSmooth[i] = tmp/z;
    }
}
void cusplot::findAllMax()
{
    double max = 0, pos = 0;
    for (int i = 0, j = 0; i < outputSmooth.size() - 2; i++)
    {

        if ((outputSmooth[i + 1] > outputSmooth[i]) && (outputSmooth[i + 2] > outputSmooth[i + 1]) && (outputSmooth[i + 2] > outputSmooth[i])) {
            max = outputSmooth[i + 2];
            pos = i + 2;

        }
        else if (max != 0) {
            qDebug() << "Max = " <<max << "PosMax = " << pos;
            pointsMax.push_back(max);
            posMax.push_back(pos);

            j++;
            max = 0;
        }
    }
}
void cusplot::findAllMin() {

    double min = 0, pos = 0;
    for (int i = 0, j = 0; i < outputSmooth.size() - 2; i++)
    {

        if ((outputSmooth[i + 1] < outputSmooth[i]) && (outputSmooth[i + 2] < outputSmooth[i + 1]) && (outputSmooth[i + 2] < outputSmooth[i])) {
            min = outputSmooth[i + 2];
            pos = i + 2;

        }
        else if (min != 0) {
            qDebug() << "Min = " <<min << "PosMin = " << pos;
            pointsMin.push_back(min);
            posMin.push_back(pos);

            j++;
            min = 0;
        }
    }
}
void cusplot::FindMergeMaxAndMin()
{
    if(pointsMax.isEmpty() == true && pointsMin.isEmpty() == true){
        QMessageBox::warning(this,"Внимание! ","Необходимо вычислить mergeMaxMin !");
    }
    else
    {
        for (int i = 0, size = posMax.size(); i < size; i++) {
            //if(posMax[0] > posMin[0])

        }

    }

}
