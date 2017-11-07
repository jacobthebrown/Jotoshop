#ifndef QWIDGETCANVAS_H
#define QWIDGETCANVAS_H

#include <QWidget>
#include <QPainter>
#include <QImage>

class QWidgetCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetCanvas(QWidget *parent = nullptr);

private:
    void paintEvent(QPaintEvent *event);
    QPainter* CanvasPainter;
    QImage* CanvasImage;

private:
    //CanvasModel* currentCanvas;
    //QVector<CanvasModel*> composites;

public slots:
    //void addCanvas();

signals:
    //void sendCurrentCanvas(CanvasModel*);
};

#endif // QWIDGETCANVAS_H
