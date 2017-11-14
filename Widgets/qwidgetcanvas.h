#ifndef QWIDGETCANVAS_H
#define QWIDGETCANVAS_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QSlider>
#include <QRect>
#include "../Models/canvas.h"
#include "../Models/basetoolclass.h"
#include "../Models/paintbrushtool.h"

class QWidgetCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetCanvas(QWidget *parent = nullptr);


    Canvas* getActiveCanvas();
    QImage* getActiveCanvasImage();
    QVector<QImage *> getAllCompositeImages();
    QImage* transparentBackground;
    void setActiveCanvas(Canvas *can);

    void drawLineTo(const QPoint &endPoint);

    QVector<Canvas*> composites; //PUBLIC FOR TESTING
    int imageWidth;
    int imageHeight;


protected:
    void mouseMoveEvent(QMouseEvent *mouse_event);
    void mousePressEvent(QMouseEvent *mouse_event);


private:
    BaseToolClass* selectedTool;

    void paintEvent(QPaintEvent *event);
    bool MouseDown;
    Canvas* ActiveCanvas;
    void addCanvas(QImage*);
    double CurrentScale;


signals:
    void sendImages(QVector<QImage *>);
    void ImageUpdate(QImage*, int);

    // Temp widget communication for tool
    void GrabTool();
    void RequestCurrentTool();
    void ReturnDropperColor(QColor);

private slots:
    void addCanvas();
    void load(QImage*);
    void RecieveTool(BaseToolClass*);

    // Temp widget comunictaion
    void CurrentTool(BaseToolClass*);




    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // QWIDGETCANVAS_H
