#include "qwidgetanimationstrip.h"



QWidgetAnimationStrip::QWidgetAnimationStrip(QWidget *parent) : QWidget(parent)
{

    QHBoxLayout* layout = new QHBoxLayout;
    layout->setMargin(3);
    this->setMaximumHeight(128);

    //QLabel* label = new QLabel("PISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISSPISS", this);
    //label->setMinimumSize(10000, this->height());

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->move(0,0);
    scrollArea->setMinimumSize(this->width(),this->height());
    scrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //scrollArea->setWidget(label);
    scrollArea->show();

    layout->addWidget(scrollArea);
    this->setLayout(layout);

}
/*
 * Slot for adding a widget to the animation strip.
 */
void QWidgetAnimationStrip::addQImage(QImage* image)
{

}

void QWidgetAnimationStrip::paintEvent(QPaintEvent *e)
{

    QPainter painter;
    QPainterPath path;
    path.addRoundRect(0,0,this->width()-1,this->height()-1,0);

    QPen pen(Qt::lightGray, 10);
    painter.setPen(pen);

    painter.begin(this);
        painter.drawPath(path);
    painter.end();
}
