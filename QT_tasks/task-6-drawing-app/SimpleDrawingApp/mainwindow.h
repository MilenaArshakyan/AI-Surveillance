#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canvaswidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineButton_clicked();
    void on_rectangleButton_clicked();
    void on_shapeComboBox_activated(const QString &shape);
  //  void on_shapeComboBox_activated(int index);

private:
    Ui::MainWindow *ui;
    CanvasWidget *canvasWidget;
};
#endif // MAINWINDOW_H
