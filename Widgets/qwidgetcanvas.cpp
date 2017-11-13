#include "qwidgetcanvas.h"

/*
 *  Default Constructor for the QWidgetCanvas
 */
QWidgetCanvas::QWidgetCanvas(QWidget *parent) : QWidget(parent)
{
    this->ActiveCanvas = nullptr;
    //this->ActiveCanvas = new Canvas();
    //this->composites.push_front(ActiveCanvas);
    this->CurrentScale = 1.0;

    // TODO: CHANGE TO SIZE SETTINGS
    this->imageHeight = 512;
    this->imageWidth = 512;

    emit sendImages(this->getAllCompositeImages());
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
    foreach (Canvas* c, this->composites) {
        if (c != nullptr)
            canvasImages.push_back(c->GetImage());
    }

    // TODO: EXCEPTION CATCH FOR EMPTY VECTORS
    //if ()

    return canvasImages;
}

/*
 *  Adds a new copied canvas to the composite.
 */
void QWidgetCanvas::addCanvas()
{

    if (ActiveCanvas != nullptr)
        this->ActiveCanvas = new Canvas(*ActiveCanvas);
    else
        this->ActiveCanvas = new Canvas(this->imageWidth, this->imageHeight);

    this->composites.push_back(this->ActiveCanvas);

    emit sendImages(this->getAllCompositeImages());
}

/*
 *  Executes the currect tool's mouse press event.
 *  TODO: Refactor to be a generic drawing event for Tool object.
 */
void QWidgetCanvas::drawLineTo(const QPoint &endPoint)
{

        QPainter painter(this);

        emit RequestCurrentTool();
        if (selectedTool->name == "dropper")
        {

        }
        else
            selectedTool->Paint(this->getActiveCanvasImage(),endPoint);
//        if (this->getActiveCanvas() == nullptr)
//            return;

        painter.setPen(QPen(QColor("orange"), 10, Qt::SolidLine, Qt::RoundCap,
                            Qt::RoundJoin));
        painter.drawPoint(endPoint);

        update();


}

/*
 *  Triggered every tick, paints the canvas image on the Widget.
 */
void QWidgetCanvas::paintEvent(QPaintEvent *event) {

    // Asks the ui to update the SelectedTool
        emit RequestCurrentTool();

        QPainter painter(this);
        QRect dirtyRect = event->rect();

        painter.scale(CurrentScale, CurrentScale);

        if (getActiveCanvasImage() != nullptr)
            painter.drawImage(dirtyRect, *getActiveCanvasImage(), dirtyRect);

        QWidget::paintEvent(event);
}

//
void QWidgetCanvas::setActiveCanvas(Canvas * can)
{
    this->ActiveCanvas = can;
    update();
}


/*
 *  TODO: Comment, refactor to make generic execution.
 */
void QWidgetCanvas::mouseMoveEvent(QMouseEvent *event)
{
    if (this->MouseDown) {
        drawLineTo(this->mapFromGlobal(event->globalPos()));
    }
}

/*
 *  TODO: Refactor to remove boolean, and refactor for more mouse types.
 */
void QWidgetCanvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        this->MouseDown = true;
    }
}

/*
 *  TODO: See mousePressEvent todo.
 */
void QWidgetCanvas::mouseReleaseEvent(QMouseEvent* event) {

    if (event->button() == Qt::LeftButton) {
        this->MouseDown = false;
        emit ImageUpdate(getActiveCanvasImage(), this->composites.indexOf(getActiveCanvas(),0));
    }

}

void QWidgetCanvas::load(QImage* im)
{
    addCanvas(im);
}

// Updates the Tool
void QWidgetCanvas::RecieveTool(BaseToolClass* tool)
{
    selectedTool = tool;
}

/*
 *  This function is used to load images onto canvases
 */
void QWidgetCanvas::addCanvas(QImage* im)
{
    if (ActiveCanvas != nullptr)
        this->ActiveCanvas = new Canvas(*ActiveCanvas);
    else
        this->ActiveCanvas = new Canvas(this->imageWidth, this->imageHeight);

    //this->ActiveCanvas->LoadImage(im);

    this->composites.push_back(this->ActiveCanvas);

    emit sendImages(this->getAllCompositeImages());
}
