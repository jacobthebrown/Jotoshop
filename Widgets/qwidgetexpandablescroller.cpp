#include "qwidgetexpandablescroller.h"

QWidgetExpandableScroller::QWidgetExpandableScroller(QWidget *parent) : QWidget(parent)
{

}

/*
 *  Event for displaying preview widget and current image if exists.
 */
void QWidgetExpandableScroller::paintEvent(QPaintEvent *event) {


    QPainter painter(this);
    QPainterPath path;
    //path.addRoundRect(this->width()/2, -1,(this->width()/2) + 1, this->height() + 1, 0);
    path.addRoundRect(3,-1,this->width()-4, this->height() + 1, 0);

    QPen pen(Qt::lightGray, 1);
    painter.setPen(pen);

    painter.begin(this);

        painter.drawPath(path);

    painter.end();

    QWidget::paintEvent(event);
}

/*
 *  TODO: Comment, refactor to make generic execution.
 */
void QWidgetExpandableScroller::mouseMoveEvent(QMouseEvent *event)
{
    //if (event->x() >= this->x() && event->x() <= this->x() + this->width()) {
    //    if (event->y() >= this->y() && event->y() <= this->y() + this->height()) {
            setCursor(Qt::IBeamCursor);
    //    }
    //}

    if (this->MouseDown && this->WidgetToProtect->width() > 128) { //&& WidgetToScroll->() < WidgetToScroll->height() ) {
        //event->DragEnter
        //qDebug() << this->mapFromGlobal(event->globalPos());
        //WidgetToScroll->resize(DefaultWidth - event->x(), WidgetToScroll->height());
        WidgetToScroll->setMinimumWidth(WidgetToScroll->width() - event->x());//this->x() - event->x());

    }
    else {
        this->WidgetToProtect->resize(this->WidgetToProtect->width() + 2, this->WidgetToProtect->height());
    }
}

/*
 *  TODO: Refactor to remove boolean, and refactor for more mouse types.
 */
void QWidgetExpandableScroller::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        this->MouseDown = true;
    }
}

/*
 *  TODO: See mousePressEvent todo.
 */
void QWidgetExpandableScroller::mouseReleaseEvent(QMouseEvent* event) {

    if (event->button() == Qt::LeftButton) {
        this->MouseDown = false;
    }

}
