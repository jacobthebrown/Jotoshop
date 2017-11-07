#include "qwidgetpreview.h"

QWidgetPreview::QWidgetPreview(QWidget *parent) : QWidget(parent)
{

}

void QWidgetPreview::paintEvent(QPaintEvent *event) {

        QPainter painter(this);

        painter.drawRect(0,0,this->width() - 1, this->height() - 1);

        QWidget::paintEvent(event);

}
