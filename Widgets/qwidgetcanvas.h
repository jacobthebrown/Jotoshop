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
    Canvas* getCurrentCanvas();

private:
    void paintEvent(QPaintEvent *event);


    //QPainter* CanvasPainter;
    //QImage* CanvasImage;

private:
    //CanvasModel* currentCanvas;
    //QVector<CanvasModel*> composites;
    Canvas* CurrentCanvas;

public slots:
    //void addCanvas();

signals:
    //void sendCurrentCanvas(CanvasModel*);
};

#endif // QWIDGETCANVAS_H
