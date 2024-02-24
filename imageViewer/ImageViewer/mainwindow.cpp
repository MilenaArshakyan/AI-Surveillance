#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("/Users/milena/Desktop/aiSur/AI-Surveillance-Tasks/imageViewer/images/img.jpg");
    ui -> picLabel -> setPixmap(pix);
    ui -> picLabel -> setScaledContents( true );
    ui -> picLabel -> setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.jpg *.jpeg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Images"), "/Users/milena/Desktop/aiSur/AI-Surveillance-Tasks/imageViewer/images", tr("Image Files (*.png *.jpg *.jpeg)"));

    if (!fileName.isEmpty()) {
        QImage image(fileName);
        ui -> picLabel -> setPixmap(QPixmap::fromImage(image));
    }
}

