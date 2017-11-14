#ifndef DROPPER_H
#define DROPPER_H
#include "basetoolclass.h"
#include <QObject>

class Dropper : public BaseToolClass
{
public:
    Dropper();

    QColor getColor();
    int getWidth();

    void setWidth(int newWidth);
    void setColor(QColor newcolor);
    void paint(QImage*, QPoint);

    virtual QString getName();
    virtual void setName(QString ToolName);


};
#endif // DROPPER_H

