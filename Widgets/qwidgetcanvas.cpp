#include "qwidgetcanvas.h"

QWidgetCanvas::QWidgetCanvas(QWidget *parent) : QWidget(parent)
{

    //CanvasPainter = new QPainter(this);
    //this->CanvasImage = new QImage(QSize(512, 512), QImage::Format_ARGB32);
    this->CurrentCanvas = new Canvas();

    QImage* imageTest = this->getCurrentCanvas()->GetImage();

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            imageTest->setPixel(i,j, QColor(i,i,i,255).rgba());
}

Canvas* QWidgetCanvas::getCurrentCanvas()
{
    return this->CurrentCanvas;
}

void QWidgetCanvas::paintEvent(QPaintEvent *event) {

        QPainter painter(this);

        QImage* canvasImage = getCurrentCanvas()->GetImage();

        int ImageWidth = (this->width()/2) - (canvasImage->width()/2);
        int ImageHeight = (this->height()/2) - (canvasImage->height()/2);
        painter.drawImage(ImageWidth, ImageHeight, *canvasImage);
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
