#ifndef QWIDGETANIMATIONSTRIP_H
#define QWIDGETANIMATIONSTRIP_H

#include <QWidget>
#include <QPainter>
#include <QScrollArea>
#include <QLabel>
#include <QHBoxLayout>
#include <QListWidget>
#include <QVector>

class QWidgetAnimationStrip : public QWidget
{
    Q_OBJECT
    void paintEvent(QPaintEvent *e);
    void itemClicked(QListWidgetItem *item);
public:
    explicit QWidgetAnimationStrip(QWidget *parent = nullptr);
    QListWidget* listArea;
    QVector<QListWidgetItem*> animationPreviewItems;

private:
    QScrollArea* scrollArea;


signals:
    void sendClickedCanvas(QListWidgetItem *); // needs to be emitted
public slots:
    void addQImage(QPixmap pix, int framePos);
    void canvasClicked(QListWidgetItem *);
};

#endif // QWIDGETANIMATIONSTRIP_H
