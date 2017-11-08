#include "qwidgetpreview.h"
#include <QDebug>
/*
 *  TODO: Insert documentation.
 */
QWidgetPreview::QWidgetPreview(QWidget *parent) : QWidget(parent)
{
    //timer.start(2000, this);
    imagesPos = 0;
    m_image = nullptr;
}

void QWidgetPreview::setImage(QImage *image)
{
    m_image = image;
    repaint();

}

/*
 *  TODO: Insert documentation.
 */
void QWidgetPreview::setImages(QVector<QImage *> im)
{
    images = im;
}

void QWidgetPreview::setSpeed(int speed)
{
    fps = 1000/speed;
    timer.start(fps, this);
}

/*
 *  TODO: Insert documentation.
 */
void QWidgetPreview::paintEvent(QPaintEvent *event) {


    QPainter painter(this);
    if(m_image != nullptr)
        painter.drawImage(rect(), *m_image, m_image->rect()); // CRASHES HERE

    //painter.drawRect(0,0,this->width() - 1, this->height() - 1);
    QWidget::paintEvent(event);


}

void QWidgetPreview::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer.timerId() && images.count() > 0)
    {
        qDebug() << "time";
        imagesPos++;
        if(imagesPos >= images.count())
            imagesPos = 0;
        setImage(images.at(imagesPos));
        update();
    }
    else
        QWidget::timerEvent(event);
}


