#ifndef QWIDGETTOOLBAR_H
#define QWIDGETTOOLBAR_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QSlider>
#include <QLabel>
#include <QButtonGroup>
#include "qwidgetslidercombo.h"
#include <QList>
#include <vector>


class QWidgetToolbar : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetToolbar(QWidget *parent = nullptr);

private:
    QPushButton* createToolButton();
    void paintEvent(QPaintEvent *e);
    int upPadding, rightPadding, bottomPadding, leftPadding;
    QButtonGroup* ToolButtons;

    int getSize();
signals:

public slots:
};

#endif // QWIDGETTOOLBAR_H
