#include "qwidgetcanvas.h"

/*
 *  Default Constructor for the QWidgetCanvas
 */
QWidgetCanvas::QWidgetCanvas(QWidget *parent) : QWidget(parent)
{
    this->ActiveCanvas = nullptr;
    this->CurrentScale = 1.0;
    this->transparentBackground = nullptr;

    this->selectedTool = new paintbrushTool();
    this->selectedTool->SetWidth(5);
    this->setMinimumSize(imageHeight * CurrentScale, imageWidth * CurrentScale);
    this->setMaximumSize(imageHeight * CurrentScale, imageWidth * CurrentScale);

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
    return this->ActiveCanvas;
}

/*
 *  Returns image of active drawing canvas.
 */
QImage* QWidgetCanvas::getActiveCanvasImage()
{
    if (this->ActiveCanvas != nullptr && this->ActiveCanvas->GetImage() != nullptr)
        return this->ActiveCanvas->GetImage();
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
    if (ActiveCanvas != nullptr)
        this->ActiveCanvas = new Canvas(*ActiveCanvas);
    else
        this->ActiveCanvas = new Canvas(size.width(), size.height());

    this->composites.push_back(this->ActiveCanvas);

    emit sendImages(this->getAllCompositeImages());
}

/*
 *  Executes the currect tool's mouse press event.
 *  TODO: Refactor to be a generic drawing event for Tool object.
 */
void QWidgetCanvas::drawLineTo(const QPoint &endPoint)
{

        //QPainter painter(getActiveCanvasImage());

        emit GrabTool();
        //emit RequestCurrentTool();
        if (QString::compare(selectedTool->name,"mouse") == 0)
        {
            qDebug() << "mouse";
        }
        else if (QString::compare(selectedTool->name,"dropper") == 0)
        {
            qDebug() << "null painter";
            emit ReturnDropperColor(this->getActiveCanvasImage()->pixelColor(endPoint));
        }
        else
            selectedTool->Paint(this->getActiveCanvasImage(),endPoint);

        //painter.setPen(QPen(QColor("orange"), 10, Qt::SolidLine, Qt::RoundCap,
        //                    Qt::RoundJoin));
        //painter.drawPoint(endPoint);

        update();
}

/*
 *  Triggered every tick, paints the canvas image on the Widget.
 */
void QWidgetCanvas::paintEvent(QPaintEvent *event)
{

        // Asks the ui to update the SelectedTool
        emit RequestCurrentTool();

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
    this->ActiveCanvas = can;
    update();
}

/*
 *  Event handler for event of mouse moved
 */
void QWidgetCanvas::mouseMoveEvent(QMouseEvent *event)
{
    if (this->MouseDown)
    {
        drawLineTo(event->pos()/CurrentScale);
    }
}

/*
 *  Event handler for event of mouse pressed
 */
void QWidgetCanvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        this->MouseDown = true;
        drawLineTo(event->pos()/CurrentScale);
    }
}

/*
 *  Event handler for event of mouse released
 */
void QWidgetCanvas::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        this->MouseDown = false;
        emit ImageUpdate(getActiveCanvasImage(), this->composites.indexOf(getActiveCanvas(),0));
    }

}

/*
 *  Updates selected tool
 */
void QWidgetCanvas::RecieveTool(BaseToolClass* tool)
{
    selectedTool = tool;
}

/*
 * TODO::
 * GAITLAN whats the diff between this and the one above??
 */
void QWidgetCanvas::CurrentTool(BaseToolClass * tool)
{
    selectedTool = tool;
}

/*
 *  Function for adding new canvases
 */
void QWidgetCanvas::addCanvas()
{
    this->ActiveCanvas = new Canvas(imageWidth, imageHeight);
    this->composites.push_back(this->ActiveCanvas);
    emit sendImages(this->getAllCompositeImages());
}

/*
 *  Method used add canves and load given image onto canvas
 */
void QWidgetCanvas::addCanvas(QImage* im)
{
    if (im != nullptr)
    {
        this->ActiveCanvas = new Canvas(this->imageWidth, this->imageHeight);
        ActiveCanvas->LoadImage(im);
    }

    this->composites.push_back(this->ActiveCanvas);

    emit sendImages(this->getAllCompositeImages());
}

/*
 * Shifts current scale using given scale
 */
void QWidgetCanvas::shiftScale(double scale)
{
    this->setScale(this->CurrentScale + scale);
}

/*
 * Sets and adjusts canvas according to scale
 */
void QWidgetCanvas::setScale(double scale)
{
    this->CurrentScale = scale;

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
    ActiveCanvas = nullptr;
    this->CurrentScale = 1.0;
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
