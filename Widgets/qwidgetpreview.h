#ifndef QWIDGETPREVIEW_H
#define QWIDGETPREVIEW_H

#include <QWidget>
#include <QPainter>


class QWidgetPreview : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetPreview(QWidget *parent = nullptr);

    void playImages(QVector<QImage> images);

private:
    int fps;
    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // QWIDGETPREVIEW_H
