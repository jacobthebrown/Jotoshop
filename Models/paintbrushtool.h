#ifndef PAINTBRUSHTOOL_H
#define PAINTBRUSHTOOL_H
#include "basetoolclass.h"
#include <QObject>

class paintbrushTool : public BaseToolClass
{
public:
    paintbrushTool();

public:
    QColor getColor();
    int getWidth();

    void setWidth(int);
    void setColor(QColor);
    void paint(QImage*,QPoint);
    virtual QString getName();
    virtual void setName(QString ToolName);

};

#endif // PAINTBRUSHTOOL_H
