#include "canvas.h"

Canvas::Canvas()
{
    this->CanvasImage = new QImage(QSize(512, 512), QImage::Format_ARGB32);
}

Canvas::~Canvas()
{
}

QImage* Canvas::GetImage()
{
    return this->CanvasImage;
}

