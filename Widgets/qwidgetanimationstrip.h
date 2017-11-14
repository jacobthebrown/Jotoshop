#ifndef QWIDGETANIMATIONSTRIP_H
#define QWIDGETANIMATIONSTRIP_H

#include <QWidget>
#include <QPainter>
#include <QScrollArea>
#include <QLabel>
#include <QHBoxLayout>
#include <QListWidget>
#include <QVector>
#include <QPixmap>

class QWidgetAnimationStrip : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetAnimationStrip(QWidget *parent = nullptr);
    ~QWidgetAnimationStrip();
    QListWidget* listArea;
    QVector<QListWidgetItem*> animationPreviewItems;
    void clear();

private:
    QScrollArea* scrollArea;
    void paintEvent(QPaintEvent *e);
    void itemClicked(QListWidgetItem *item);

signals:
    void sendClickedCanvas(QListWidgetItem *);
public slots:
    void addQImage(QPixmap pix, int framePos);
    void canvasClicked(QListWidgetItem *);
    void refreshImage(QImage*, int);
};

#endif // QWIDGETANIMATIONSTRIP_H
