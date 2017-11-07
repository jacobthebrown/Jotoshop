#include "qwidgetcanvas.h"

QWidgetCanvas::QWidgetCanvas(QWidget *parent) : QWidget(parent)
{

    //CanvasPainter = new QPainter(this);
    //this->CanvasImage = new QImage(QSize(512, 512), QImage::Format_ARGB32);
    this->CurrentCanvas = new Canvas();
    this->composites.push_back(CurrentCanvas);

    QImage* imageTest = this->getCurrentCanvas()->GetImage();

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            imageTest->setPixel(i,j, QColor(i,i,i,255).rgba());
}

// Return current Canvas
Canvas* QWidgetCanvas::getCurrentCanvas()
{
    return this->CurrentCanvas;
}

// Return current Canvas QImage
QImage* QWidgetCanvas::getCurrentCanvasImage()
{
    return this->CurrentCanvas->GetImage();
}


void QWidgetCanvas::addCanvas()
{
    this->CurrentCanvas = new Canvas;
    //this->CurrentCanvas->GetImage()->fill(QColor(100,100,100)); // for test
    this->composites.push_back(CurrentCanvas);
}


void QWidgetCanvas::drawLineTo(const QPoint &endPoint)
{
        QPainter painter(this->getCurrentCanvasImage());

        painter.setPen(QPen(QColor("blue"), 10, Qt::SolidLine, Qt::RoundCap,
                            Qt::RoundJoin));
        //painter.drawLine(lastPoint, endPoint);
        painter.drawPoint(endPoint);



        update();

        lastPoint = endPoint;

}


void QWidgetCanvas::paintEvent(QPaintEvent *event) {

        QPainter painter(this);
        QRect dirtyRect = event->rect();
        painter.drawImage(dirtyRect, *getCurrentCanvasImage(), dirtyRect);

//        QImage* canvasImage = getCurrentCanvasImage();

//        int ImageWidth = (this->width()/2) - (canvasImage->width()/2);
//        int ImageHeight = (this->height()/2) - (canvasImage->height()/2);
//        painter.drawImage(ImageWidth, ImageHeight, *canvasImage);
//        painter.drawRect(0,0,this->width() - 1, this->height() - 1);


        //QWidget::paintEvent(event);



}


void QWidgetCanvas::mouseMoveEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        drawLineTo(event->pos());
    }

}

void QWidgetCanvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
            lastPoint = event->pos();
            mouseMoveEvent(event);

    }
}



/*
void QWidgetCanvas::resizeEvent(QResizeEvent *event)
{
    if (width() > CanvasImage->width() || height() > CanvasImage->height()) {
        int newWidth = qMax(width() + 128, CanvasImage->width());
        int newHeight = qMax(height() + 128, CanvasImage->height());
    }
    QWidget::resizeEvent(event);
}
*/
