#ifndef QWIDGETPREVIEW_H
#define QWIDGETPREVIEW_H

#include <QWidget>
#include <QPainter>
#include <QBasicTimer>
#include <QTimerEvent>


class QWidgetPreview : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetPreview(QWidget *parent = nullptr);
    void setCurrentImage(QImage* image);
    void setImages(QVector<QImage*> im);
    void setSpeed(int speed);
    void setActiveStatus();

    void resize(double newScale);
private:
    QBasicTimer timer;
    QVector<QImage*> images;
    QImage* currentImage;
    int fps;
    int imagesPos;
    double scale;
    int originalWidth;
    int originalHeight;
    bool activeStatus;

    // Events
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);


signals:
    void activityStatus(bool);

public slots:
};

#endif // QWIDGETPREVIEW_H
