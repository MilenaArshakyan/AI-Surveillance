#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

class CanvasWidget : public QWidget
{
    Q_OBJECT

public:
    enum DrawingTool {
        LineTool,
        RectangleTool,
    };

    explicit CanvasWidget(QWidget *parent = nullptr);
    void setCurrentTool(DrawingTool tool);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    DrawingTool currentTool;
    QRect currentShape;
    QVector<QRect> shapes;
};

#endif // CANVASWIDGET_H
