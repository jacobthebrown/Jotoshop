#include "canvas.h"

Canvas::Canvas(int width, int height)
{
    this->CanvasImage = new QImage(QSize(width, height), QImage::Format_ARGB32);
    this->CanvasImage->fill(QColor(203,203,203));
}

Canvas::Canvas(int width, int height)
{
    this->CanvasImage = new QImage(QSize(width, height), QImage::Format_ARGB32);
    this->CanvasImage->fill(QColor(203,203,203));
}

/*
 * Copy constructor
 */
Canvas::Canvas(const Canvas& other)
{
    this->CanvasImage = new QImage(other.CanvasImage->size(), QImage::Format_ARGB32);
    *this->CanvasImage = *(other.CanvasImage);
    //this->CanvasImage = new QImage(QSize(512, 512), QImage::Format_ARGB32);
    //this->CanvasImage->fill(QColor(203,203,203));
    //*(this->CanvasImage) = other.GetImage()->copy(0,0,other.GetImage()->width(),other.GetImage()->height() );
}

Canvas::~Canvas()
{

}

QImage* Canvas::GetImage() const
{
    // TODO: THROW EXCEPTION
    if (this->CanvasImage != nullptr)
        return this->CanvasImage;
    else
        return nullptr;

}

void Canvas::LoadImage(QImage* im)
{
    this->CanvasImage = im;
}
