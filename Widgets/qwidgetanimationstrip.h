#ifndef QWIDGETANIMATIONSTRIP_H
#define QWIDGETANIMATIONSTRIP_H

#include <QWidget>
#include <QPainter>
#include <QScrollArea>
#include <QLabel>
#include <QHBoxLayout>

class QWidgetAnimationStrip : public QWidget
{
    Q_OBJECT
    void paintEvent(QPaintEvent *e);
public:
    explicit QWidgetAnimationStrip(QWidget *parent = nullptr);

signals:

public slots:
    void addQImage(QImage*image);
};

#endif // QWIDGETANIMATIONSTRIP_H
