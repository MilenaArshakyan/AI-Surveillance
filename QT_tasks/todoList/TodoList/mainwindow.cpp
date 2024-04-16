#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui -> add, &QPushButton::clicked, this, &MainWindow::add_clicked);
    connect(ui -> remove, &QPushButton::clicked, this, &MainWindow::remove_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_clicked() {
    QString add_text = ui -> lineEdit -> text();
    if (!add_text.isEmpty()) {
        ui -> listWidget -> addItem(add_text);
        ui -> lineEdit -> clear();
    }
}

void MainWindow::remove_clicked() {
    int selectedItem = ui -> listWidget -> currentRow();

    if (selectedItem < 0) {
        QMessageBox::warning(this, "Warning", "Select a task to remove");
    } else {
        delete ui -> listWidget -> takeItem(selectedItem);
    }
}
