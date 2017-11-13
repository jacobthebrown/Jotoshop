#include "fullpreviewwindow.h"
#include "ui_fullpreviewwindow.h"

FullPreviewWindow::FullPreviewWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FullPreviewWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Preview Sprite");
}

FullPreviewWindow::~FullPreviewWindow()
{
    delete ui;
}
