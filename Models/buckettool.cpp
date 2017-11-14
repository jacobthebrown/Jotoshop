#include "buckettool.h"
#include <queue>
#include <QDebug>
bucketTool::bucketTool()
{

}

/*
 * provides the current selected color
 */
QColor bucketTool::getColor()
{
    return color;
}

/*
 * Provides the user with the width of the tool
 */
int bucketTool::getWidth()
{
    return width;
}

/*
 * sets tool width with the value passed
 */
void bucketTool::setWidth(int newWidth)
{
    width = newWidth;
}

/*
 * sets the tool color to value passed
 */
void bucketTool::setColor(QColor newColor)
{
    color = newColor;
}


/*
 * Gives a string representation of the tools' name
 */
QString bucketTool::getName()
{
    return name;
}

/*
 * Sets the tools name
 */
void bucketTool::setName(QString ToolName)
{
    name = ToolName;
}


/*
 * Uses a painter to change the pixes on the image at the point specified, using a breadth first search to fill
 */
void bucketTool::paint(QImage* activeCanvas, QPoint mouse_pos)
{
    breadthFirst(activeCanvas,mouse_pos);
}

/*
 * Starts the point click, saves the color clicked. Checks the neighbors on the point.
 * If they are the same color it paints them and enques them repeating this until the Queue is empty
 *
 */
void bucketTool::breadthFirst(QImage* activeCanvas, QPoint mouse_pos)
{

    QColor removeColor = activeCanvas->pixelColor(mouse_pos);


    if(removeColor.isValid() && removeColor.rgba() != color.rgba())
    {
        QPoint current;
        //QImage* newImage = new QImage(activeCanvas->copy());
        activeCanvas->setPixel(mouse_pos,color.rgba());

        std::queue<QPoint> q;
        q.push(mouse_pos);

        // Goes through points: above, left,right,bottom if they are the same color that needs to be removed it fills them and enques them
        while(!q.empty())
        {
            current = q.front();
            q.pop();
            if(current.y() - 1 >= 0 && (activeCanvas->pixelColor(current.x(),current.y()-1).alpha() == removeColor.alpha() ))
            {
                activeCanvas->setPixel(current.x(), current.y() - 1,color.rgba());
                q.push(QPoint(current.x(), current.y() - 1));
            }
            if(current.y() + 1 < activeCanvas->height() && (activeCanvas->pixelColor(current.x(),current.y()+1).alpha()  == removeColor.alpha() ))
            {
                activeCanvas->setPixel(current.x(), current.y() + 1,color.rgba());
                q.push(QPoint(current.x(), current.y() + 1));
            }
            if(current.x() - 1 >= 0  && (activeCanvas->pixelColor(current.x() - 1,current.y()).alpha()  == removeColor.alpha()))
            {
                activeCanvas->setPixel(current.x() - 1, current.y(),color.rgba());
                q.push(QPoint(current.x() - 1, current.y()));
            }
            if(current.x() + 1 < activeCanvas->width()  && (activeCanvas->pixelColor(current.x() + 1,current.y()).alpha() == removeColor.alpha()))
            {
                activeCanvas->setPixel(current.x() + 1, current.y(),color.rgba());
                q.push(QPoint(current.x() + 1, current.y()));
            }
        }

    }


}
