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
    void setImage(QImage* image);

    void setImages(QVector<QImage*> im);

    void setSpeed(int speed);

private:
    int fps;
    int imagesPos;
    QBasicTimer timer;
    QVector<QImage*> images;
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

    QImage* m_image;

signals:

public slots:
};

#endif // QWIDGETPREVIEW_H
