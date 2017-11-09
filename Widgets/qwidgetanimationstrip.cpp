#include "qwidgetanimationstrip.h"
#include <QDebug>



QWidgetAnimationStrip::QWidgetAnimationStrip(QWidget *parent) : QWidget(parent)
{

    QHBoxLayout* layout = new QHBoxLayout;
    layout->setMargin(3);
    this->setMaximumHeight(128);

    //QLabel* label = new QLabel("kk", this);
    //label->setMinimumSize(200, 200);

    listArea = new QListWidget;
    listArea->setViewMode(QListWidget::IconMode);
    //scrollArea = new QScrollArea(this);

    //scrollArea->move(0,0);
    listArea->setMinimumSize(this->width(),this->height());
    listArea->setIconSize(QSize(80,80));
    listArea->setResizeMode(QListWidget::Adjust);
    listArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    listArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //listArea->addItem(new QListWidgetItem(QIcon(":/Images/Buttons/Resources/Images/dropper.png"),"Earth"));//scrollArea->addScrollBarWidget(label, Qt::AlignLeft);
    listArea->show();

    layout->addWidget(listArea);
    this->setLayout(layout);

    //Connected clicked icon event to handler
    connect(listArea, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(canvasClicked(QListWidgetItem*)));

}
/*
 * Slot for adding a widget to the animation strip.
 */
void QWidgetAnimationStrip::addQImage(QPixmap pix, QString framePos)
{

    listArea->addItem(new QListWidgetItem(QIcon(pix),framePos));

}

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
}

// when icon is clicked return that icons position
void QWidgetAnimationStrip::canvasClicked(QListWidgetItem *item)
{
    qDebug() << "hhh";
    emit sendClickedCanvas(item);
}
