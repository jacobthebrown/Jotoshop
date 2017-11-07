#ifndef QWIDGETPREVIEW_H
#define QWIDGETPREVIEW_H

#include <QWidget>
#include <Qpainter>

class QWidgetPreview : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetPreview(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // QWIDGETPREVIEW_H
