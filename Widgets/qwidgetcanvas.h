#ifndef QWIDGETCANVAS_H
#define QWIDGETCANVAS_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QSlider>
#include "../Models/canvas.h"

class QWidgetCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetCanvas(QWidget *parent = nullptr);

    QPoint lastPoint;

    Canvas* getActiveCanvas();
    QImage* getActiveCanvasImage();
    QVector<QImage> getAllCompositeImages();
    void addCanvas();
    void drawLineTo(const QPoint &endPoint);


protected:
    void mouseMoveEvent(QMouseEvent *mouse_event);
    void mousePressEvent(QMouseEvent *mouse_event);


private:
    void paintEvent(QPaintEvent *event);
    bool MouseDown;


    //QPainter* CanvasPainter;
    //QImage* CanvasImage;

private:
    QVector<Canvas*> composites;
    Canvas* ActiveCanvas;



    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // QWIDGETCANVAS_H
