#include "qwidgettoolbar.h"
#include <QDebug>
#include <QGraphicsView>
#include <QColorDialog>
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

    // Current button corresponds to a tool,
    //set up button paths sets the images at the array index of current button
    currentButton = 0;
    setUpButtonPaths();
    ToolButtons = new QButtonGroup();
    AddButtons(ToolButtons);
    AddColorButtons();

    // Sets up the slider box and connects it's value changed to update the tool
    int numOfTools = this->ToolButtons->buttons().length();
    QWidgetSliderCombo* sizeSlider = new QWidgetSliderCombo(this, "Size", 1, 32*numOfTools/2 + 25, this->width()-10, 64);
    connect(sizeSlider->Slider,SIGNAL(valueChanged(int)),this,SLOT(ChangeWidth(int)));
    connect(&currentTool, SIGNAL(SignalDefaultWidth(int)),sizeSlider->Slider,SLOT(setValue(int)));

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
    // Paints the icon on the button
    AddIcon(pb);
    pb->show();

    return pb;

}

/*
 * TODO
 */
//void QWidgetToolbar::paintEvent(QPaintEvent *e)
//{
//    int numOfTools = this->ToolButtons->buttons().length();

//    QPainter painter;
//    QPainterPath path;
//    path.addRoundRect(leftPadding, upPadding, 80, 16 + 32*(numOfTools / 2), 0);
//    path.addRoundRect(0,0,this->width()-1,this->height()-1,0);

//    QPen pen(Qt::lightGray, 10);
//    painter.setPen(pen);

//    painter.begin(this);
//        painter.drawPath(path);
//    painter.end();
//}

/*
 * TODO
 */
int QWidgetToolbar::getSize() {
    return 0;
    //return this->Slider->value();
}

void QWidgetToolbar::AddButtons(QButtonGroup *ToolButtons)
{
    QPushButton* paintBrushButton = createToolButton();
    ToolButtons->addButton(paintBrushButton);
    connect(paintBrushButton, SIGNAL(clicked(bool)),this,SLOT(RegisterPaintBrushButton()));


    QPushButton* broadBrushButton = createToolButton();
    ToolButtons->addButton(broadBrushButton);
    connect(broadBrushButton,SIGNAL(clicked(bool)),this,SLOT(RegisterBroadBrushButton()));

    QPushButton* dropperButton = createToolButton();
    ToolButtons->addButton(dropperButton);
    connect(dropperButton,SIGNAL(clicked(bool)),this,SLOT(RegisterDropperButton()));

    QPushButton* eraserButton = createToolButton();
    ToolButtons->addButton(eraserButton);
    connect(eraserButton,SIGNAL(clicked(bool)),this,SLOT(RegisterEraserButton()));
}

void QWidgetToolbar::AddColorButtons()
{
    primaryColorImage = new QImage(40,40,QImage::Format_ARGB32);
    QPushButton* primaryColorButton = new QPushButton("", this);
    connect(primaryColorButton,SIGNAL(clicked(bool)),this,SLOT(UpdatePrimary()));
    primaryColorButton->setMaximumSize(50,50);
    primaryColorButton->setMinimumSize(50,50);
    primaryColorButton->setText(QString(""));
    primaryColorButton->move(0, 200);

    primaryColorImage->fill(QColor(255, 160, 47));
    primaryColorButton->setIcon(QPixmap::fromImage(*primaryColorImage));
    primaryColorButton->setIconSize(QSize(35,35));

    // Paints the icon on the button
    //AddIcon(pb);
    primaryColorButton->show();

    ColorButtons[0] = primaryColorButton;

    secondaryColorImage = new QImage(40,40,QImage::Format_ARGB32);
    QPushButton* secondaryColorButton = new QPushButton("", this);
    connect(secondaryColorButton,SIGNAL(clicked(bool)),this,SLOT(UpdateSecondary()));

    secondaryColorButton->setMaximumSize(50,50);
    secondaryColorButton->setMinimumSize(50,50);
    secondaryColorButton->setText(QString(""));
    secondaryColorButton->move(30, 250);

    secondaryColorImage->fill(QColor(0, 0, 250));
    secondaryColorButton->setIcon(QPixmap::fromImage(*secondaryColorImage));
    secondaryColorButton->setIconSize(QSize(35,35));

    secondaryColorButton->show();

    ColorButtons[1] = secondaryColorButton;

    secondaryColorImage = new QImage(40,40,QImage::Format_ARGB32);
    QPushButton* swapColorButton = new QPushButton("", this);
    //connect(secondaryColorButton,SIGNAL(clicked(bool)),this,SLOT(UpdateSecondary()));

    swapColorButton->setMaximumSize(50,50);
    swapColorButton->setMinimumSize(50,50);
    swapColorButton->setText(QString(""));
    swapColorButton->move(30, 300);

    //swapColorButton->fill(QColor(0, 0, 250));
    swapColorButton->setIcon(QPixmap::fromImage(QImage(":/Images/Buttons/../../swapColorsSmall.png")));
    swapColorButton->setIconSize(QSize(35,35));

    secondaryColorButton->show();

    ColorButtons[2] = secondaryColorButton;
}

void QWidgetToolbar::AddIcon(QPushButton * pb)
{
    // Do fill bucket

    QPixmap bbMap(buttonPaths[currentButton]);
    QIcon brushIcon2(bbMap);
    pb->setIcon(brushIcon2);
    pb->setIconSize(QSize(15,15));

    buttons[currentButton] = pb;

    currentButton++;
}

void QWidgetToolbar::setUpButtonPaths()
{
    buttonPaths[0] = ":Images/Buttons/Resources/Images/paintBrush.png";
    buttonPaths[1] = ":Images/Buttons/Resources/Images/broadBrush.png";
    buttonPaths[2] = ":Images/Buttons/Resources/Images/dropper.png";
    buttonPaths[3] = ":Images/Buttons/Resources/Images/eraser.png";

    functionNames[0] = "BrushPushed";
}

void QWidgetToolbar::RegisterPaintBrushButton()
{
        qDebug() << "PaintBrush";
        currentButton = 0;
        currentTool.UpdateTool("paintBrushButton");
}

void QWidgetToolbar::RegisterBroadBrushButton()
{
        qDebug() << "BroadBrush";
        currentButton = 1;
        currentTool.UpdateTool("broadBrushButton");
}

void QWidgetToolbar::RegisterDropperButton()
{
    qDebug() <<"Dropper";
    currentButton = 2;
    // Need ot [ut dropper
    //currentTool.UpdateTool("");
}

void QWidgetToolbar::RegisterEraserButton()
{
    qDebug() <<"Eraser";
    currentButton = 3;
    currentTool.UpdateTool("eraserButton");
}

void QWidgetToolbar::ChangeWidth(int changedValue)
{
    //qDebug() << changedValue;
    currentTool.updateWidth(changedValue);

}

void QWidgetToolbar::ChooseColor(int sendersName)
{
    QColorDialog chooseColor;
    QColor chosenColor = chooseColor.getColor();

    if(chosenColor.isValid())
    {
        switch(sendersName)
        {
            case(1):
                primaryColorImage->fill(chosenColor);
                ColorButtons[0]->setIcon(QIcon(QPixmap::fromImage(*primaryColorImage)));
                currentTool.SetColor(chosenColor);
                break;
            case(2):
                secondaryColorImage->fill(chosenColor);
                ColorButtons[1]->setIcon(QIcon(QPixmap::fromImage(*secondaryColorImage)));
                currentTool.setSecondaryColor(chosenColor);
                break;
            default:
                break;
        }
    }


}

void QWidgetToolbar::UpdatePrimary()
{
    ChooseColor(1);
}

void QWidgetToolbar::UpdateSecondary()
{
    ChooseColor(2);
}

