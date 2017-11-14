#include "mousetool.h"

MouseTool::MouseTool()
{

}

QColor MouseTool::GetColor()
{
    return color;
}

int MouseTool::GetWidth()
{
    return width;
}

void MouseTool::SetWidth(int newWidth)
{
    width = newWidth;
}

void MouseTool::SetColor(QColor newColor)
{
    color = newColor;
}

void MouseTool::Paint(QImage *, QPoint)
{

}

QString MouseTool::GetName()
{
    return name;
}

void MouseTool::SetName(QString ToolName)
{
    name = ToolName;
}
