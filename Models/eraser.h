#ifndef ERASER_H
#define ERASER_H
#include "basetoolclass.h"

class Eraser : public BaseToolClass
{
public:
    Eraser();
    QColor getColor();
    int getWidth();

    void setWidth(int);
    void setColor(QColor);
    void paint(QImage*,QPoint);

    virtual QString getName();
    virtual void setName(QString ToolName);
};

#endif // ERASER_H
