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
    activeStatus = false;
    timer.start(1000,this);
    imagesPos = 0;
    currentImage = nullptr;
    scale = 1.0;
    label = new QLabel;
    previewDialog.setWindowTitle("Preview Sprite");


}

/*
 *  Sets a new image to be displayed and updates the display.
 */
void QWidgetPreview::setCurrentImage(QImage *image)
{
    currentImage = image;
    label->setPixmap(QPixmap::fromImage(*image));
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
 * Changes the activeStatus and emits back the current status
 */
void QWidgetPreview::setActiveStatus()
{
    if(activeStatus == true)
        activeStatus = false;
    else
        activeStatus = true;

    emit activityStatus(activeStatus);
}
/*
 * Shows dialog window of actual size sprite preview
 */
void QWidgetPreview::fullPreview()
{ 
    QFormLayout form(&previewDialog);
    form.addWidget(label);
    previewDialog.show();
}

/*
 *  Event for displaying preview widget and current image if exists.
 */
void QWidgetPreview::paintEvent(QPaintEvent *event) {


    QPainter painter(this);
    painter.scale(scale,scale);
    QPainterPath path;
    path.addRoundRect(0,0,this->width()-1,this->height()-1,0);
    QPen pen(Qt::lightGray, 1);
    painter.setPen(pen);
    painter.begin(this);

    if(currentImage != nullptr)
            painter.drawImage(rect(), *currentImage, currentImage->rect());

    painter.drawPath(path);

    painter.end();
    QWidget::paintEvent(event);
}


/*
 *  Event for updating display image for every given time interval.
 */
void QWidgetPreview::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer.timerId() && images.count() > 0 && activeStatus == true)
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




