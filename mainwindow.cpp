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

void MainWindow::SaveFile(int width, int height, int frames, QVector<QImage*> images)
{
    // Grabs the filename saved; forcing the filter to be the extension
    const QString filter = "(*.ssp)";
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save File"),tr(".ssp"),filter);
    QFile file(fileName);

    // Throws a warning dialog box if the file won't open
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Save Error","Error saving file!");
        return;
    }

    // Creates a textstream handler
    QTextStream out(&file);
    QString line;

    // Write height and width to file followed by the number of frames in project
    line = QString::number(height) + " " + QString::number(width) + "\n";
    out << line;

    out << QString::number(frames) + "\n";

    QColor pixel;
    foreach(QImage* image, images)
    {
        for(int y = 0; y < image->height(); y++)
        {
            for(int x = 0; x < image->width(); x++)
            {
                pixel = image->pixelColor(x,y);

                line = QString::number(pixel.red());
                line += " ";
                line += QString::number(pixel.green());
                line += " ";
                line += QString::number(pixel.blue());
                line += " ";
                line += QString::number(pixel.alpha());
                if(x == image->width() - 1)
                    line += "\n";
                else
                    line += " ";
                out << line;
            }
        }
    }

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

void MainWindow::on_actionSave_triggered()
{
    QVector<QImage*> canvasVector = ui->Canvas->getAllCompositeImages();
    SaveFile((canvasVector[0])->width(), (canvasVector[0])->height(), canvasVector.count(), canvasVector);
}
