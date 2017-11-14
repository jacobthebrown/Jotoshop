#include "mousetool.h"

MouseTool::MouseTool()
{

}

/*
 * provides the current selected color
 */
QColor MouseTool::getColor()
{
    return color;
}

/*
 * Provides the user with the width of the tool
 */
int MouseTool::getWidth()
{
    return width;
}

/*
 * sets tool width with the value passed
 */
void MouseTool::setWidth(int newWidth)
{
    width = newWidth;
}

/*
 * sets the tool color to value passed
 */
void MouseTool::setColor(QColor newColor)
{
    color = newColor;
}

/*
 * Overriden to fulfill the interface
 */
void MouseTool::paint(QImage *, QPoint)
{

}

/*
 * Gives a string representation of the tools' name
 */
QString MouseTool::getName()
{
    return name;
}

/*
 * Sets the tools name
 */
void MouseTool::setName(QString ToolName)
{
    name = ToolName;
}
