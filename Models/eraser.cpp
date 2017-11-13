#include "eraser.h"
#include "basetoolclass.h"
Eraser::Eraser()
{

}

QColor Eraser::GetColor()
{
    return color;
}

int Eraser::GetWidth()
{
    return width;
}

void Eraser::SetWidth(int newWidth)
{
    width = newWidth;
}

void Eraser::SetColor(QColor newColor)
{
    color = newColor;
}

void Eraser::Paint(QImage* activeCanvas, QPoint endPoint)
{

    if (activeCanvas == nullptr)
        return;

    QPainter painter(activeCanvas);

    painter.setPen(QPen(this->color, this->width, Qt::SolidLine, Qt::SquareCap));
    painter.drawPoint(endPoint);

}

QString Eraser::GetName()
{
    return name;
}

void Eraser::SetName(QString ToolName)
{
    name = ToolName;
}
