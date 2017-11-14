#ifndef MOUSETOOL_H
#define MOUSETOOL_H
#include "basetoolclass.h"

class MouseTool : public BaseToolClass
{
public:
    MouseTool();

    QColor GetColor();
    int GetWidth();

    void SetWidth(int newWidth);
    void SetColor(QColor newColor);
    void Paint(QImage*,QPoint);

    virtual QString GetName();
    virtual void SetName(QString ToolName);
};

#endif // MOUSETOOL_H
