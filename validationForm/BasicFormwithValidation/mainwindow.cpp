#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui -> sub, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    //button_ = new QPushButton("&Submit", this);
    //button_ -> setGeometry(200, 400, 80, 80);
    //connect(button_, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    //connect(ui -> submit, &QPushButton::pressed, this, &MainWindow::on_submit_pressed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (ui -> lineEdit1 -> text().isEmpty() || ui -> lineEdit2 -> text().isEmpty() || ui -> lineEdit3 -> text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "fill out all the forms");
    } else {
        QMessageBox::information(this, "Succes", "submit successfully");
    }
}

