#include "paintbrushtool.h"
#include <QPainter>
#include <QImage>

paintbrushTool::paintbrushTool()
{
}

QColor paintbrushTool::GetColor()
{
    return color;
}

int paintbrushTool::GetWidth()
{
    return width;
}

void paintbrushTool::SetWidth(int newWidth)
{
    width = newWidth;
}

void paintbrushTool::SetColor(QColor newColor)
{
    color =  newColor;
}
void paintbrushTool::Paint(QImage* activeCanvas, QPoint endPoint)
{

    if (activeCanvas == nullptr)
        return;

    QPainter painter(activeCanvas);

    painter.setPen(QPen(this->color, this->width, Qt::SolidLine, Qt::SquareCap));
    painter.drawPoint(endPoint);

}

QString paintbrushTool::GetName()
{
    return name;
}

void paintbrushTool::SetName(QString ToolName)
{
    name = ToolName;
}
