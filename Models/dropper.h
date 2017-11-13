#ifndef DROPPER_H
#define DROPPER_H
#include "basetoolclass.h"
#include <QObject>

class Dropper : public BaseToolClass
{
public:
    Dropper();

    QColor GetColor();
    int GetWidth();

    void SetWidth(int newWidth);
    void SetColor(QColor newcolor);
    void Paint(QImage*, QPoint);

    virtual QString GetName();
    virtual void SetName(QString ToolName);


};
#endif // DROPPER_H

