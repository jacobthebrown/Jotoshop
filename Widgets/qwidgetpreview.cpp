#include "qwidgetpreview.h"

/*
 *  TODO: Insert documentation.
 */
QWidgetPreview::QWidgetPreview(QWidget *parent) : QWidget(parent)
{

}

/*
 *  TODO: Insert documentation.
 */
void QWidgetPreview::playImages(QVector<QImage> images)
{
    QPainter painter(this);
    QRectF target(10.0, 20.0, 80.0, 60.0);
    QRectF source(0.0, 0.0, 70.0, 40.0);
    foreach (QImage im, images) {
        painter.drawImage(target,im,source);
    }
}

/*
 *  TODO: Insert documentation.
 */
void QWidgetPreview::paintEvent(QPaintEvent *event) {

        QPainter painter(this);
        painter.drawRect(0,0,this->width() - 1, this->height() - 1);
        QWidget::paintEvent(event);

}
