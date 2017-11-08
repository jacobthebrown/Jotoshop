#include "qwidgetpreview.h"
#include <QDebug>
/*
 *  TODO: Insert documentation.
 */
QWidgetPreview::QWidgetPreview(QWidget *parent) : QWidget(parent)
{
    //timer.start(60, this);
}

void QWidgetPreview::setImage(QImage *image)
{
    m_image = image;
    repaint();

}

/*
 *  TODO: Insert documentation.
 */
void QWidgetPreview::playImages(QVector<QImage *> im)
{
    foreach (QImage* i, im) {
        setImage(i);
    };
}

/*
 *  TODO: Insert documentation.
 */
void QWidgetPreview::paintEvent(QPaintEvent *event) {

    if (!m_image) { return; }
    QPainter painter(this);
    painter.drawImage(rect(), *m_image, m_image->rect());

    //painter.drawRect(0,0,this->width() - 1, this->height() - 1);
    QWidget::paintEvent(event);


}

//void QWidgetPreview::timerEvent(QTimerEvent *event)
//{
//    if (event->timerId() == timer.timerId())
//    {
//        qDebug() << "time";
//        //++imagesPos;
//        update();
//    }
//    else
//        QWidget::timerEvent(event);
//}


