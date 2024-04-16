#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QWheelEvent>
#include <QTransform>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openImage);
    connect(ui->actionZoomIn, &QAction::triggered, this, &MainWindow::zoomIn);
    connect(ui->actionZoomOut, &QAction::triggered, this, &MainWindow::zoomOut);
    connect(ui->actionRotate, &QAction::triggered, this, &MainWindow::rotate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", QString(), "Images (*.png *.jpg *.jpeg)");

    if (!fileName.isEmpty()) {
        currentPixmap = QPixmap(fileName);
        scaleFactor = 1.0;

        ui -> imageLabel -> setPixmap(currentPixmap.scaledToWidth(ui->imageLabel->width(), Qt::SmoothTransformation));
        ui -> imageLabel -> setScaledContents(true);
    }
}

void MainWindow::zoomIn()
{
    scaleFactor *= 1.2;
    ui -> imageLabel -> resize(scaleFactor * ui -> imageLabel -> pixmap().size());
}

void MainWindow::zoomOut()
{
    scaleFactor /= 1.2;
    ui -> imageLabel -> resize(scaleFactor * ui -> imageLabel -> pixmap().size());
}

void MainWindow::rotate()
{
    QTransform image;
    image.rotate(90);
    currentPixmap = currentPixmap.transformed(image);
    ui -> imageLabel -> setPixmap(currentPixmap);
}




