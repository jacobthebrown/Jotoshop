#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>
#include <QWidget>
#include <QDebug>
#include <QLineEdit>
#include <QLabel>
#include <QPoint>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    count = 0;
    ui->setupUi(this);
    //connect(ui->primaryColorWidget, SIGNAL(sendColorSelected(QColor)),this,SLOT(recieveSelectedColor(QColor)));
    //connect(this,SIGNAL(updateToolBar(QColor)),&toolBar,SLOT(SetColor(QColor)));
    //SetToolBarPics();

    //connect(ui->tempCanvas, SIGNAL(sendMousePosition(QPoint&)),this,SLOT(paintCanvas(QPoint&)));

    //canvasImage = QImage(ui->tempCanvas->size().width(),ui->tempCanvas->size().height(),QImage::Format_ARGB32);
    //canvasImage.fill(QColor(0,0,0,0));

    //ui->tabWidget->removeTab(1);

    //ToolBar connections
    //connect(&toolBar,SIGNAL(HighlightToolIcon(QString)),this,SLOT(UpdateButtonBorder(QString)));
    //connect(this,SIGNAL(ToolClicked(QString)),&toolBar,SLOT(UpdateTool(QString)));
}

MainWindow::~MainWindow()
{

    delete ui;
}

/*

void MainWindow::SetToolBarPics()
{
    //QSize size(13,13);
    //QPixmap pbMap(":buttonImages/paintBrush.png");
    //QIcon pbIcon(pbMap);
    //ui->paintBrushButton->setIcon(pbIcon);
    //ui->paintBrushButton->setIconSize(size);
    //
    //QPixmap bbMap(":buttonImages/dropper.png");
    //QIcon bbIcon(bbMap);
    //ui->broadBrushButton->setIcon(bbIcon);
    //ui->broadBrushButton->setIconSize(size);
    //
    //QPixmap erMap(":buttonImages/eraser.png");
    //QIcon erIcon(erMap);
    //ui->eraserButton->setIcon(erIcon);
    //ui->eraserButton->setIconSize(size);
    //
    //QPixmap drMap(":buttonImages/dropper.png");
    //QIcon drIcon(drMap);
    //ui->dropperButton->setIcon(drIcon);
    //ui->dropperButton->setIconSize(size);
}



void MainWindow::recieveSelectedColor(QColor receivedColor)
{
    emit updateToolBar(receivedColor);

    //QImage image(ui->primaryColorWidget->width(),ui->primaryColorWidget->width(), QImage::Format_ARGB32);
    //image.fill(receivedColor);

    //QPixmap m(QPixmap::fromImage(image));
    //ui->primaryColorWidget->setPixmap(m);
}

void MainWindow::paintCanvas(QPoint &pos)
{
    //qDebug() << "We in";
    //canvasImage.setPixel(pos.x(),pos.y(),toolBar.getColor());
    //QPixmap map(QPixmap::fromImage(canvasImage));
    //ui->tempCanvas->setPixmap(map);
}



void MainWindow::on_broadBrushButton_clicked()
{
    emit ToolClicked("broadBrushButton");

}

void MainWindow::on_eraserButton_clicked()
{
    emit ToolClicked("eraserButton");
}

void MainWindow::on_dropperButton_clicked()
{
    emit ToolClicked("dropperButton");
}

void MainWindow::showCanvas(CanvasModel *canvas)
{
    ui->CanvasLayout->addWidget(canvas,1,count);
    count++;
}

void MainWindow::on_addCanvasButton_clicked()
{
    emit addCanvas();
}

*/
