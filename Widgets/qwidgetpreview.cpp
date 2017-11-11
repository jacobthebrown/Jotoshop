#include "qwidgetpreview.h"
#include <QDebug>
/*
 *  Prview widget allows for the animation of qimages.
 *  The current displayed image is initialized to nullptr
 *  and the image position counter is initialzied to 0
 *  and starts timer at 15 fps.
 */
QWidgetPreview::QWidgetPreview(QWidget *parent) : QWidget(parent)
{
    timer.start(1000,this);
    imagesPos = 0;
    currentImage = nullptr;
}

/*
 *  Sets a new image to be displayed and updates the display.
 */
void QWidgetPreview::setCurrentImage(QImage *image)
{
    currentImage = image;
    repaint();

}

/*
 *  Method for setting current list of images.
 */
void QWidgetPreview::setImages(QVector<QImage *> im)
{
    images = im;
}

/*
 *  Sets the FPS play speed of image display.
 */
void QWidgetPreview::setSpeed(int speed)
{
    fps = 1000/speed;
    timer.start(fps, this);
}

/*
 *  Event for displaying preview widget and current image if exists.
 */
void QWidgetPreview::paintEvent(QPaintEvent *event) {


    QPainter painter(this);

    if(currentImage != nullptr)
        painter.drawImage(rect(), *currentImage, currentImage->rect());

    QWidget::paintEvent(event);


}


/*
 *  Event for updating display image for every given time interval.
 */
void QWidgetPreview::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer.timerId() && images.count() > 0)
    {
        imagesPos++;
        if(imagesPos >= images.count())
            imagesPos = 0;
        setCurrentImage(images.at(imagesPos));
        update();
    }
    else
        QWidget::timerEvent(event);
}


