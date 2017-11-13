#ifndef PAINTBRUSHTOOL_H
#define PAINTBRUSHTOOL_H
#include "basetoolclass.h"
#include <QObject>

class paintbrushTool : public BaseToolClass
{
public:
    paintbrushTool();

public:
    QColor GetColor();
    int GetWidth();

    void SetWidth(int);
    void SetColor(QColor);
    void Paint(QImage*,QPoint);
    virtual QString GetName();
    virtual void SetName(QString ToolName);

};

#endif // PAINTBRUSHTOOL_H
