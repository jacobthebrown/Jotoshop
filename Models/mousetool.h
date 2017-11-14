#ifndef MOUSETOOL_H
#define MOUSETOOL_H
#include "basetoolclass.h"

class MouseTool : public BaseToolClass
{
public:
    MouseTool();

    QColor getColor();
    int getWidth();

    void setWidth(int newWidth);
    void setColor(QColor newColor);
    void paint(QImage*,QPoint);

    virtual QString getName();
    virtual void setName(QString ToolName);
};

#endif // MOUSETOOL_H
