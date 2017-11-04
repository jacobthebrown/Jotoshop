#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->primaryColorWidget, SIGNAL(sendColorSelected(QColor)),this,SLOT(recieveSelectedColor(QColor)));
    connect(this,SIGNAL(updateToolBar(QColor)),&toolBar,SLOT(SetColor(QColor)));
    SetToolBarPics();

    connect(ui->tempCanvas, SIGNAL(sendMousePosition(QPoint&)),this,SLOT(paintCanvas(QPoint&)));

    canvasImage = QImage(ui->tempCanvas->size().width(),ui->tempCanvas->size().height(),QImage::Format_ARGB32);
    canvasImage.fill(QColor(0,0,0,0));

    ui->tabWidget->removeTab(1);


}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::SetToolBarPics()
{
    QSize size(13,13);
    QPixmap pbMap(":buttonImages/paintBrush.png");
    QIcon pbIcon(pbMap);
    ui->paintBrushButton->setIcon(pbIcon);
    ui->paintBrushButton->setIconSize(size);

    QPixmap bbMap(":buttonImages/dropper.png");
    QIcon bbIcon(bbMap);
    ui->broadBrushButton->setIcon(bbIcon);
    ui->broadBrushButton->setIconSize(size);

    QPixmap erMap(":buttonImages/eraser.png");
    QIcon erIcon(erMap);
    ui->eraserButton->setIcon(erIcon);
    ui->eraserButton->setIconSize(size);

    QPixmap drMap(":buttonImages/dropper.png");
    QIcon drIcon(drMap);
    ui->dropperButton->setIcon(drIcon);
    ui->dropperButton->setIconSize(size);
}

void MainWindow::recieveSelectedColor(QColor receivedColor)
{
    emit updateToolBar(receivedColor);

    QImage image(ui->primaryColorWidget->width(),ui->primaryColorWidget->width(), QImage::Format_ARGB32);
    image.fill(receivedColor);

    QPixmap m(QPixmap::fromImage(image));
    ui->primaryColorWidget->setPixmap(m);
}

void MainWindow::paintCanvas(QPoint &pos)
{
    qDebug() << "We in";
    canvasImage.setPixel(pos.x(),pos.y(),toolBar.getColor());
    QPixmap map(QPixmap::fromImage(canvasImage));
    ui->tempCanvas->setPixmap(map);
}
