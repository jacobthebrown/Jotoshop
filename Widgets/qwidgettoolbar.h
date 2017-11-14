#ifndef QWIDGETTOOLBAR_H
#define QWIDGETTOOLBAR_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QSlider>
#include <QLabel>
#include <QButtonGroup>
#include "qwidgetslidercombo.h"
#include <QList>
#include <vector>
#include "../Models/toolsmodel.h"
#include "../Models/basetoolclass.h"
#include "../Models/paintbrushtool.h"
#include "../Models/eraser.h"
#include "../Models/broadbrush.h"
#include "../Models/dropper.h"
#include "../Models/buckettool.h"
#include "../Models/mousetool.h"

class QWidgetToolbar : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetToolbar(QWidget *parent = nullptr);
    ~QWidgetToolbar();
    //  Returns the current tool
    BaseToolClass* getCurrentTool();
private:
    // Rename to currentTool
    BaseToolClass *currentTool;
//    ToolsModel currentTool;

    // List of tools
    paintbrushTool*  paintBrush;
    Eraser* eraser;
    BroadBrush* broadBrush;
    Dropper* dropper;
    bucketTool* bucket;
    MouseTool* mouse;

    // Tool dimensions
    QColor primarySelectedColor,secondarySelectedColor;
    int selectedWidth;




    // Padding for spacing
    int upPadding, rightPadding, bottomPadding, leftPadding;

    //Group of pushbuttons
    QButtonGroup* toolButtons;

    // Images & pixmaps for primary color and secondary color buttons
    QImage* primaryColorImage;
    QImage* secondaryColorImage;
    QPixmap primaryMap,secondaryMap;

    // Arrays that hold the image paths, tool buttons, and color buttons
    int currentButtonIndex;
    QString buttonPaths[6];
    QString buttonPathsClicked[6];
    QPushButton* buttons[6];
    QPushButton* colorButtons[3];

    // Helper Methods to set up the Ui
    void addButtons();
    void addColorButtons();

    // Slaps an icon on each button
    void addIcon(QPushButton*);

    // instantiate arrays with strings
    void setUpUnclickedButtonPaths();

    // creats a button
    QPushButton* createToolButton();

    // Internal sliderWidet
    QWidgetSliderCombo* sizeSlider;

    // Helper functions in setting up the tol bar ui
    void toggleColorButtons();
    void setInitialState();
    void createSlider();
    void setButtonPadding();

    void updateButtonsView(int);

    // Helper functions to instantiate Tools value
    void updateToolColor(QColor);

    // Getters for width and color
    int getToolWidth();

    // Launches QColorDialog to pick a color, parameter is to represent
    // Either the primary or secondary color was clicked
    bool updateColorPrimaryColor();
    bool updateSecondaryColor();

    void changePrimaryColorButtonImage();
    void changeSecondaryColorButtonImage();

signals:

    void sendCurrentTool(BaseToolClass*);

    // Sends the tool out of the widget
    void tool(BaseToolClass*);

public slots:
    // Registers the button events for the tools
    void registerPaintBrushButton();
    void registerBroadBrushButton();
    void registerDropperButton();
    void registerEraserButton();
    void registerBucketFillButton();
    void registerMouseButton();

    // Updates tool width and ui
    void updateToolWidth(int);
    void updatePrimaryColorImage();
    void updateSecondaryColorImage();

    // Regarding passing the tool around and info about it
    void currentToolRequested();
    void updateDropperReturn(QColor);
    void setDropperColor(QColor);


    // trigger slot to signify a tool is coming
    void giveTool();
    // Swaps the primary and secondary colors and updates visuals
    void swapPrimaryAndSecondaryColors();


};

#endif // QWIDGETTOOLBAR_H
