#include "qwidgettoolbar.h"
/*
 *     TODO: Create custom buttons for tools, connect canvas and toolbar.
 */

/*
 *  Default constructor for QWidget Toolbar.
 */
QWidgetToolbar::QWidgetToolbar(QWidget *parent) : QWidget(parent)
{

    // Styling for the border and placement of children QObjects.
    this->leftPadding = 8;
    this->upPadding = 8;
    this->rightPadding = 8;
    this->bottomPadding = 8;

    // Create abunch of place holder tool buttons for the future.
    ToolButtons = new QButtonGroup();
    for(int i = 0; i < 10; i++) {
        ToolButtons->addButton(createToolButton());
    }

    // Create slider underneath buttons.
    int numOfTools = this->ToolButtons->buttons().length();
    QWidgetSliderCombo* sizeSlider = new QWidgetSliderCombo(this, "Size", 1, 32*numOfTools/2 + 25, this->width()-10, 64);

}

/*
 *  Create a button. TODO: ADD MORE SPECIFIC DOCUMENTATION.
 */
QPushButton* QWidgetToolbar::createToolButton() {

    int numOfTools = this->ToolButtons->buttons().length();

    QPushButton* pb = new QPushButton("button", this);
    pb->setMaximumSize(32,32);
    pb->setMinimumSize(32,32);
    pb->setText(QString(""));
    pb->move(leftPadding + 8 + 32*(numOfTools % 2), upPadding + 8 + 32*(numOfTools / 2));
    pb->show();

    return pb;

}

/*
 * TODO
 */
void QWidgetToolbar::paintEvent(QPaintEvent *e)
{
    int numOfTools = this->ToolButtons->buttons().length();

    QPainter painter;
    QPainterPath path;
    path.addRoundRect(leftPadding, upPadding, 80, 16 + 32*(numOfTools / 2), 0);
    path.addRoundRect(0,0,this->width()-1,this->height()-1,0);

    QPen pen(Qt::lightGray, 10);
    painter.setPen(pen);

    painter.begin(this);
        painter.drawPath(path);
    painter.end();
}

/*
 * TODO
 */
int QWidgetToolbar::getSize() {
    return 0;
    //return this->Slider->value();
}
