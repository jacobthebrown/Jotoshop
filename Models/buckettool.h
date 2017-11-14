#ifndef BUCKETTOOL_H
#define BUCKETTOOL_H
#include "basetoolclass.h"

class bucketTool : public BaseToolClass
{
public:
    bucketTool();

    QColor GetColor();
    int GetWidth();

    void SetWidth(int newWidth);
    void SetColor(QColor newColor);
    void Paint(QImage*, QPoint);

    virtual QString GetName();
    virtual void SetName(QString ToolName);
    void BreadthFirst(QImage* activeCanvas, QPoint mouse_pos);
};

#endif // BUCKETTOOL_H
