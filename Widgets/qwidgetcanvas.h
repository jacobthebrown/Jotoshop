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

    void addCanvas(QImage*);
    Canvas* getActiveCanvas();
    QImage* getActiveCanvasImage();
    QVector<QImage *> getAllCompositeImages();
    QImage* transparentBackground;
    void setActiveCanvas(Canvas *can);

    void drawLineTo(const QPoint &endPoint);
    void clear();

    QVector<Canvas*> composites; //PUBLIC FOR TESTING
    int imageWidth;
    int imageHeight;
    void resize(int width, int height, double scale);

    void shiftScale(double Scale);
    void setScale(double Scale);
    void addCanvas();
    void addCanvas(QSize);
protected:
    void mouseMoveEvent(QMouseEvent *mouse_event);
    void mousePressEvent(QMouseEvent *mouse_event);


private:
    BaseToolClass* selectedTool;

    void paintEvent(QPaintEvent *event);
    bool MouseDown;
    Canvas* ActiveCanvas;


    double CurrentScale;


public slots:


signals:
    void sendImages(QVector<QImage *>);
    void ImageUpdate(QImage*, int);

    // Temp widget communication for tool
    void GrabTool();
    void RequestCurrentTool();
    void ReturnDropperColor(QColor);

private slots:
    //void load(QImage*);
    void RecieveTool(BaseToolClass*);

    // Temp widget comunictaion
    void CurrentTool(BaseToolClass*);




    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // QWIDGETCANVAS_H
