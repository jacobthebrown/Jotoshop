#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>
#include <QWidget>
#include <QDebug>
#include <QLineEdit>
#include <QLabel>
#include <QPoint>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    count = 0;
    ui->setupUi(this);
    connect(ui->primaryColorWidget, SIGNAL(sendColorSelected(QColor)),this,SLOT(recieveSelectedColor(QColor)));
    connect(this,SIGNAL(updateToolBar(QColor)),&toolBar,SLOT(SetColor(QColor)));
    SetToolBarPics();

    //Canvas conncections
    //connect(ui->CanvasLayout, SIGNAL(sendMousePosition(QPoint&)),this,SLOT(paintCanvas(QPoint&))); // Mouse position on canvas
    connect(this, SIGNAL(addCanvas()), &canvasWidget, SLOT(addCanvas()));
    connect(&canvasWidget,SIGNAL(sendCurrentCanvas(CanvasModel*)), this, SLOT(showCanvas(CanvasModel*)));

    ui->tabWidget->removeTab(1);

    //ToolBar connections
    connect(&toolBar,SIGNAL(HighlightToolIcon(QString)),this,SLOT(UpdateButtonBorder(QString)));
    connect(this,SIGNAL(ToolClicked(QString)),&toolBar,SLOT(UpdateTool(QString)));
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
    //paint(pos,canvasImage,toolBar.Color(),toolBar.Width());

    int offset = toolBar.Width()/2;

    try
        {
            for(int i = pos.x()- offset; i <= pos.x()+ offset; i++)
            {
                for(int j = pos.y() - offset; j < pos.y() + offset; j++)
                {
                    if(i > 0 && i < canvasImage.width() && j > 0 && j < canvasImage.height())
                    {
                        canvasImage.setPixel(i,j,toolBar.Color());
                    }
                }
            }
        }
        catch(...)
        {

        }


    //canvasImage.setPixel(pos.x(),pos.y(),toolBar.Color());
    QPixmap map(QPixmap::fromImage(canvasImage));
    //ui->tempCanvas->setPixmap(map);
}

//void MainWindow::paint(QPoint pos, QImage& im, QRgb color, qint32 width)
//{
//    int offset = width/2;
//    for(int i = pos.x()- offset; i <= pos.x()+ offset; i++)
//    {
//        for(int j = pos.y() - offset; j < pos.y() + offset; j++)
//        {
//            im.setPixel(i,j,color);
//        }
//    }
//    QPixmap map(QPixmap::fromImage(im));
//    ui->tempCanvas->setPixmap(map);
//}

void MainWindow::UpdateButtonBorder(QString name)
{
    qDebug() << name;
    QString styleSheetNotClicked = "background-color: rgb(173,173,173)";
    ui->paintBrushButton->setStyleSheet(styleSheetNotClicked);
    ui->broadBrushButton->setStyleSheet(styleSheetNotClicked);
    ui->dropperButton->setStyleSheet(styleSheetNotClicked);
    ui->eraserButton->setStyleSheet(styleSheetNotClicked);

    QString stylesheetClicked = "background-color: rgb(173,173,173);border-style:solid;border-width:2px;border-color:rgb(253,120,44);";
    if(name == "paintBrushButton")
        ui->paintBrushButton->setStyleSheet(stylesheetClicked);
    if(name == "broadBrushButton")
        ui->broadBrushButton->setStyleSheet(stylesheetClicked);
   if(name == "eraserButton")
        ui->eraserButton->setStyleSheet(stylesheetClicked);
   if(name == "dropperButton")
        ui->dropperButton->setStyleSheet(stylesheetClicked);

}

void MainWindow::on_paintBrushButton_clicked()
{
    emit ToolClicked("paintBrushButton");
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


