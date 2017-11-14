#ifndef BUCKETTOOL_H
#define BUCKETTOOL_H
#include "basetoolclass.h"

class bucketTool : public BaseToolClass
{
public:
    bucketTool();

    QColor getColor();
    int getWidth();

    void setWidth(int newWidth);
    void setColor(QColor newColor);
    void paint(QImage*, QPoint);

    virtual QString getName();
    virtual void setName(QString ToolName);
    void breadthFirst(QImage* activeCanvas, QPoint mouse_pos);
};

#endif // BUCKETTOOL_H
