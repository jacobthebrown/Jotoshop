#ifndef QCANVASWIDGET_H
#define QCANVASWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVector>
#include "canvasmodel.h"


class QCanvasWidget: public QWidget
{
    Q_OBJECT
public:
    QCanvasWidget();
private:
    CanvasModel* currentCanvas;
    QVector<CanvasModel*> composites;

public slots:
    void addCanvas();

signals:
    void sendCurrentCanvas(CanvasModel*);
};

#endif // QCANVASWIDGET_H
