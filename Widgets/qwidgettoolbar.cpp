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
    // Set The Initial tools and state of the tool bar
    setInitialState();

    setButtonPadding();

    // Current button corresponds to a tool index for image getting and setting,
    //set up button paths sets the images at the array index of current button
    currentButtonIndex = 0;
    setUpUnclickedButtonPaths();
    addButtons();
    addColorButtons();

    createSlider();
    connect(sizeSlider->Slider,SIGNAL(valueChanged(int)),this,SLOT(updateToolWidth(int)));


}

/*
 *  Deletes every object that was made new
 */
QWidgetToolbar::~QWidgetToolbar()
{
    delete toolButtons;
    delete primaryColorImage;
    delete secondaryColorImage;

    for(int i = 0; i < 4; i++)
    {
        delete buttons[i];
    }

    for(int i = 0; i < 3; i++)
    {
        delete colorButtons[i];
    }
    delete sizeSlider;

}

/*
 *  Gives the current tool pointer to caller
 */
BaseToolClass *QWidgetToolbar::getCurrentTool()
{
    return currentTool;
}


/*
 *  Create a button for the toolBar button group.
 */
QPushButton* QWidgetToolbar::createToolButton() {

    // Users the number of tool buttons for spacing below
    int numOfTools = this->toolButtons->buttons().length();

    QPushButton* pb = new QPushButton("button", this);
    pb->setMaximumSize(32,32);
    pb->setMinimumSize(32,32);
    pb->setText(QString(""));
    pb->move(leftPadding + 8 + 32*(numOfTools % 2), upPadding + 8 + 32*(numOfTools / 2));
    // Paints the icon on the button
    addIcon(pb);

    pb->show();
    return pb;

}


/*
 * Returns width from the tool currently assigned
 */
int QWidgetToolbar::getToolWidth()
{
    return currentTool->getWidth();
}

/*
 * Manually Creates the tool button's and hooks up their clicked events to corresponding slots
 */
void QWidgetToolbar::addButtons()
{
    toolButtons = new QButtonGroup();

    QPushButton* paintBrushButton = createToolButton();
    toolButtons->addButton(paintBrushButton);
    connect(paintBrushButton, SIGNAL(clicked(bool)),this,SLOT(registerPaintBrushButton()));


    QPushButton* broadBrushButton = createToolButton();
    toolButtons->addButton(broadBrushButton);
    connect(broadBrushButton,SIGNAL(clicked(bool)),this,SLOT(registerBroadBrushButton()));

    QPushButton* dropperButton = createToolButton();
    toolButtons->addButton(dropperButton);
    connect(dropperButton,SIGNAL(clicked(bool)),this,SLOT(registerDropperButton()));

    QPushButton* eraserButton = createToolButton();
    toolButtons->addButton(eraserButton);
    connect(eraserButton,SIGNAL(clicked(bool)),this,SLOT(registerEraserButton()));

    QPushButton* bucketFillButton = createToolButton();
    toolButtons->addButton(bucketFillButton);
    connect(bucketFillButton,SIGNAL(clicked(bool)),this,SLOT(registerBucketFillButton()));

    QPushButton* mouseButton = createToolButton();
    toolButtons->addButton(mouseButton);
    connect(mouseButton,SIGNAL(clicked(bool)),this,SLOT(registerMouseButton()));
}

/*
 * Manaully creates primary and secondary color buttons, setting their initial values
 * and location within the widget
*/
void QWidgetToolbar::addColorButtons()
{
    primaryColorImage = new QImage(40,40,QImage::Format_ARGB32);
    QPushButton* primaryColorButton = new QPushButton("", this);
    connect(primaryColorButton,SIGNAL(clicked(bool)),this,SLOT(updatePrimaryColorImage()));
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

    colorButtons[0] = primaryColorButton;

    secondaryColorImage = new QImage(40,40,QImage::Format_ARGB32);
    QPushButton* secondaryColorButton = new QPushButton("", this);
    connect(secondaryColorButton,SIGNAL(clicked(bool)),this,SLOT(updateSecondaryColorImage()));

    secondaryColorButton->setMaximumSize(50,50);
    secondaryColorButton->setMinimumSize(50,50);
    secondaryColorButton->setText(QString(""));
    secondaryColorButton->move(30, 250);

    secondaryColorImage->fill(QColor(203,203,203));
    secondaryColorButton->setIcon(QPixmap::fromImage(*secondaryColorImage));
    secondaryColorButton->setIconSize(QSize(35,35));

    secondaryColorButton->show();

    colorButtons[1] = secondaryColorButton;

    secondaryColorImage = new QImage(40,40,QImage::Format_ARGB32);

    QPushButton* swapColorButton = new QPushButton("", this);
    QPixmap buttonPixMap(":Images/Buttons/Resources/SwapArray.png");
    QIcon brushIcon(buttonPixMap);
    swapColorButton->setIcon(brushIcon);;
    swapColorButton->move(0, 250);
    swapColorButton->setStyleSheet("background-color:#323232; border-style:none");
    connect(swapColorButton,SIGNAL(clicked(bool)),this,SLOT(swapPrimaryAndSecondaryColors()));
    swapColorButton->show();


    colorButtons[2] = swapColorButton;
}

/*
 * Incrementally adds Icons to the buttons
 *
 */
void QWidgetToolbar::addIcon(QPushButton * pb)
{
    QPixmap buttonPixMap(buttonPaths[currentButtonIndex]);
    QIcon brushIcon(buttonPixMap);
    pb->setIcon(brushIcon);
    pb->setIconSize(QSize(18,18));

    buttons[currentButtonIndex] = pb;

    currentButtonIndex++;
}

/*
 * Updates the image icons for all the buttons to be unclicked except for the one that called the function
 *
 */
void QWidgetToolbar::updateButtonsView(int clicked)
{
    for(int i = 0; i < 6; i++)
    {
        if(i == clicked)
        {
            QPixmap buttonPixMap(buttonPathsClicked[i]);
            QIcon brushIcon(buttonPixMap);
            buttons[i]->setIcon(brushIcon);
            buttons[i]->setIconSize(QSize(18,18));
        }
        else
        {
            QPixmap buttonPixMap(buttonPaths[i]);
            QIcon brushIcon(buttonPixMap);
            buttons[i]->setIcon(brushIcon);
            buttons[i]->setIconSize(QSize(18,18));
        }

    }
}

/*
 * Sets up all the clicked and unclicked image paths to be used
 *
 */
void QWidgetToolbar::setUpUnclickedButtonPaths()
{
    buttonPaths[0] = ":Images/Buttons/Resources/unclickedPen.png";
    buttonPaths[1] = ":Images/Buttons/Resources/UnclickedBrush.png";
    buttonPaths[2] = ":Images/Buttons/Resources/unclickedDropper.png";
    buttonPaths[3] = ":Images/Buttons/Resources/unclickedEraser.png";
    buttonPaths[4] = ":Images/Buttons/Resources/UnclickedBucket.png";
    buttonPaths[5] = ":Images/Buttons/Resources/UnclickedMouse.png";

    buttonPathsClicked[0] = ":Images/Buttons/Resources/clickedPen.png";
    buttonPathsClicked[1] = ":Images/Buttons/Resources/clickedBrush.png";
    buttonPathsClicked[2] = ":Images/Buttons/Resources/clickedDropper.png";
    buttonPathsClicked[3] = ":Images/Buttons/Resources/clickedEraser.png";
    buttonPathsClicked[4] = ":Images/Buttons/Resources/ClickedBucket.png";
    buttonPathsClicked[5] = ":Images/Buttons/Resources/clickedMouse.png";

}

/*
* Registers the PaintBrush as the current tool, updating the color and width accordingly
*/
void QWidgetToolbar::registerPaintBrushButton()
{
        currentButtonIndex = 0;

        updateButtonsView(currentButtonIndex);

        currentTool = paintBrush;
        updateToolColor(primarySelectedColor);
        updateToolWidth(sizeSlider->Slider->value());

        toggleColorButtons();
}

/*
* Registers the BroadBrush as the current tool, updating the color and width accordingly
*/
void QWidgetToolbar::registerBroadBrushButton()
{
        qDebug() << "BroadBrush";
        currentButtonIndex = 1;
        updateButtonsView(currentButtonIndex);

        currentTool = broadBrush;

        updateToolColor(primarySelectedColor);
        updateToolWidth(sizeSlider->Slider->value());

        toggleColorButtons();
}

/*
* Registers the dropper as the current tool, updating the color and width accordingly
*/
void QWidgetToolbar::registerDropperButton()
{
    currentTool = dropper;
    currentButtonIndex = 2;
    updateButtonsView(currentButtonIndex);

    updateToolColor(primarySelectedColor);
    updateToolWidth(sizeSlider->Slider->value());
    toggleColorButtons();
    colorButtons[0]->setEnabled(false);
    colorButtons[1]->setEnabled(false);
    colorButtons[2]->setEnabled(false);

}

/*
* Registers the dropper as the current tool, updating the color and width accordingly
*/
void QWidgetToolbar::registerBucketFillButton()
{
    currentTool = bucket;
    currentButtonIndex = 4;
    updateButtonsView(currentButtonIndex);

    updateToolColor(primarySelectedColor);
    updateToolWidth(sizeSlider->Slider->value());
    toggleColorButtons();
}

/*
* Registers the mouse as the current tool, updating the color and width accordingly
*/
void QWidgetToolbar::registerMouseButton()
{
    qDebug() << "mouse";
    currentTool = mouse;
    currentButtonIndex = 5;
    updateButtonsView(currentButtonIndex);
    toggleColorButtons();
}

/*
* Registers the eraser as the current tool, updating the color and width accordingly
*/
void QWidgetToolbar::registerEraserButton()
{
    currentButtonIndex = 3;
    updateButtonsView(currentButtonIndex);
    currentTool = eraser;
    currentTool->setColor(primarySelectedColor);
    currentTool->setWidth(sizeSlider->Slider->value());
    colorButtons[0]->setEnabled(false);
    colorButtons[1]->setEnabled(false);
    colorButtons[2]->setEnabled(false);
}

/*
 * Launches dialog box to pick a color. Updates the current color and image for primary or
 * secondary color accordingly
 *
*/
bool QWidgetToolbar::updateColorPrimaryColor()
{
    // Launches choose color Dialog box
    QColorDialog chooseColor;
    QColor chosenColor = chooseColor.getColor();

    // Validates whether the user picked a color
    if(chosenColor.isValid())
    {
        primarySelectedColor = chosenColor;

        updateToolColor(primarySelectedColor);
        updateToolWidth(sizeSlider->Slider->value());

        return true;
    }
    return false;

}

/*
* Launches a dialog box that the secondary color can be picked, Sets the value and updates the secondary button
* color
*/
bool QWidgetToolbar::updateSecondaryColor()
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


/*
* IF a valid color is chosen, update the image for primary color button
*/
void QWidgetToolbar::updatePrimaryColorImage()
{
    if(updateColorPrimaryColor())
    {
        changePrimaryColorButtonImage();
    }
}

/*
* Updates the Primary color button image color
*/
void QWidgetToolbar::changePrimaryColorButtonImage()
{
    primaryColorImage->fill(primarySelectedColor);
    colorButtons[0]->setIcon(QIcon(QPixmap::fromImage(*primaryColorImage)));
}

/*
* IF a valid color is chosen, update the image for secondary color button
*/
void QWidgetToolbar::updateSecondaryColorImage()
{
    if(updateSecondaryColor())
    {
        changeSecondaryColorButtonImage();
    }
}

/*
* Updates the secondary color button image color
*/
void QWidgetToolbar::changeSecondaryColorButtonImage()
{
    secondaryColorImage->fill(secondarySelectedColor);
    colorButtons[1]->setIcon(QIcon(QPixmap::fromImage(*secondaryColorImage)));
}

// Emits a signal that holds the currently selected tool
void QWidgetToolbar::currentToolRequested()
{
    emit sendCurrentTool(currentTool);
}


/*
* Emits a signal that holds the currently selected tool
*/
void QWidgetToolbar::updateDropperReturn(QColor dropperColor)
{
    primarySelectedColor = dropperColor;
    changePrimaryColorButtonImage();
}

/*
* Updates the tools Color from what the dropper returned
*/
void QWidgetToolbar::setDropperColor(QColor dropperColor)
{
    primarySelectedColor = dropperColor;
    updateToolColor(dropperColor);
    changePrimaryColorButtonImage();

}

/*
* Gives the current Tool to whomever requested
*/
void QWidgetToolbar::giveTool()
{
    emit tool(currentTool);
}

/*
* Swaps the primary and secondary colors updating their images accordinginly
*/
void QWidgetToolbar::swapPrimaryAndSecondaryColors()
{
    QColor tempPrimary = primarySelectedColor;

    primarySelectedColor = secondarySelectedColor;
    secondarySelectedColor = tempPrimary;
    updateToolColor(primarySelectedColor);

    changePrimaryColorButtonImage();
    changeSecondaryColorButtonImage();
}

/*
* Updates the tools current Color
*/
void QWidgetToolbar::updateToolColor(QColor color)
{
    currentTool->setColor(color);
}

/*
* Updates the tools current width
*/
void QWidgetToolbar::updateToolWidth(int width)
{
    currentTool->setWidth(width);
}

/*
* Disables the colors buttons when the dropper and eraser is selected
*/
void QWidgetToolbar::toggleColorButtons()
{
    if(colorButtons[0]->isEnabled() == false && colorButtons[1]->isEnabled() ==false)
    {
        colorButtons[0]->setEnabled(true);
        colorButtons[1]->setEnabled(true);
        colorButtons[2]->setEnabled(true);
    }

}

/*
* Sets padding for the buttons style
*/
void QWidgetToolbar::setButtonPadding()
{
    // Styling for the border and placement of children QObjects.
    this->leftPadding = 8;
    this->upPadding = 8;
    this->rightPadding = 8;
    this->bottomPadding = 8;
}



/* Instantiates the tools to their default values
 * Sets the initial tool to the paintbrush, orange, width 10
 * */
void QWidgetToolbar::setInitialState()
{
    // Instantiates the tools and sets the default to the paintBrush
    paintBrush = new paintbrushTool;
    paintBrush->setName("paintBrush");
    eraser = new Eraser;
    eraser->setName("eraser");
    broadBrush = new BroadBrush;
    broadBrush->setName("broadBrush");
    dropper = new Dropper;
    dropper->setName("dropper");
    bucket = new bucketTool;
    bucket->setName("bucket");

    mouse = new MouseTool;
    mouse->setName("mouse");

    currentTool = mouse;
    primarySelectedColor = QColor(255,158,73);
    secondarySelectedColor = QColor(203,203,203);
    selectedWidth = 10;
    updateToolColor(primarySelectedColor);
    updateToolWidth(selectedWidth);
}

/*
* Creates a slider and connects the change value widget
*/
void QWidgetToolbar::createSlider()
{
    int numOfTools = this->toolButtons->buttons().length();
    sizeSlider = new QWidgetSliderCombo(this, "Size", 1, 32*numOfTools/2 + 25, this->width()-10, 64);
    sizeSlider->Slider->setValue(selectedWidth);
}
