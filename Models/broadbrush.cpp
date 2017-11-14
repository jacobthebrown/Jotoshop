#include "broadbrush.h"

BroadBrush::BroadBrush()
{

}

/*
 * provides the current selected color
 */
QColor BroadBrush::getColor()
{
    return color;
}

/*
 * Provides the user with the width of the tool
 */
int BroadBrush::getWidth()
{
    return width;
}

/*
 * sets tool width with the value passed
 */
void BroadBrush::setWidth(int newWidth)
{
    width = newWidth;
}

/*
 * sets the tool color to value passed
 */
void BroadBrush::setColor(QColor newColor)
{
    color = newColor;
}

/*
 * Uses a painter to change the pixes on the image at the point specified
 */
void BroadBrush::paint(QImage* activeCanvas, QPoint endPoint)
{

    if (activeCanvas == nullptr)
        return;

    QPainter painter(activeCanvas);

    painter.setPen(QPen(this->color, this->width, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
    painter.drawPoint(endPoint);


}

/*
 * Gives a string representation of the tools' name
 */
QString BroadBrush::getName()
{
    return name;
}

/*
 * Sets the tools name
 */
void BroadBrush::setName(QString toolName)
{
    name = toolName;
}
