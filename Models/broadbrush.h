#ifndef BROADBRUSH_H
#define BROADBRUSH_H
#include "basetoolclass.h"

class BroadBrush : public BaseToolClass
{
public:
    BroadBrush();
    QColor GetColor();
    int GetWidth();

    void SetWidth(int newWidth);
    void SetColor(QColor newColor);
    void Paint(QImage*,QPoint);

    virtual QString GetName();
    virtual void SetName(QString ToolName);


};

#endif // BROADBRUSH_H
