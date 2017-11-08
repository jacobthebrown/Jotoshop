#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>
#include <QWidget>
#include <QDebug>
#include <QLineEdit>
#include <QLabel>
#include <QPoint>
#include <QColorDialog>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    // Connects canvas widget images with preview widget images
    connect(this, SIGNAL(addCanvas()), ui->Canvas, SLOT(addCanvas()));
    connect(ui->Canvas, SIGNAL(sendImages(QVector<QImage*>)), this, SLOT(sendPreviewImages(QVector<QImage*>)));

    // Connects canvas widget images with animation strip
    connect(this, SIGNAL(addToStrip(QImage*)), ui->AnimationStrip, SLOT(addQImage(QImage*)));

}

MainWindow::~MainWindow()
{

    delete ui;
}



//
QLabel* MainWindow::getCanvasAsLabel()
{
    QLabel* label = new QLabel;
    QImage tempImage = ui->Canvas->getActiveCanvasImage()->scaled(80,80,Qt::KeepAspectRatio);
    QPixmap tempPix = tempPix.fromImage(tempImage);
    label->setPixmap(tempPix);
    label->setFixedSize(80,80);
    return label;
}

/*
* Sends qimages from canvas widget to preview widget
*/
void MainWindow::sendPreviewImages(QVector<QImage*> images)
{
    ui->Preview->setImages(images);
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
*/

/*
 * TODO
 */
void MainWindow::on_addCanvasButton_clicked()
{
    // Add current canvas to animation strip
    ui->AnimationStrip->layout()->addWidget(getCanvasAsLabel());

    //Add new canvas and update display
    addCanvas();
    ui->Canvas->update();

}


void MainWindow::on_fpsSpeedSlider_valueChanged(int value)
{
    ui->sliderValueLabel->setText("FPS: " + QString::number(value));
    ui->Preview->setSpeed(value);
}
