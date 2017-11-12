#include "Models/toolsmodel.h"
#include <QDebug>

ToolsModel::ToolsModel()
{
    // pendwidth == broadbrush, change once merges happen
    // Gives some default values for the brush widths and initial primary color
    currentTool = "mouse";
    penWidth = 3;
    brushWidth = 7;
    eraserWidth = 5;
    SetColor(QColor(255, 160, 47));

}

QRgb ToolsModel::Color()
{
    return currentColor;
}

qint32 ToolsModel::Width()
{
    return toolWidth;
}

void ToolsModel::updateWidth(int newWidth)
{
    setWidth(newWidth);
}

void ToolsModel::mouseMoveEvent(QMouseEvent *mouse_event)
{
    qDebug() << this->objectName();
}

void ToolsModel::setWidth(int width)
{
    toolWidth = width;
}

void ToolsModel::determineTool(QString tool)
{

    if(tool == "paintBrushButton")
        toolWidth = brushWidth;
    else if(tool == "broadBrushButton")
        toolWidth = penWidth;
    else if(tool == "eraserButton")
        toolWidth = eraserWidth;

    emit SignalDefaultWidth(toolWidth);
}

void ToolsModel::SetColor(QColor cColor)
{
    currentColor = qRgba(cColor.red(),cColor.green(),cColor.blue(),cColor.alpha());
}

void ToolsModel::setSecondaryColor(QColor sColor)
{
    backupColor = qRgba(sColor.red(),sColor.green(),sColor.blue(),sColor.alpha());
}

void ToolsModel::UpdateTool(QString tool)
{
    currentTool = tool;
    determineTool(tool);
    //emit HighlightToolIcon(currentTool);
}


