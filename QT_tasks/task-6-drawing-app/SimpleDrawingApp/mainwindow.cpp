#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvaswidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    canvasWidget = new CanvasWidget(this);
    setCentralWidget(canvasWidget);

    //connect(ui->shapeComboBox, QOverload<const QString &>::of(&QComboBox::activated), this, &MainWindow::on_shapeComboBox_activated);

    connect(ui -> lineButton, &QPushButton::clicked, this, &MainWindow::on_lineButton_clicked);
    connect(ui -> rectangleButton, &QPushButton::clicked, this, &MainWindow::on_rectangleButton_clicked);
    connect(ui -> shapeComboBox, SIGNAL(activated(QString)), this, SLOT(on_shapeComboBox_activated(QString)));
   // connect(ui -> shapeComboBox, QOverload<const QString &>::of(&QComboBox::activated), this, &MainWindow::on_shapeComboBox_activated);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineButton_clicked()
{
    canvasWidget -> setCurrentTool(CanvasWidget::LineTool);
}


void MainWindow::on_rectangleButton_clicked()
{
    canvasWidget -> setCurrentTool(CanvasWidget::RectangleTool);
}

void MainWindow::on_shapeComboBox_activated(const QString &shape)
{
    if (shape == "Line") {
        canvasWidget -> setCurrentTool(CanvasWidget::LineTool);
    } else if (shape == "Rectangle") {
        canvasWidget -> setCurrentTool(CanvasWidget::RectangleTool);
    }
}
