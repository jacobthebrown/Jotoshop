#ifndef BASETOOLCLASS_H
#define BASETOOLCLASS_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QObject>
#include <Qstring>

class BaseToolClass
{
public:
    BaseToolClass();

    QColor color;
    int width;
    QString name;

    virtual QColor GetColor() = 0;
    virtual void SetColor(QColor) = 0;
    virtual void SetName(QString) = 0;
    virtual int GetWidth() = 0;
    virtual void SetWidth(int) = 0;
    virtual void Paint(QImage*, QPoint) = 0;
    virtual QString GetName() = 0;


};

#endif // BASETOOLCLASS_H
