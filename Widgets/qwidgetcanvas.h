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
    QVector<QImage *> getAllCompositeImages();
    void setActiveCanvas(Canvas *can);

    void drawLineTo(const QPoint &endPoint);

    QVector<Canvas*> composites; //PUBLIC FOR TESTING
    int imageWidth;
    int imageHeight;


protected:
    void mouseMoveEvent(QMouseEvent *mouse_event);
    void mousePressEvent(QMouseEvent *mouse_event);


private:
    void paintEvent(QPaintEvent *event);
    bool MouseDown;
    Canvas* ActiveCanvas;
    void addCanvas(QImage*);
    double CurrentScale;


signals:
    void sendImages(QVector<QImage *>);
    void ImageUpdate(QImage*, int);

private slots:
    void addCanvas();
    void load(QImage*);




    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // QWIDGETCANVAS_H
