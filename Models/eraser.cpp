#include "eraser.h"
#include "basetoolclass.h"
Eraser::Eraser()
{

}

/*
 * provides the current selected color
 */
QColor Eraser::getColor()
{
    return color;
}

/*
 * Provides the user with the width of the tool
 */
int Eraser::getWidth()
{
    return width;
}

/*
 * sets tool width with the value passed
 */
void Eraser::setWidth(int newWidth)
{
    width = newWidth;
}

/*
 * sets the tool color to value passed
 */
void Eraser::setColor(QColor newColor)
{
    color = newColor;
}

/*
 * Changes the alpha channel to erase
 */
void Eraser::paint(QImage* activeCanvas, QPoint endPoint)
{

    if (activeCanvas == nullptr)
        return;

    QPainter painter(activeCanvas);


    this->color.setAlpha(this->color.alpha()/255);
    int offet = width/2;
    for(int x = endPoint.x() - offet; x < endPoint.x() + offet; x++)
    {
        for(int y = endPoint.y() - offet; y < endPoint.y() + offet; y++)
        {
            if (x >= 0 && x < activeCanvas->width() && y >= 0 && y < activeCanvas->height())
            {
                    activeCanvas->setPixelColor(QPoint(x,y),this->color);
            }
        }
    }

//    painter.setPen(QPen(this->color, this->width, Qt::SolidLine, Qt::SquareCap));
//    painter.drawPoint(endPoint);

}

/*
 * Gives a string representation of the tools' name
 */
QString Eraser::getName()
{
    return name;
}


/*
 * Sets the tools name
 */
void Eraser::setName(QString ToolName)
{
    name = ToolName;
}
