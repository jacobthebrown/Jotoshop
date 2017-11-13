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

    // Tool dimensions
    QColor primarySelectedColor,secondarySelectedColor;
    int selectedWidth;

    // Helper functions to instantiate Tools value
    void UpdateToolColor(QColor);

    // Getters for width and color
    int GetToolWidth();

    // Launches QColorDialog to pick a color, parameter is to represent
    // Either the primary or secondary color was clicked
    bool UpdateColorPrimaryColor();
    bool UpdateSecondaryColor();



    // Padding for spacing
    int upPadding, rightPadding, bottomPadding, leftPadding;

    //Group of pushbuttons
    QButtonGroup* ToolButtons;

    // Images & pixmaps for primary color and secondary color buttons
    QImage* primaryColorImage;
    QImage* secondaryColorImage;
    QPixmap primaryMap,secondaryMap;

    // Arrays that hold the image paths, tool buttons, and color buttons
    int currentButton;
    QString buttonPaths[4];
    QPushButton* buttons[4];
    QPushButton* ColorButtons[3];

    // Helper Methods to set up the Ui
    void AddButtons(QButtonGroup*);
    void AddColorButtons();

    // Slaps an icon on each button
    void AddIcon(QPushButton*);

    // instantiate arrays with strings
    void setUpButtonPaths();

    // creats a button
    QPushButton* createToolButton();

    // Internal sliderWidet
    QWidgetSliderCombo* sizeSlider;

    void ToggleColorButtons();
signals:

    void SendCurrentTool(BaseToolClass*);

public slots:
    void RegisterPaintBrushButton();
    void RegisterBroadBrushButton();
    void RegisterDropperButton();
    void RegisterEraserButton();
    void UpdateToolWidth(int);
    void UpdatePrimaryColorImage();
    void UpdateSecondaryColorImage();

    void CurrentToolRequested();
    void UpdateDropperReturn(QColor);


};

#endif // QWIDGETTOOLBAR_H
