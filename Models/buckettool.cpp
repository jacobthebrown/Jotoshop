#include "buckettool.h"
#include <queue>
#include <QDebug>
bucketTool::bucketTool()
{

}

QColor bucketTool::GetColor()
{
    return color;
}

int bucketTool::GetWidth()
{
    return width;
}

void bucketTool::SetWidth(int newWidth)
{
    width = newWidth;
}

void bucketTool::SetColor(QColor newColor)
{
    color = newColor;
}


QString bucketTool::GetName()
{
    return name;
}

void bucketTool::SetName(QString ToolName)
{
    name = ToolName;
}

void bucketTool::Paint(QImage* activeCanvas, QPoint mouse_pos)
{
    BreadthFirst(activeCanvas,mouse_pos);
}

void bucketTool::BreadthFirst(QImage* activeCanvas, QPoint mouse_pos)
{
//    if(color.pixelColor(pos->x(),pos->y())!= t)
//    {
//        std::queue<QPoint> pointsToFill;
//        pointsToFill.push(QPoint(pos->x(),pos->y()));
//        color.setPixel(pos->x(), pos->y() + 1,t.rgba());
//        BreadthSearch(pointsToFill, color.pixelColor(pos->x(),pos->y()),color.width(),color.height());
//    }
//    QPainter painter(activeCanvas);
//    painter.setPen(QPen(Color);
//    painter.drawPoint(endPoint);


    QColor removeColor = activeCanvas->pixelColor(mouse_pos);


    if(removeColor != color)
    {
        QPoint current;
        //QImage* newImage = new QImage(activeCanvas->copy());
        activeCanvas->setPixel(mouse_pos,color.rgba());

        std::queue<QPoint> q;
        q.push(mouse_pos);

        while(!q.empty())
        {
            qDebug() << "X: " + QString::number(current.x()) +" Y: " + QString::number(current.y());
            current = q.front();
            q.pop();
            if(current.y() - 1 >= 0 && (activeCanvas->pixelColor(current.x(),current.y()-1) == removeColor))
            {
                activeCanvas->setPixel(current.x(), current.y() - 1,color.rgba());
                q.push(QPoint(current.x(), current.y() - 1));
            }
            if(current.y() + 1 < activeCanvas->height() && (activeCanvas->pixelColor(current.x(),current.y()+1) == removeColor))
            {
                activeCanvas->setPixel(current.x(), current.y() + 1,color.rgba());
                q.push(QPoint(current.x(), current.y() + 1));
            }
            if(current.x() - 1 >= 0  && (activeCanvas->pixelColor(current.x() - 1,current.y()) == removeColor))
            {
                activeCanvas->setPixel(current.x() - 1, current.y(),color.rgba());
                q.push(QPoint(current.x() - 1, current.y()));
            }
            if(current.x() + 1 < activeCanvas->width()  && (activeCanvas->pixelColor(current.x() + 1,current.y()) == removeColor))
            {
                activeCanvas->setPixel(current.x() + 1, current.y(),color.rgba());
                q.push(QPoint(current.x() + 1, current.y()));
            }
        }

    }


}
