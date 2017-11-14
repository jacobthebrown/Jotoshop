#include "broadbrush.h"

BroadBrush::BroadBrush()
{

}


QColor BroadBrush::GetColor()
{
    return color;
}

int BroadBrush::GetWidth()
{
    return width;
}

void BroadBrush::SetWidth(int newWidth)
{
    width = newWidth;
}

void BroadBrush::SetColor(QColor newColor)
{
    color = newColor;
}

void BroadBrush::Paint(QImage* activeCanvas, QPoint endPoint)
{

    if (activeCanvas == nullptr)
        return;

    QPainter painter(activeCanvas);

    painter.setPen(QPen(this->color, this->width, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
    painter.drawPoint(endPoint);


}

QString BroadBrush::GetName()
{
    return name;
}

void BroadBrush::SetName(QString ToolName)
{
    name = ToolName;
}
