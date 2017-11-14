#include "qwidgetexpandablescroller.h"

/*
 *  Constructor for new Expandable Scroller widget
 */
QWidgetExpandableScroller::QWidgetExpandableScroller(QWidget *parent) : QWidget(parent)
{

}

/*
 *  Destructor for Expandable Scroller widget
 */
QWidgetExpandableScroller::~QWidgetExpandableScroller()
{

}

/*
 *  Event handler for drawing scrollers
 */
void QWidgetExpandableScroller::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPainterPath path;
    path.addRoundRect(3,-1,this->width()-4, this->height() + 1, 0);

    QPen pen(Qt::lightGray, 1);
    painter.setPen(pen);

    painter.begin(this);

    painter.drawPath(path);

    painter.end();

    QWidget::paintEvent(event);
}

/*
 *  Event handler for mouse move events
 */
void QWidgetExpandableScroller::mouseMoveEvent(QMouseEvent *event)
{
    setCursor(Qt::IBeamCursor);

    if (this->MouseDown && this->WidgetToProtect->width() > 128)
        WidgetToScroll->setMinimumWidth(WidgetToScroll->width() - event->x());
    else
        this->WidgetToProtect->resize(this->WidgetToProtect->width() + 2, this->WidgetToProtect->height());    
}

/*
 *  Event handler for mouse press events
 */
void QWidgetExpandableScroller::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        this->MouseDown = true;   
}

/*
 *  Event handler for mouse release events
 */
void QWidgetExpandableScroller::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
        this->MouseDown = false;

}
