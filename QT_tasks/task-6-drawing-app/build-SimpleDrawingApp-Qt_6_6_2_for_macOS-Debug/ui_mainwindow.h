/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <canvaswidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *lineButton;
    QPushButton *rectangleButton;
    QComboBox *shapeComboBox;
    CanvasWidget *widget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QWidget *widget_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(19, 9, 321, 291));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineButton = new QPushButton(gridLayoutWidget);
        lineButton->setObjectName("lineButton");

        gridLayout->addWidget(lineButton, 0, 0, 1, 1);

        rectangleButton = new QPushButton(gridLayoutWidget);
        rectangleButton->setObjectName("rectangleButton");

        gridLayout->addWidget(rectangleButton, 0, 1, 1, 1);

        shapeComboBox = new QComboBox(gridLayoutWidget);
        shapeComboBox->addItem(QString());
        shapeComboBox->addItem(QString());
        shapeComboBox->setObjectName("shapeComboBox");

        gridLayout->addWidget(shapeComboBox, 0, 2, 1, 1);

        widget = new CanvasWidget(gridLayoutWidget);
        widget->setObjectName("widget");

        gridLayout->addWidget(widget, 1, 0, 1, 3);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(440, 40, 329, 261));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(gridLayoutWidget_2);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout_2->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget_2);
        pushButton->setObjectName("pushButton");

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget_2);
        comboBox->setObjectName("comboBox");

        gridLayout_2->addWidget(comboBox, 0, 2, 1, 1);

        widget_2 = new QWidget(gridLayoutWidget_2);
        widget_2->setObjectName("widget_2");

        gridLayout_2->addWidget(widget_2, 1, 0, 1, 3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 36));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineButton->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        rectangleButton->setText(QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        shapeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Line", nullptr));
        shapeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Rectangle", nullptr));

        pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
