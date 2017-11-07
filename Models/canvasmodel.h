#ifndef CANVASMODEL_H
#define CANVASMODEL_H
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtWidgets>

class CanvasModel : public QGraphicsView
{
    Q_OBJECT
public:
    CanvasModel(QWidget *parent = 0);
    ~CanvasModel();
    QImage canvasImage;

    QGraphicsItem *item;
    QGraphicsScene *scene;

protected:
    void mouseMoveEvent(QMouseEvent *mouse_event);
    void mousePressEvent(QMouseEvent *mouse_event);

signals:
    void sendMousePosition(QPoint&);
};

#endif // CANVASMODEL_H


