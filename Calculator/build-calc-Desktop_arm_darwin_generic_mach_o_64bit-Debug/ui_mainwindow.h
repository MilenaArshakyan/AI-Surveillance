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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(373, 422);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 271, 51));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 90, 61, 71));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(100, 90, 61, 71));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(170, 90, 61, 71));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(30, 160, 61, 71));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(100, 160, 61, 71));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(170, 160, 61, 71));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(30, 300, 61, 71));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(100, 300, 131, 71));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(170, 230, 61, 71));
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(100, 230, 61, 71));
        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(30, 230, 61, 71));
        pushButton_13 = new QPushButton(centralwidget);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(240, 300, 61, 71));
        pushButton_14 = new QPushButton(centralwidget);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(240, 160, 61, 71));
        pushButton_15 = new QPushButton(centralwidget);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(240, 230, 61, 71));
        pushButton_16 = new QPushButton(centralwidget);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(240, 90, 61, 71));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
