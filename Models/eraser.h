#ifndef ERASER_H
#define ERASER_H
#include "basetoolclass.h"

class Eraser : public BaseToolClass
{
public:
    Eraser();
    QColor GetColor();
    int GetWidth();

    void SetWidth(int);
    void SetColor(QColor);
    void Paint(QImage*,QPoint);

    virtual QString GetName();
    virtual void SetName(QString ToolName);
};

#endif // ERASER_H
