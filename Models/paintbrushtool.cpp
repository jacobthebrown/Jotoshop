#include "paintbrushtool.h"
#include <QPainter>
#include <QImage>

paintbrushTool::paintbrushTool()
{
}

/*
 * provides the current selected color
 */
QColor paintbrushTool::getColor()
{
    return color;
}

/*
 * Provides the user with the width of the tool
 */
int paintbrushTool::getWidth()
{
    return width;
}

/*
 * sets tool width with the value passed
 */
void paintbrushTool::setWidth(int newWidth)
{
    width = newWidth;
}

/*
 * sets the tool color to value passed
 */
void paintbrushTool::setColor(QColor newColor)
{
    color =  newColor;
}

/*
 * Uses Qpainter to color the current point with the color and width of the tool
 */
void paintbrushTool::paint(QImage* activeCanvas, QPoint endPoint)
{

    if (activeCanvas == nullptr)
        return;

    QPainter painter(activeCanvas);

    painter.setPen(QPen(this->color, this->width, Qt::SolidLine, Qt::SquareCap));
    painter.drawPoint(endPoint);

}

/*
 * Gives a string representation of the tools' name
 */
QString paintbrushTool::getName()
{
    return name;
}

/*
 * Sets the tools name
 */
void paintbrushTool::setName(QString ToolName)
{
    name = ToolName;
}
