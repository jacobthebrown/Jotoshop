#include "toolsmodel.h"
#include <QDebug>

ToolsModel::ToolsModel()
{

}

QRgb ToolsModel::getColor()
{
    return currentColor;
}

void ToolsModel::SetColor(QColor cColor)
{
    currentColor = qRgba(cColor.red(),cColor.green(),cColor.blue(),cColor.alpha());
}
