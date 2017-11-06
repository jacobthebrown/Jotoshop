#include "qcanvaswidget.h"

QCanvasWidget::QCanvasWidget()
{

}

void QCanvasWidget::addCanvas()
{
    CanvasModel* newCan = new CanvasModel;
    currentCanvas = newCan;
    composites.push_back(currentCanvas);
    emit sendCurrentCanvas(composites.at(0));
}
