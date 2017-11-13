#include "qwidgettoolbar.h"
#include <QDebug>
#include <QGraphicsView>
#include <QColorDialog>
#include "../Models/paintbrushtool.h"
/*
 *     TODO: Create custom buttons for tools, connect canvas and toolbar.
 */

/*
 *  Default constructor for QWidget Toolbar.
 */
QWidgetToolbar::QWidgetToolbar(QWidget *parent) : QWidget(parent)
{
    // Instantiates the tools and sets the default to the paintBrush
    paintBrush = new paintbrushTool;
    paintBrush->SetName("paintBrush");
    eraser = new Eraser;
    eraser->SetName("eraser");
    broadBrush = new BroadBrush;
    broadBrush->SetName("broadBrush");
    dropper = new Dropper;
    dropper->SetName("dropper");

    currentTool = paintBrush;
    primarySelectedColor = QColor(255,158,73);
    selectedWidth = 10;
    UpdateToolColor(primarySelectedColor);
    UpdateToolWidth(selectedWidth);

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

    int numOfTools = this->ToolButtons->buttons().length();
    sizeSlider = new QWidgetSliderCombo(this, "Size", 1, 32*numOfTools/2 + 25, this->width()-10, 64);
    connect(sizeSlider->Slider,SIGNAL(valueChanged(int)),this,SLOT(UpdateToolWidth(int)));
    sizeSlider->Slider->setValue(selectedWidth);

}

QWidgetToolbar::~QWidgetToolbar()
{
    delete paintBrush;
    delete eraser;
    delete broadBrush;
    //delete dropper;

    delete ToolButtons;
    delete primaryColorImage;
    delete secondaryColorImage;

    for(int i = 0; i < 4; i++)
    {
        delete buttons[i];
    }

    for(int i = 0; i < 3; i++)
    {
        delete ColorButtons[i];
    }
    delete sizeSlider;

}

// Gives the current tool
BaseToolClass *QWidgetToolbar::GetCurrentTool()
{
    return currentTool;
}


/*
 *  Create a button. TODO: ADD MORE SPECIFIC DOCUMENTATION.
 */
QPushButton* QWidgetToolbar::createToolButton() {

    // Users the number of tool buttons for spacing below
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
 * Returns width from the tool currently assigned
 */

int QWidgetToolbar::GetToolWidth() {
    return currentTool->GetWidth();
}

// Manually Creates the tool button's and hooks up their clicked events to corresponding slots
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

/*
 * Manaully creates primary and secondary color buttons, setting their initial values
 * and location within the widget
*/
void QWidgetToolbar::AddColorButtons()
{
    primaryColorImage = new QImage(40,40,QImage::Format_ARGB32);
    QPushButton* primaryColorButton = new QPushButton("", this);
    connect(primaryColorButton,SIGNAL(clicked(bool)),this,SLOT(UpdatePrimaryColorImage()));
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
    connect(secondaryColorButton,SIGNAL(clicked(bool)),this,SLOT(UpdateSecondaryColorImage()));

    secondaryColorButton->setMaximumSize(50,50);
    secondaryColorButton->setMinimumSize(50,50);
    secondaryColorButton->setText(QString(""));
    secondaryColorButton->move(30, 250);

    secondaryColorImage->fill(QColor(203,203,203));
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
    //swapColorButton->setIcon(QPixmap::fromImage(QImage(":/Images/Buttons/../../swapColorsSmall.png")));
    swapColorButton->setIconSize(QSize(35,35));

    swapColorButton->show();

    ColorButtons[2] = swapColorButton;
}

/*
 * Incrementally adds Icons to the buttons
 *
 */
void QWidgetToolbar::AddIcon(QPushButton * pb)
{
    // Do fill bucket

    QPixmap buttonPixMap(buttonPaths[currentButton]);
    QIcon brushIcon(buttonPixMap);
    pb->setIcon(brushIcon);
    pb->setIconSize(QSize(15,15));

    buttons[currentButton] = pb;

    currentButton++;
}

// Puts the images files from the resource into an array to be use for icons
void QWidgetToolbar::setUpButtonPaths()
{
    buttonPaths[0] = ":Images/Buttons/Resources/Images/paintBrush.png";
    buttonPaths[1] = ":Images/Buttons/Resources/Images/broadBrush.png";
    buttonPaths[2] = ":Images/Buttons/Resources/Images/dropper.png";
    buttonPaths[3] = ":Images/Buttons/Resources/Images/eraser.png";
}

/*
* Registers the PaintBrush as the current tool, updating the color and width accordingly
*/
void QWidgetToolbar::RegisterPaintBrushButton()
{
        qDebug() << "PaintBrush";
        // Figure out a way to keep track visually of which button is clicked <------
        currentButton = 0;

        currentTool = paintBrush;
        UpdateToolColor(primarySelectedColor);
        UpdateToolWidth(sizeSlider->Slider->value());

        ToggleColorButtons();
}

/*
* Registers the BroadBrush as the current tool, updating the color and width accordingly
*/
void QWidgetToolbar::RegisterBroadBrushButton()
{
        qDebug() << "BroadBrush";
        currentButton = 1;
        currentTool = broadBrush;

        UpdateToolColor(primarySelectedColor);
        UpdateToolWidth(sizeSlider->Slider->value());

        ToggleColorButtons();
}

/*
* Registers the dropper as the current tool, updating the color and width accordingly
*/
void QWidgetToolbar::RegisterDropperButton()
{
    currentButton = 2;

    UpdateToolColor(primarySelectedColor);
    UpdateToolWidth(sizeSlider->Slider->value());

    ToggleColorButtons();
    ColorButtons[0]->setEnabled(false);
    ColorButtons[1]->setEnabled(false);
}

/*
* Registers the eraser as the current tool, updating the color and width accordingly
*/
void QWidgetToolbar::RegisterEraserButton()
{
    currentButton = 3;
    currentTool = eraser;
    currentTool->SetColor(QColor(203,203,203));
    currentTool->SetWidth(sizeSlider->Slider->value());
    ColorButtons[0]->setEnabled(false);
    ColorButtons[1]->setEnabled(false);
}

/*
 * Launches dialog box to pick a color. Updates the current color and image for primary or
 * secondary color accordingly
 *
*/
bool QWidgetToolbar::UpdateColorPrimaryColor()
{
    // Launches choose color Dialog box
    QColorDialog chooseColor;
    QColor chosenColor = chooseColor.getColor();

    // Validates whether the user picked a color
    if(chosenColor.isValid())
    {
        primarySelectedColor = chosenColor;

        UpdateToolColor(primarySelectedColor);
        UpdateToolWidth(sizeSlider->Slider->value());

        return true;
    }
    return false;

}

bool QWidgetToolbar::UpdateSecondaryColor()
{
    // Launches choose color Dialog box
    QColorDialog chooseColor;
    QColor chosenColor = chooseColor.getColor();

    // Validates whether the user picked a color
    if(chosenColor.isValid())
    {
        secondarySelectedColor = chosenColor;
        return true;
    }
    return false;
}

// Launches a choosecolor Dialog sending which button pressed it
void QWidgetToolbar::UpdatePrimaryColorImage()
{
    if(UpdateColorPrimaryColor())
    {
        primaryColorImage->fill(primarySelectedColor);
        ColorButtons[0]->setIcon(QIcon(QPixmap::fromImage(*primaryColorImage)));
    }
}

// When the secondary color is pressed it updates the secondary color and image
void QWidgetToolbar::UpdateSecondaryColorImage()
{
    if(UpdateSecondaryColor())
    {
        secondaryColorImage->fill(secondarySelectedColor);
        ColorButtons[1]->setIcon(QIcon(QPixmap::fromImage(*secondaryColorImage)));
    }
}

// Emits a signal that holds the currently selected tool
void QWidgetToolbar::CurrentToolRequested()
{
    emit SendCurrentTool(currentTool);
}


// Updates the tools Color from what the dropper returned
void QWidgetToolbar::UpdateDropperReturn(QColor dropperColor)
{
    primarySelectedColor = dropperColor;
    UpdatePrimaryColorImage();
}

// Updates the tools color
void QWidgetToolbar::UpdateToolColor(QColor color)
{
    currentTool->SetColor(color);
}

//updates the tools width
void QWidgetToolbar::UpdateToolWidth(int width)
{
    currentTool->SetWidth(width);
}

// Disables the colors buttons when the dropper and eraser is selected
void QWidgetToolbar::ToggleColorButtons()
{
    if(ColorButtons[0]->isEnabled() == false && ColorButtons[1]->isEnabled() ==false)
    {
        ColorButtons[0]->setEnabled(true);
        ColorButtons[1]->setEnabled(true);
    }

}
