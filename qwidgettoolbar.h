#ifndef QWIDGETTOOLBAR_H
#define QWIDGETTOOLBAR_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>

class QWidgetToolbar : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetToolbar(QWidget *parent = nullptr);
    void createToolButton();

private:
   int toolCount;

   void paintEvent(QPaintEvent *e);
signals:

public slots:
};

#endif // QWIDGETTOOLBAR_H
