#include "qwidgetcanvas.h"

QWidgetCanvas::QWidgetCanvas(QWidget *parent) : QWidget(parent)
{

    CanvasPainter = new QPainter(this);
    this->CanvasImage = new QImage(QSize(512, 512), QImage::Format_ARGB32);

}

void QWidgetCanvas::paintEvent(QPaintEvent *event) {

        QPainter painter(this);
        int ImageWidth = (this->width()/2) - (CanvasImage->width()/2);
        int ImageHeight = (this->height()/2) - (CanvasImage->height()/2);
        painter.drawImage(ImageWidth, ImageHeight, *CanvasImage);
        painter.drawRect(0,0,this->width() - 1, this->height() - 1);

        QWidget::paintEvent(event);

}

/*
void QWidgetCanvas::addCanvas()
{
    CanvasModel* newCan = new CanvasModel;
    currentCanvas = newCan;
    composites.push_back(currentCanvas);
    emit sendCurrentCanvas(composites.at(0));
}

void QWidgetCanvas::resizeEvent(QResizeEvent *event)
{
    if (width() > CanvasImage->width() || height() > CanvasImage->height()) {
        int newWidth = qMax(width() + 128, CanvasImage->width());
        int newHeight = qMax(height() + 128, CanvasImage->height());
    }
    QWidget::resizeEvent(event);
}
*/
