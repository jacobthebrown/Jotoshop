#ifndef CANVASMODEL_H
#define CANVASMODEL_H
#include <QOBject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>


class CanvasModel : public QLabel
{
    Q_OBJECT
public:
    CanvasModel(QWidget *parent = 0);
    QImage canvasImage;

protected:
    void mouseMoveEvent(QMouseEvent *mouse_event);
    void mousePressEvent(QMouseEvent *mouse_event);

signals:
    void sendMousePosition(QPoint&);
};

#endif // CANVASMODEL_H
