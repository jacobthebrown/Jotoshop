#include "clickedcolorresponse.h"
#include <QColorDialog>

clickedColorResponse::clickedColorResponse(QWidget *parent) : QLabel(parent)
{

}

void clickedColorResponse::mousePressEvent(QMouseEvent *mouse_event)
{
    cDialog.getColor();
    emit sendColorSelected(cDialog.currentColor());
}
