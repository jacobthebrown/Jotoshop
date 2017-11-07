#ifndef QWIDGETCANVAS_H
#define QWIDGETCANVAS_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include "../Models/canvas.h"

class QWidgetCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetCanvas(QWidget *parent = nullptr);

    QPoint lastPoint;

    Canvas* getCurrentCanvas();
    QImage* getCurrentCanvasImage();
    void addCanvas();
    void drawLineTo(const QPoint &endPoint);


protected:
    void mouseMoveEvent(QMouseEvent *mouse_event);
    void mousePressEvent(QMouseEvent *mouse_event);


private:
    void paintEvent(QPaintEvent *event);


    //QPainter* CanvasPainter;
    //QImage* CanvasImage;

private:
    QVector<Canvas*> composites;
    Canvas* CurrentCanvas;


};

#endif // QWIDGETCANVAS_H
