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

class QWidgetToolbar : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetToolbar(QWidget *parent = nullptr);

private:
    ToolsModel currentTool;

    // Padding for spacing
    int upPadding, rightPadding, bottomPadding, leftPadding;

    //Group of pushbuttons
    QButtonGroup* ToolButtons;

    int getSize();

    QImage* primaryColorImage;
    QImage* secondaryColorImage;

    QPixmap primaryMap,secondaryMap;

    // Arrays cordinating the currentButton to strings
    int currentButton;
    QString buttonPaths[4];
    QPushButton* buttons[4];
    QString functionNames[4];

    QPushButton* ColorButtons[3];

    // Adds the button to the group
    void AddButtons(QButtonGroup*);
    void AddColorButtons();
    // Slaps an icon on each button
    void AddIcon(QPushButton*);
    // instantiate arrays with strings
    void setUpButtonPaths();

    // creats a button
    QPushButton* createToolButton();
    // paint event for some reason
    //void paintEvent(QPaintEvent *e);

    void ChooseColor(int);
signals:

public slots:
    void RegisterPaintBrushButton();
    void RegisterBroadBrushButton();
    void RegisterDropperButton();
    void RegisterEraserButton();
    void ChangeWidth(int);
    void UpdatePrimary();
    void UpdateSecondary();
};

#endif // QWIDGETTOOLBAR_H
