#include "qwidgetcanvas.h"

/*
 *  Default Constructor for the QWidgetCanvas
 */
QWidgetCanvas::QWidgetCanvas(QWidget *parent) : QWidget(parent)
{
    this->activeCanvas = nullptr;
    this->currentScale = 1.0;
    this->transparentBackground = nullptr;

    this->setMinimumSize(imageHeight * currentScale, imageWidth * currentScale);
    this->setMaximumSize(imageHeight * currentScale, imageWidth * currentScale);

    emit sendImages(this->getAllCompositeImages());
}

/*
 *  Deconstructor for the QWidgetCanvas to free memory
 */
QWidgetCanvas::~QWidgetCanvas()
{
    foreach (Canvas* c, composites)
    {
        delete c;
    }
}

/*
 *  Returns active drawing canvas.
 */
Canvas* QWidgetCanvas::getActiveCanvas()
{
    return this->activeCanvas;
}

/*
 *  Returns image of active drawing canvas.
 */
QImage* QWidgetCanvas::getActiveCanvasImage()
{
    if (this->activeCanvas != nullptr && this->activeCanvas->GetImage() != nullptr)
        return this->activeCanvas->GetImage();
    else
        return nullptr;
}

/*
 *  Returns a vector of QImages from the composite of canvas.
 */
QVector<QImage*> QWidgetCanvas::getAllCompositeImages()
{
    QVector<QImage*> canvasImages;
    foreach (Canvas* c, this->composites)
    {
        if (c != nullptr)
            canvasImages.push_back(c->GetImage());
    }

    // TODO: EXCEPTION CATCH FOR EMPTY VECTORS
    //if (canvasImages.count() == 0)


    return canvasImages;
}

/*
 *  Adds a new copied canvas to the composite.
 */
void QWidgetCanvas::addCanvas(QSize size)
{
    if (activeCanvas != nullptr)
        this->activeCanvas = new Canvas(*activeCanvas);
    else
        this->activeCanvas = new Canvas(size.width(), size.height());

    this->composites.push_back(this->activeCanvas);

    emit sendImages(this->getAllCompositeImages());
}

/*
 *  Validates that the mouse click is within the canvas
 *  Executes the currect tool's mouse press event.
 */
void QWidgetCanvas::drawLineTo(const QPoint &endPoint)
{
    if(endPoint.x() >= 0 && endPoint.x() < this->getActiveCanvasImage()->width() && endPoint.y() >= 0 && endPoint.y() < this->getActiveCanvasImage()->height())
    {

        emit grabTool();
        if(selectedTool != nullptr)
        {
            if (QString::compare(selectedTool->name,"mouse") == 0)
            {
                //qDebug() << "mouse";
            }
            else if (QString::compare(selectedTool->name,"dropper") == 0)
            {
                //qDebug() << "null painter";
                emit returnDropperColor(this->getActiveCanvasImage()->pixelColor(endPoint));
            }
            else
                selectedTool->paint(this->getActiveCanvasImage(),endPoint);

            update();
        }
    }
}

/*
 *  Triggered every tick, paints the canvas image on the Widget.
 */
void QWidgetCanvas::paintEvent(QPaintEvent *event)
{

        // Asks the ui to update the SelectedTool
        emit requestCurrentTool();

        QPainter painter(this);
        QRect dirtyRect = this->rect();

        if (transparentBackground != nullptr && this->getAllCompositeImages().size() != 0)
        {
            painter.drawImage(dirtyRect, *transparentBackground);
        }
        if (getActiveCanvasImage() != nullptr)
        {
            painter.drawImage(dirtyRect, *getActiveCanvasImage());
        }

        QPainterPath path;
        QPen pen(Qt::lightGray, 1);
        painter.setPen(pen);
        painter.drawRect(0,0,this->width()-1, this->height()-1);
        painter.drawPath(path);

        QWidget::paintEvent(event);
}

/*
 *  Method for changing the active cavas to a different canvas
 */
void QWidgetCanvas::setActiveCanvas(Canvas * can)
{
    this->activeCanvas = can;
    update();
}

/*
 *  Event handler for event of mouse moved
 */
void QWidgetCanvas::mouseMoveEvent(QMouseEvent *event)
{
    if (this->mouseDown && this->getActiveCanvasImage() != nullptr)
    {
        drawLineTo(event->pos()/currentScale);
    }
}

/*
 *  Event handler for event of mouse pressed
 */
void QWidgetCanvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton&& this->getActiveCanvasImage() != nullptr)
    {
        this->mouseDown = true;
        drawLineTo(event->pos()/currentScale);
    }
}

/*
 *  Event handler for event of mouse released
 */
void QWidgetCanvas::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        this->mouseDown = false;
        emit ImageUpdate(getActiveCanvasImage(), this->composites.indexOf(getActiveCanvas(),0));
    }

}


/*
 * TODO::
 * Slot to recieve the current tool
 */
void QWidgetCanvas::currentTool(BaseToolClass * tool)
{
    selectedTool = tool;
}

/*
 *  Function for adding new canvases
 */
void QWidgetCanvas::addCanvas()
{
    this->activeCanvas = new Canvas(imageWidth, imageHeight);
    this->composites.push_back(this->activeCanvas);
    emit sendImages(this->getAllCompositeImages());
}

/*
 *  Method used add canves and load given image onto canvas
 */
void QWidgetCanvas::addCanvas(QImage* im)
{
    if (im != nullptr)
    {
        this->activeCanvas = new Canvas(this->imageWidth, this->imageHeight);
        activeCanvas->LoadImage(im);
    }

    this->composites.push_back(this->activeCanvas);

    emit sendImages(this->getAllCompositeImages());
}

/*
 * Shifts current scale using given scale
 */
void QWidgetCanvas::shiftScale(double scale)
{
    this->setScale(this->currentScale + scale);
}

/*
 * Sets and adjusts canvas according to scale
 */
void QWidgetCanvas::setScale(double scale)
{
    this->currentScale = scale;

    int widthScaled = imageWidth * scale;
    int heightScaled = imageHeight * scale;

    this->setFixedSize(widthScaled, heightScaled);

    delete this->transparentBackground;

    this->transparentBackground = new QImage(QSize(widthScaled, heightScaled), QImage::Format_ARGB32);
    this->transparentBackground->fill(QColor(255,255,255));

    QPainter painter(transparentBackground);

    int offset = 0;

    for (int row = 0; row <= widthScaled/4; row++)
    {
        for (int col = 0; col <= heightScaled/4; col += 2)
        {

            bool swap = false;

            QRect rect = QRect(col*widthScaled/8 + offset,row*heightScaled/8,widthScaled/8,heightScaled/8);
            painter.fillRect(rect, QColor(155, 155, 155, 255));


        }
        if (offset <= 0)
            offset += widthScaled/8;
        else
            offset = 0;

    }

    update();

}

/*
 *  Method to clear Canvas Widget
 */
void QWidgetCanvas::clear()
{
    activeCanvas = nullptr;
    this->currentScale = 1.0;
    this->transparentBackground = nullptr;


    foreach (auto canvasPtr, composites)
    {
        delete canvasPtr;
    }
    composites.clear();
}

/*
 *  Method for resizing canvas, zoom feature
 */
void QWidgetCanvas::resize(int width, int height, double scale)
{
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setFixedSize(width, height);
    this->imageHeight = height;
    this->imageWidth = width;
    this->setScale(scale);
};
