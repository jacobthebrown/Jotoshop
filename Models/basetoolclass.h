#ifndef BASETOOLCLASS_H
#define BASETOOLCLASS_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QObject>
#include <QString>
#include <QColor>

class BaseToolClass
{
public:
    BaseToolClass();


    QColor color;
    int width;
    QString name;

    virtual QColor getColor() = 0;
    virtual void setColor(QColor) = 0;
    virtual void setName(QString) = 0;
    virtual int getWidth() = 0;
    virtual void setWidth(int) = 0;
    virtual void paint(QImage*, QPoint) = 0;
    virtual QString getName() = 0;


};

#endif // BASETOOLCLASS_H
