#include "canvas.h"

/*
 * Creates a new canvas of a given size. A Canvas will display an editable QImage upon which the user
 * can take various actions, such as erasing, drawing, filling, etc.
 */
Canvas::Canvas(int width, int height)
{
    // Creates a new QImage of the specified height and width
    this->CanvasImage = new QImage(QSize(width, height), QImage::Format_ARGB32);

    // Fills the background of the canvas with the checkered transparent pattern
    this->CanvasImage->fill(QColor(0,0,0,0));

    // Represents the size of this canvas object
    canvasSize = QSize(width, height);
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

/*
 * Destructor
 */
Canvas::~Canvas()
{
    delete CanvasImage;
}

/*
 * Returns a QImage* object representing the state of the current canvas draw space
 */
QImage* Canvas::GetImage() const
{
    if (this->CanvasImage != nullptr)
        return this->CanvasImage;
    else
        return nullptr;

}

/*
 * Loads a QImage* into this Canvas object
 */
void Canvas::LoadImage(QImage* im)
{
    this->CanvasImage = new QImage(im->copy());
}
