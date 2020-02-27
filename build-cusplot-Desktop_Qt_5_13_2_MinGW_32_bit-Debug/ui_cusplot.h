/********************************************************************************
** Form generated from reading UI file 'cusplot.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSPLOT_H
#define UI_CUSPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cusplot
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_a;
    QLabel *label_6;
    QLineEdit *lineEdit_f;
    QLabel *label_w;
    QLineEdit *lineEdit_A;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QPushButton *findAllMax;
    QPushButton *smoothButton;
    QPushButton *startButton;
    QPushButton *findAllMin;
    QLabel *label_f;
    QSpacerItem *horizontalSpacer;
    QLabel *label_A;
    QLineEdit *lineEdit_6;
    QLabel *label_5;
    QLineEdit *lineEdit_w;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *cusplot)
    {
        if (cusplot->objectName().isEmpty())
            cusplot->setObjectName(QString::fromUtf8("cusplot"));
        cusplot->resize(811, 474);
        centralWidget = new QWidget(cusplot);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 441, 261));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 290, 441, 31));
        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(465, 10, 331, 261));
        gridLayout = new QGridLayout(gridLayoutWidget_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_a = new QLineEdit(gridLayoutWidget_2);
        lineEdit_a->setObjectName(QString::fromUtf8("lineEdit_a"));

        gridLayout->addWidget(lineEdit_a, 0, 4, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 3, 1, 1);

        lineEdit_f = new QLineEdit(gridLayoutWidget_2);
        lineEdit_f->setObjectName(QString::fromUtf8("lineEdit_f"));

        gridLayout->addWidget(lineEdit_f, 2, 2, 1, 1);

        label_w = new QLabel(gridLayoutWidget_2);
        label_w->setObjectName(QString::fromUtf8("label_w"));

        gridLayout->addWidget(label_w, 1, 1, 1, 1);

        lineEdit_A = new QLineEdit(gridLayoutWidget_2);
        lineEdit_A->setObjectName(QString::fromUtf8("lineEdit_A"));

        gridLayout->addWidget(lineEdit_A, 0, 2, 1, 1);

        groupBox = new QGroupBox(gridLayoutWidget_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayoutWidget_3 = new QWidget(groupBox);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(0, 10, 301, 161));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        findAllMax = new QPushButton(gridLayoutWidget_3);
        findAllMax->setObjectName(QString::fromUtf8("findAllMax"));

        gridLayout_3->addWidget(findAllMax, 0, 1, 1, 1);

        smoothButton = new QPushButton(gridLayoutWidget_3);
        smoothButton->setObjectName(QString::fromUtf8("smoothButton"));

        gridLayout_3->addWidget(smoothButton, 1, 0, 1, 1);

        startButton = new QPushButton(gridLayoutWidget_3);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        gridLayout_3->addWidget(startButton, 0, 0, 1, 1);

        findAllMin = new QPushButton(gridLayoutWidget_3);
        findAllMin->setObjectName(QString::fromUtf8("findAllMin"));

        gridLayout_3->addWidget(findAllMin, 1, 1, 1, 1);


        gridLayout->addWidget(groupBox, 3, 1, 1, 4);

        label_f = new QLabel(gridLayoutWidget_2);
        label_f->setObjectName(QString::fromUtf8("label_f"));

        gridLayout->addWidget(label_f, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        label_A = new QLabel(gridLayoutWidget_2);
        label_A->setObjectName(QString::fromUtf8("label_A"));

        gridLayout->addWidget(label_A, 0, 1, 1, 1);

        lineEdit_6 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 1, 4, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 3, 1, 1);

        lineEdit_w = new QLineEdit(gridLayoutWidget_2);
        lineEdit_w->setObjectName(QString::fromUtf8("lineEdit_w"));

        gridLayout->addWidget(lineEdit_w, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 5, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(490, 290, 80, 21));
        cusplot->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(cusplot);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 811, 20));
        cusplot->setMenuBar(menuBar);
        mainToolBar = new QToolBar(cusplot);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        cusplot->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(cusplot);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        cusplot->setStatusBar(statusBar);

        retranslateUi(cusplot);

        QMetaObject::connectSlotsByName(cusplot);
    } // setupUi

    void retranslateUi(QMainWindow *cusplot)
    {
        cusplot->setWindowTitle(QCoreApplication::translate("cusplot", "cusplot", nullptr));
        lineEdit_a->setText(QCoreApplication::translate("cusplot", "0.01", nullptr));
        label_6->setText(QString());
        lineEdit_f->setText(QCoreApplication::translate("cusplot", "0", nullptr));
        label_w->setText(QCoreApplication::translate("cusplot", "\320\236\320\274\320\265\320\263\320\260", nullptr));
        lineEdit_A->setText(QCoreApplication::translate("cusplot", "10", nullptr));
        groupBox->setTitle(QString());
        findAllMax->setText(QCoreApplication::translate("cusplot", "Find all points max", nullptr));
        smoothButton->setText(QCoreApplication::translate("cusplot", "\320\241\320\272\320\276\320\273\321\214\320\267\321\217\321\211\320\265\320\265", nullptr));
        startButton->setText(QCoreApplication::translate("cusplot", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 sin", nullptr));
        findAllMin->setText(QCoreApplication::translate("cusplot", "Find all points min", nullptr));
        label_f->setText(QCoreApplication::translate("cusplot", "\320\244\320\260\320\267\320\260", nullptr));
        label_A->setText(QCoreApplication::translate("cusplot", "\320\220\320\274\320\277\320\273\320\270\321\202\321\203\320\264\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("cusplot", "\320\232\320\276\321\215\321\204 \320\260", nullptr));
        lineEdit_w->setText(QCoreApplication::translate("cusplot", "0.2", nullptr));
        pushButton->setText(QCoreApplication::translate("cusplot", "mergeMaxMin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cusplot: public Ui_cusplot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSPLOT_H
