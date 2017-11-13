#include "dropper.h"

Dropper::Dropper()
{

}

QColor Dropper::GetColor()
{
    return color;
}

int Dropper::GetWidth()
{
    return width;
}

void Dropper::SetWidth(int newWidth)
{
    width = newWidth;
}

void Dropper::SetColor(QColor newcolor)
{
    color = newcolor;
}

void Dropper::Paint(QImage* activeCanvas, QPoint endPoint)
{

      //emit SendColor(activeCanvas->pixelColor(endPoint.x(),endPoint.y()));
//    if (activeCanvas == nullptr)
//        return;

//    QPainter painter(activeCanvas);

//    painter.setPen(QPen(this->color, this->width, Qt::SolidLine, Qt::SquareCap));
//    painter.drawPoint(endPoint);

}

QString Dropper::GetName()
{
    return name;
}

void Dropper::SetName(QString ToolName)
{
    name = ToolName;
}


