#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstNum;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui -> btn0, SIGNAL(clicked()), this, SLOT(digitsNumbers()));
    connect(ui -> btn1, SIGNAL(clicked()), this, SLOT(digitsNumbers()));
    connect(ui -> btn2, SIGNAL(clicked()), this, SLOT(digitsNumbers()));
    connect(ui -> btn3, SIGNAL(clicked()), this, SLOT(digitsNumbers()));
    connect(ui -> btn4, SIGNAL(clicked()), this, SLOT(digitsNumbers()));
    connect(ui -> btn5, SIGNAL(clicked()), this, SLOT(digitsNumbers()));
    connect(ui -> btn6, SIGNAL(clicked()), this, SLOT(digitsNumbers()));
    connect(ui -> btn7, SIGNAL(clicked()), this, SLOT(digitsNumbers()));
    connect(ui -> btn8, SIGNAL(clicked()), this, SLOT(digitsNumbers()));
    connect(ui -> btn9, SIGNAL(clicked()), this, SLOT(digitsNumbers()));
    connect(ui -> pluse, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui -> minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui -> div, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui -> mul, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui -> equal, SIGNAL(clicked()), this, SLOT(equal()));

    ui -> pluse -> setCheckable(true);
    ui -> minus -> setCheckable(true);
    ui -> div -> setCheckable(true);
    ui -> mul -> setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitsNumbers()
{
    QPushButton* button = (QPushButton*)sender();

    double allNumbers;
    QString newLabel;
    allNumbers = (ui -> display -> text() + button -> text()).toDouble();
    newLabel = QString::number(allNumbers, 'g', 15);

    ui -> display -> setText(newLabel);
}

void MainWindow::operations()
{
    QPushButton* button = (QPushButton*)sender();
    firstNum = ui -> display -> text().toDouble();
    ui -> display -> setText("");
    button -> setChecked(true);
}

void MainWindow::equal()
{
    QString newLabel;
    double labelNum;
    double secondNum;

    secondNum = ui -> display -> text().toDouble();

    if (ui -> pluse -> isChecked()) {
        labelNum = firstNum + secondNum;
        newLabel = QString::number(labelNum, 'g', 15);

    } else if (ui -> minus -> isChecked()) {
        labelNum = firstNum - secondNum;
        newLabel = QString::number(labelNum, 'g', 15);

    } else if (ui -> mul -> isChecked()) {
        labelNum = firstNum * secondNum;
        newLabel = QString::number(labelNum, 'g', 15);

    } else if (ui -> div -> isChecked()) {
        if (secondNum == 0) {
            newLabel = QString::number(0, 'g', 15);
            ui -> display -> setText("0");
        } else {
            labelNum = firstNum / secondNum;
            newLabel = QString::number(labelNum, 'g', 15);
        }
    }

    ui -> display -> setText(newLabel);

    ui -> pluse -> setChecked(false);
    ui -> minus -> setChecked(false);
    ui -> mul -> setChecked(false);
    ui -> div -> setChecked(false);
}


void MainWindow::on_del_clicked()
{
    ui -> pluse -> setChecked(false);
    ui -> minus -> setChecked(false);
    ui -> div -> setChecked(false);
    ui -> mul -> setChecked(false);

    ui-> display -> setText("0");
}

