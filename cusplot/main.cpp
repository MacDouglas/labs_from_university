#include "cusplot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cusplot w;
    w.show();

    return a.exec();
}
