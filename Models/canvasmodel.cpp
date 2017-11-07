#include "canvasmodel.h"

CanvasModel::CanvasModel(QWidget *parent) : QGraphicsView(parent)
{
    this->canvasImage = QImage(200,200, QImage::Format_ARGB32);

    this->canvasImage.fill(QColor(255,0,0));
    this->item = new QGraphicsPixmapItem(QPixmap::fromImage(canvasImage));
    this->scene = new QGraphicsScene(this);
    this->scene->addItem(item);
    this->setScene(scene);

}
// ok what
CanvasModel::~CanvasModel()
{
    ;
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


