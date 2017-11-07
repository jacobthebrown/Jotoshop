#include "qwidgettoolbar.h"

QWidgetToolbar::QWidgetToolbar(QWidget *parent) : QWidget(parent)
{

    this->toolCount = 0;

    for(int i = 0; i < 10; i++) {
        createToolButton();
    }

}

void QWidgetToolbar::createToolButton() {

    QPushButton* pb = new QPushButton("button", this);
    pb->setMaximumSize(32,32);
    pb->setMinimumSize(32,32);
    pb->setText(QString(""));
    pb->move(16 + 32*(toolCount % 2), 16 + 32*(toolCount / 2));
    pb->show();

    (this->toolCount)++;

}

void QWidgetToolbar::paintEvent(QPaintEvent *e)
{
    QPainter painter;
    QPainterPath path;
    path.addRoundRect(8, 8, 80, 16 + 32*(toolCount / 2), 0);
    path.addRoundRect(0,0,this->width()-1,this->height()-1,0);

    QPen pen(Qt::lightGray, 10);
    painter.setPen(pen);

    painter.begin(this);
        painter.drawPath(path);
    painter.end();
}
