#include "canvasmodel.h"

CanvasModel::CanvasModel(QWidget *parent) : QLabel(parent)
{

}

void CanvasModel::mouseMoveEvent(QMouseEvent *mouse_event)
{
    QPoint mousePos = mouse_event->pos();

    if(mousePos.x() <= this->size().width() && mousePos.y() <= this->size().height())
    {
        if(mousePos.x() > 0 && mousePos.y() > 0)
            emit sendMousePosition(mousePos);


    }
}

void CanvasModel::mousePressEvent(QMouseEvent *mouse_event)
{
    mouseMoveEvent(mouse_event);
}
