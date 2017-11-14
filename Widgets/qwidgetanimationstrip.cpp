#include "qwidgetanimationstrip.h"
#include <QDebug>


/*
 * Constructs new Animation Strip widget
 */
QWidgetAnimationStrip::QWidgetAnimationStrip(QWidget *parent) : QWidget(parent)
{

    QHBoxLayout* layout = new QHBoxLayout;
    layout->setMargin(3);
    this->setMaximumHeight(128);

    listArea = new QListWidget;
    listArea->setMovement(QListView::Static);
    listArea->setViewMode(QListWidget::IconMode);

    listArea->setMinimumSize(this->width(),this->height());
    listArea->setIconSize(QSize(80,80));
    listArea->setResizeMode(QListWidget::Adjust);
    listArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    listArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    listArea->show();

    layout->addWidget(listArea);
    this->setLayout(layout);

    connect(listArea, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(canvasClicked(QListWidgetItem*)));
}
/*
 * Destructor to free memory
 */
QWidgetAnimationStrip::~QWidgetAnimationStrip()
{
    for(int i=0; i<listArea->count(); i++)
    {
        delete listArea->item(i);
    }
    delete listArea;
    delete this->layout();
}

/*
 * Slot for adding/updating a widget to the animation strip.
 */
void QWidgetAnimationStrip::addQImage(QPixmap pix, int framePos)
{

    // Draws a rectangle around item image.
    QPainter painter(&pix);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.drawRect(0,0,pix.width() - 1, pix.height() - 1);
    painter.end();

    // if item exists, update
    if(listArea->item(framePos) != 0)
    {
        listArea->item(framePos)->operator =(QListWidgetItem(QIcon(pix),QString::number(framePos)));
    }
    else
    {
        QListWidgetItem* items = new QListWidgetItem(QIcon(pix),QString::number(framePos));
        animationPreviewItems.push_back(items);
        listArea->addItem(items);
    }
    update();
}

/*
 * Clear the Animation Strip of frames
 */
void QWidgetAnimationStrip::clear()
{
    for(int i=0; i<listArea->count(); i++)
    {
        delete listArea->item(i);
    }

    animationPreviewItems.clear();
    listArea->clear();
    update();
}

/*
 * Event handler for drawing out animation strip
 */
void QWidgetAnimationStrip::paintEvent(QPaintEvent *e)
{

    QPainter painter;
    QPainterPath path;
    path.addRoundRect(0,0,this->width()-1,this->height()-1,0);

    QPen pen(Qt::lightGray, 10);
    painter.setPen(pen);

    painter.begin(this);
    painter.drawPath(path);
    painter.end();
    QWidget::paintEvent(e);
}

/*
 * When icon is clicked return that icons position
 */
void QWidgetAnimationStrip::canvasClicked(QListWidgetItem *item)
{
    emit sendClickedCanvas(item);
}

/*
 * Method for reflecting changes to animation strip icons
 */
void QWidgetAnimationStrip::refreshImage(QImage * targetImage, int position)
{


    // if item exists, update
    if(listArea->item(position) != 0)
    {

        // Draws rectangle around image icon.
        QImage cloneImage = targetImage->copy();
        QPainter painter(&cloneImage);
        QPen pen;
        pen.setWidth(1);
        pen.setColor(Qt::black);
        painter.setPen(pen);
        painter.drawRect(0,0,cloneImage.width() - 1, cloneImage.height() - 1);
        painter.end();

        listArea->item(position)->operator =(QListWidgetItem(QIcon(QPixmap::fromImage(cloneImage)),QString::number(position)));
        listArea->update();
    }
}
