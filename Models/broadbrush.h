#ifndef BROADBRUSH_H
#define BROADBRUSH_H
#include "basetoolclass.h"

class BroadBrush : public BaseToolClass
{
public:
    BroadBrush();

    QColor getColor();
    int getWidth();

    void setWidth(int newWidth);
    void setColor(QColor newColor);
    void paint(QImage*,QPoint);

    virtual QString getName();
    virtual void setName(QString toolName);


};

#endif // BROADBRUSH_H
