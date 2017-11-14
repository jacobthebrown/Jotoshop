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
    // Might not be right
    BaseToolClass* GetCurrentTool();
private:
    // Rename to currentTool
    BaseToolClass *currentTool;
//    ToolsModel currentTool;

    // List of tools
    paintbrushTool*  paintBrush;
    Eraser* eraser;
    BroadBrush* broadBrush;
    Dropper* dropper;
    bucketTool* Bucket;
    MouseTool* mouse;

    // Tool dimensions
    QColor primarySelectedColor,secondarySelectedColor;
    int selectedWidth;




    // Padding for spacing
    int upPadding, rightPadding, bottomPadding, leftPadding;

    //Group of pushbuttons
    QButtonGroup* ToolButtons;

    // Images & pixmaps for primary color and secondary color buttons
    QImage* primaryColorImage;
    QImage* secondaryColorImage;
    QPixmap primaryMap,secondaryMap;

    // Arrays that hold the image paths, tool buttons, and color buttons
    int currentButtonIndex;
    QString buttonPaths[6];
    QString buttonPathsClicked[6];
    QPushButton* buttons[6];
    QPushButton* ColorButtons[3];

    // Helper Methods to set up the Ui
    void AddButtons();
    void AddColorButtons();

    // Slaps an icon on each button
    void AddIcon(QPushButton*);

    // instantiate arrays with strings
    void SetUpUnclickedButtonPaths();

    // creats a button
    QPushButton* createToolButton();

    // Internal sliderWidet
    QWidgetSliderCombo* sizeSlider;

    // Helper functions in setting up the tol bar ui
    void ToggleColorButtons();
    void SetInitialState();
    void CreateSlider();
    void SetButtonPadding();

    void UpdateButtonsView(int);

    // Helper functions to instantiate Tools value
    void UpdateToolColor(QColor);

    // Getters for width and color
    int GetToolWidth();

    // Launches QColorDialog to pick a color, parameter is to represent
    // Either the primary or secondary color was clicked
    bool UpdateColorPrimaryColor();
    bool UpdateSecondaryColor();

    void ChangePrimaryColorButtonImage();
    void ChangeSecondaryColorButtonImage();

signals:

    void SendCurrentTool(BaseToolClass*);

    // Temp
    void Tool(BaseToolClass*);

public slots:
    void RegisterPaintBrushButton();
    void RegisterBroadBrushButton();
    void RegisterDropperButton();
    void RegisterEraserButton();
    void RegisterBucketFillButton();
    void RegisterMouseButton();

    void UpdateToolWidth(int);
    void UpdatePrimaryColorImage();
    void UpdateSecondaryColorImage();

    void CurrentToolRequested();
    void UpdateDropperReturn(QColor);
    void SetDropperColor(QColor);


    // Temp between widget
    void GiveTool();

    void SwapPrimaryAndSecondaryColors();


};

#endif // QWIDGETTOOLBAR_H
