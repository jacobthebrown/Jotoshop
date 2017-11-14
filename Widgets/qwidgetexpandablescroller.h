#ifndef QWIDGETEXPANDABLESCROLLER_H
#define QWIDGETEXPANDABLESCROLLER_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

class QWidgetExpandableScroller : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetExpandableScroller(QWidget *parent = nullptr);
    ~QWidgetExpandableScroller();
    QWidget* WidgetToScroll;
    QWidget* WidgetToProtect;
    bool MouseDown;
    // TODO: Scrolling POLICY VERT/HORZ?

private:
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // QWIDGETEXPANDABLESCROLLER_H
