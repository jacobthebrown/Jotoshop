#ifndef QWIDGETEXPANDABLESCROLLER_H
#define QWIDGETEXPANDABLESCROLLER_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

class QWidgetExpandableScroller : public QWidget
{
    Q_OBJECT
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
public:
    explicit QWidgetExpandableScroller(QWidget *parent = nullptr);
    QWidget* WidgetToScroll;
    QWidget* WidgetToProtect;
    bool MouseDown;
    // TODO: Scrolling POLICY VERT/HORZ?

signals:

public slots:
};

#endif // QWIDGETEXPANDABLESCROLLER_H
