#include "canvas.h"

Canvas::Canvas()
{
    this->CanvasImage = new QImage(QSize(512, 512), QImage::Format_ARGB32);
    this->CanvasImage->fill(QColor(100,100,100));
}
/*
 * Copy constructor
 */
Canvas::Canvas(const Canvas& other)
{
    this->CanvasImage = new QImage(QSize(512, 512), QImage::Format_ARGB32);
    *this->CanvasImage = *(other.CanvasImage);
}

Canvas::~Canvas()
{
}

QImage* Canvas::GetImage()
{
    return this->CanvasImage;
}

