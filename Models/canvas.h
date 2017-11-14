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
    Canvas(int width, int height);
    Canvas(const Canvas& other);
    ~Canvas();
    QImage* GetImage() const;
    void LoadImage(QImage* im);
private:
    QImage* CanvasImage;
    QSize canvasSize;
};

#endif // CANVAS_H


