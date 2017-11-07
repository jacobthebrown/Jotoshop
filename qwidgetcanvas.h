#ifndef QWidgetCanvas_H
#define QWidgetCanvas_H

#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QHBoxLayout>
#include <QPainter>
#include <QTime>
#include <string>
#include <QDebug>
#include <QtDebug>
#include <QMouseEvent>
#include <QTimer>
#include <QApplication>
#include <cmath>
#include <algorithm>

class QWidgetCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetCanvas(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

    QImage* CanvasImage;
    QPainter* CanvasPainter;
protected:
    //void paintEvent(QPaintEvent *event);

signals:
    //void DrawPaint(QMouseEvent *event);

private:
    bool IsPressed;
    double LastX;
    double LastY;
    QTimer* MouseActionTimer;
    //AbtractTool CurrentTool;

public slots:
};

#endif // QWidgetCanvas_H
