#include "Models/toolsmodel.h"
#include <QDebug>

ToolsModel::ToolsModel()
{
    // pendwidth == broadbrush, change once merges happen
    currentTool = "mouse";
    penWidth = 3;
    brushWidth = 7;
    eraserWidth = 5;
}

QRgb ToolsModel::Color()
{
    return currentColor;
}

qint32 ToolsModel::Width()
{
    return toolWidth;
}

void ToolsModel::mouseMoveEvent(QMouseEvent *mouse_event)
{
    qDebug() << this->objectName();
}

void ToolsModel::determineTool(QString tool)
{

    if(tool == "paintBrushButton")
        toolWidth = brushWidth;
    else if(tool == "broadBrushButton")
        toolWidth = penWidth;
   else if(tool == "eraserButton")
        toolWidth = eraserWidth;

}

void ToolsModel::SetColor(QColor cColor)
{
    currentColor = qRgba(cColor.red(),cColor.green(),cColor.blue(),cColor.alpha());
}

void ToolsModel::UpdateTool(QString tool)
{
    currentTool = tool;
    determineTool(tool);
    emit HighlightToolIcon(currentTool);
}


