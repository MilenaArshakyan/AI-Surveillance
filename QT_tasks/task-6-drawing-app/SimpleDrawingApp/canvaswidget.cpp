#include "canvaswidget.h"

CanvasWidget::CanvasWidget(QWidget *parent) : QWidget(parent), currentTool(LineTool) {}

void CanvasWidget::setCurrentTool(DrawingTool tool)
{
    currentTool = tool;
}

void CanvasWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    for (const QRect &shapeRect : shapes)
    {
        painter.drawRect(shapeRect);
    }

    if (!currentShape.isNull())
    {
        painter.drawRect(currentShape);
    }
}

void CanvasWidget::mousePressEvent(QMouseEvent *event)
{
    if (currentTool != -1)
    {
        currentShape.setTopLeft(event->pos());
        currentShape.setSize(QSize());

        if (currentTool == LineTool)
        {
            currentShape.setSize(QSize(0, 0));
        }
        else if (currentTool == RectangleTool)
        {
            currentShape.setSize(QSize(10, 10));
        }

        update();
    }
}

void CanvasWidget::mouseMoveEvent(QMouseEvent *event)
{

    if (!currentShape.isNull())
    {
        QSize newSize(event -> pos().x() - currentShape.x(), event -> pos().y() - currentShape.y());
        currentShape.setSize(newSize);
        update();
    }
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent *event)
{

    if (!currentShape.isNull())
    {
        QSize newSize(event -> pos().x() - currentShape.x(), event -> pos().y() - currentShape.y());
        currentShape.setSize(newSize);
        shapes.append(currentShape);
        currentShape = QRect();
        update();
    }
}
