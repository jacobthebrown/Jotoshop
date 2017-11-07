#ifndef CANVAS_H
#define CANVAS_H
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtWidgets>

class Canvas
{

public:
    Canvas();
    ~Canvas();
    QImage* GetImage();

private:
    QImage* CanvasImage;

protected:

signals:
};

#endif // CANVAS_H


