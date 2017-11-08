#ifndef QWIDGETPREVIEW_H
#define QWIDGETPREVIEW_H

#include <QWidget>
#include <QPainter>
//#include <QBasicTimer>
//#include <QTimerEvent>


class QWidgetPreview : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetPreview(QWidget *parent = nullptr);
    void setImage(QImage* image);

    void playImages(QVector<QImage*> im);

private:
    int fps;
    //QBasicTimer timer;
    QVector<QImage> images;
    void paintEvent(QPaintEvent *event);
    //void timerEvent(QTimerEvent *event);

    QImage* m_image;

signals:

public slots:
};

#endif // QWIDGETPREVIEW_H
