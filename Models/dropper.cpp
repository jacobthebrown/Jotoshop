#include "dropper.h"

Dropper::Dropper()
{

}

/*
 * provides the current selected color
 */
QColor Dropper::getColor()
{
    return color;
}

/*
 * Provides the user with the width of the tool
 */
int Dropper::getWidth()
{
    return width;
}

/*
 * sets tool width with the value passed
 */
void Dropper::setWidth(int newWidth)
{
    width = newWidth;
}

/*
 * sets the tool color to value passed
 */
void Dropper::setColor(QColor newcolor)
{
    color = newcolor;
}

/*
 * Declare since the base class is abstract
 */
void Dropper::paint(QImage* activeCanvas, QPoint endPoint)
{

}

/*
 * Gives a string representation of the tools' name
 */
QString Dropper::getName()
{
    return name;
}

/*
 * Sets the tools name
 */
void Dropper::setName(QString ToolName)
{
    name = ToolName;
}


