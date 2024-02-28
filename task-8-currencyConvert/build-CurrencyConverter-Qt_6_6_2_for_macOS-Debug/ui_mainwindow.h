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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonConvert;
    QLineEdit *lineEditAmount;
    QComboBox *toCurrencyComboBox;
    QComboBox *fromCurrencyComboBox;
    QLabel *labelResult;
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
        gridLayoutWidget->setGeometry(QRect(10, 10, 301, 161));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonConvert = new QPushButton(gridLayoutWidget);
        pushButtonConvert->setObjectName("pushButtonConvert");

        gridLayout->addWidget(pushButtonConvert, 4, 1, 1, 1);

        lineEditAmount = new QLineEdit(gridLayoutWidget);
        lineEditAmount->setObjectName("lineEditAmount");

        gridLayout->addWidget(lineEditAmount, 4, 0, 1, 1);

        toCurrencyComboBox = new QComboBox(gridLayoutWidget);
        toCurrencyComboBox->setObjectName("toCurrencyComboBox");

        gridLayout->addWidget(toCurrencyComboBox, 2, 0, 1, 2);

        fromCurrencyComboBox = new QComboBox(gridLayoutWidget);
        fromCurrencyComboBox->setObjectName("fromCurrencyComboBox");

        gridLayout->addWidget(fromCurrencyComboBox, 1, 0, 1, 2);

        labelResult = new QLabel(gridLayoutWidget);
        labelResult->setObjectName("labelResult");

        gridLayout->addWidget(labelResult, 7, 0, 1, 3);

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
        pushButtonConvert->setText(QCoreApplication::translate("MainWindow", "Convert", nullptr));
        lineEditAmount->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelResult->setText(QCoreApplication::translate("MainWindow", "Result", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
