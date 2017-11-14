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

MainWindow::MainWindow(GifExporter& gifModel, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    // Connects canvas widget images with preview widget images
    connect(this, SIGNAL(addCanvas(QSize)), ui->Canvas, SLOT(addCanvas(QSize)));
    connect(this, SIGNAL(addToStrip(QPixmap, int)), ui->AnimationStrip, SLOT(addQImage(QPixmap,int)));
    connect(ui->Canvas, SIGNAL(sendImages(QVector<QImage*>)), this, SLOT(sendPreviewImages(QVector<QImage*>)));
    connect(ui->Preview,SIGNAL(activityStatus(bool)),this,SLOT(updatePreviewButtonStatus(bool)));

    // Connects "Export to GIF" menu button to the gif exporting logic
    connect(ui->exportAction, &QAction::triggered, this, &MainWindow::exportGIF);
    connect(this, &MainWindow::exportToGIF, &gifModel, &GifExporter::exportToGIF);

    // Connects canvas widget images with animation strip
	connect(ui->AnimationStrip, SIGNAL(sendClickedCanvas(QListWidgetItem*)), this, SLOT(onCanvasIconClicked(QListWidgetItem*)));
    //connect(this, SIGNAL(addToStrip(QLabel*)), ui->AnimationStrip, SLOT(addQImage(QLabel*)));

    // Connects upon loading an image creates a new canvas
    connect(this,SIGNAL(loadImage(QImage*)),ui->Canvas,SLOT(load(QImage*)));

    // Connects canvas and animation strip
    connect(ui->Canvas, SIGNAL(ImageUpdate(QImage*,int)), ui->AnimationStrip, SLOT(refreshImage(QImage*,int)) );

    // Connects tools
    connect(ui->Canvas,SIGNAL(GrabTool()),ui->Toolbar,SLOT(GiveTool()));
    connect(ui->Toolbar, SIGNAL(Tool(BaseToolClass*)),ui->Canvas, SLOT(CurrentTool(BaseToolClass*)));
    
    // Scroll set up
    this->ui->ExpandableScroller_1->WidgetToScroll = ui->scrollArea_2;
    this->ui->ExpandableScroller_1->WidgetToProtect = ui->scrollArea;

    // Begin setup with a add new action
    emit ui->actionNew->triggered();

    // Set size of canvas
    this->ui->Canvas->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->ui->Canvas->setFixedSize(canvasSize.width(), canvasSize.height());
    this->ui->Canvas->imageHeight = canvasSize.height();
    this->ui->Canvas->imageWidth = canvasSize.width();
    this->ui->Canvas->setScale(1.0);

//    connect(ui->Canvas,SIGNAL(RequestCurrentTool()),this,SLOT(CurrentToolRequest()));
//    connect(this,SIGNAL(GetcurrentToolFromBar()),ui->Toolbar,SLOT(CurrentToolRequested()));
//    connect(ui->Toolbar,SIGNAL(SendCurrentTool(BaseToolClass*)),this,SLOT(AquiredCurrentTool(BaseToolClass*)));
//    connect(this,SIGNAL(SendCanvasCurrentTool(BaseToolClass*)),ui->Canvas,SLOT(RecieveTool(BaseToolClass*)));
    connect(ui->Canvas,SIGNAL(ReturnDropperColor(QColor)),ui->Toolbar,SLOT(SetDropperColor(QColor)));
}

MainWindow::~MainWindow()
{
    // TODO: Make sure we are deleting every object we created in the heap.
    delete ui;
}

// TODO: MOVE TO MAIN WINDOW MODEL
// TODO: SET FPS OF GIF.
void MainWindow::exportGIF()
{
    // Dialog to get gif export path.
    const QString fileName = QFileDialog::getSaveFileName(this, tr("Export to GIF"), "C:/Users/Sam/Documents", tr("Image Files (*.gif)"));

    // Grab all the Canvas images and push them into a vector.
    QVector<QImage*> temp;
    foreach (QImage *im, ui->Canvas->getAllCompositeImages()) {
        QImage* ima = new QImage;
        *ima = *im;
        temp.push_back(ima);
    }

    int width = ui->Canvas->width();
    int height = ui->Canvas->height();


    emit exportToGIF(fileName, temp, width, height);
}



// TODO: MOVE TO MAIN WINDOW MODEL
// TODO: CREATE ERROR HANDLING EXCEPTIONS
QString MainWindow::SaveFile(int width, int height, int frames, QVector<QImage*> images)
{
    // Grabs the filename saved; forcing the filter to be the extension
    const QString filter = "(*.ssp)";
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save File"),tr(".ssp"),filter);
    QFile file(fileName);

    // Throws a warning dialog box if the file won't open
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Save Error","Error saving file!");
        return NULL;
    }

    // Creates a textstream handler
    QTextStream out(&file);
    QString line;

    // Write height and width to file followed by the number of frames in project
    line = QString::number(height) + " " + QString::number(width);
    out << line << endl << QString::number(frames) << endl;

    QColor pixel;

    // Loops through each images writing individual pixels to the file
    foreach(QImage* image, images)
    {
        for(int y = 0; y < height; y++)
        {
            for(int x = 0; x < width; x++)
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
    file.close();
    file.flush();


    return fileName;

}

/*
 * TODO: MOVE TO MODEL.
 * TODO: CREATE ERROR HANDLING EXCEPTIONS
 */
void MainWindow::LoadFile(QString fileName)
{
    QFile file(fileName);

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Error", "Couldn't Open File");
        return;
    }
    qint32 height, width, frames;

    QStringList lineSplit;
    QString line;
    QTextStream in(&file);

    line = in.readLine();
    lineSplit = line.split(' ');

    height = lineSplit[0].toInt();
    width = lineSplit[1].toInt();

    line = in.readLine();
    frames = line.toInt();

     QString temp;
     QImage *im;
     QLabel* label;
     QPixmap tempPix;
    int row = 0, col = 0;


    for(int z = 0; z < frames; z++)
    {
        im = new QImage(width, height, QImage::Format_ARGB32);
        for(int y = 0; y < height; y++)
        {
            line = in.readLine();
            lineSplit = line.split(' ');
            for(int x = 0; x < lineSplit.size(); x += 4)
            {
//                temp += lineSplit[x] + " " +lineSplit[x + 1] +  " " + lineSplit[x + 2] + " " + lineSplit[x + 3] + " ";
                im->setPixel(col,row,qRgba(lineSplit[x].toInt(),lineSplit[x + 1].toInt(),lineSplit[x + 2].toInt(),lineSplit[x + 3].toInt()));
                col++;
                if(col == width)
                    col = 0;
            }
            row++;
            if(row == height)
                row = 0;

        }

        label = new QLabel;
        //im->scaled(80,80,Qt::KeepAspectRatio);
        //QImage tempImage = ui->Canvas->getActiveCanvasImage()->scaled(80,80,Qt::KeepAspectRatio);
        tempPix= QPixmap::fromImage(*im);
        QImage t = im->scaled(80,80,Qt::KeepAspectRatio);
        //tempPix.scaled(80,80,Qt::KeepAspectRatio);
        label->setPixmap(QPixmap::fromImage(t));
        label->setFixedSize(80,80);
        //ui->AnimationStrip->layout()->addWidget(label);

        if(ui->Canvas->getAllCompositeImages().count() > 0)
        {
            ui->AnimationStrip->addQImage(QPixmap::fromImage(t), ui->Canvas->getAllCompositeImages().indexOf(ui->Canvas->getActiveCanvasImage()));
        }


        //Add new canvas and update display
        //addCanvas();
        emit(loadImage(im));
    }
    ui->Canvas->update();
    file.close();
}

/*
* Sends qimages from canvas widget to preview widget
*/
void MainWindow::sendPreviewImages(QVector<QImage*> images)
{
    ui->Preview->setImages(images);
}

/*
 * Update text of previewButton to the active status of the Preview window
 */
void MainWindow::updatePreviewButtonStatus(bool isActive)
{
    if(isActive)
        ui->previewButton->setText("Stop Preview");
    else
        ui->previewButton->setText("Start Preview");
}
/*
 *
 */
void MainWindow::onCanvasIconClicked(QListWidgetItem *item)
{

    for(int i = 0; i < ui->AnimationStrip->listArea->count(); i++){
        if (ui->AnimationStrip->listArea->item(i) == item)
            // TODO: ERROR HANDLE FOR NULL CANVAS
            ui->Canvas->setActiveCanvas(ui->Canvas->composites.at(i));
    }
}

/*
 * TODO
 */
void MainWindow::on_addCanvasButton_clicked()
{
    //Add new canvas and update display
    emit addCanvas(canvasSize);
    ui->Canvas->update();

    int framePos = 0;

    if(ui->Canvas->getActiveCanvas() != nullptr)
    {

    }
    if(ui->Canvas->getAllCompositeImages().count() > 0)
    {
        framePos = ui->Canvas->getAllCompositeImages().indexOf(ui->Canvas->getActiveCanvasImage());
    }
    emit addToStrip(QPixmap::fromImage(*(ui->Canvas->getActiveCanvasImage())), framePos);

}

/*
 * Updates the speed in preview window when slider value is adjusted
 */
void MainWindow::on_fpsSpeedSlider_valueChanged(int value)
{
    ui->sliderValueLabel->setText("FPS: " + QString::number(value));
    ui->Preview->setSpeed(value);
}

/*
 *
 */
void MainWindow::on_actionSave_triggered()
{
    QVector<QImage*> canvasVector = ui->Canvas->getAllCompositeImages();
    SaveFile((canvasVector[0])->width(), (canvasVector[0])->height(), canvasVector.count(), canvasVector);
}

/*
 *
 */
void MainWindow::on_actionNew_triggered()
{
    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);

    // Add some text above the fields
    form.addRow(new QLabel("Please select an initial size for the Canvas:"));

    QList<QLineEdit *> fields;
    for(int i = 0; i < 2; ++i) {
        QLineEdit *lineEdit = new QLineEdit(&dialog);
        QString label;
        if(i == 0)
        {
            label = "Width (px):";
        }
        else
        {
            label = "Height (px):";
        }

        form.addRow(label, lineEdit);

        fields << lineEdit;
    }

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));



    // Show the dialog as modal
    if (dialog.exec() == QDialog::Accepted) {
        // restore ui to its default state
        restoreDefaultUI();

        // If the user didn't dismiss the dialog, do something with the fields
        int width = fields[0]->text().toInt();
        int height = fields[1]->text().toInt();

        canvasSize = QSize(width, height);

        QVector<QImage*> canvasVector;



    }
}
/*
 * Restores the ui to its default state. (i.e., an empty canvas widget, empty frame viewer, and empty preview window)
 */
void MainWindow::restoreDefaultUI()
{
    ui->Canvas->clear();
    ui->AnimationStrip->clear();
    ui->Preview->clear();
}

/*
 *
 */
void MainWindow::on_actionLoad_triggered()
{
    // Creates a dialog to select a project to load.
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load Project"), "", tr("*.ssp"));

    LoadFile(fileName);
}

/*
 * Calls setActiveStatus in QWidgetPreview when previewButton clicked
 */
void MainWindow::on_previewButton_clicked()
{
    ui->Preview->setActiveStatus();
}

/*
 * Calls fullPreview in QWidgetPreview when fullPreviewButton clicked
 */
void MainWindow::on_fullPreviewButton_clicked()
{
    ui->Preview->fullPreview();
}

/*
 *
 */
void MainWindow::CurrentToolRequest()
{
    emit GetcurrentToolFromBar();
}

/*
 *
 */
void MainWindow::AquiredCurrentTool(BaseToolClass * tool)
{
    emit SendCanvasCurrentTool(tool);
}

/*
 *
 */
void MainWindow::on_canvas_GrowButton_clicked()
{
    ui->Canvas->shiftScale(+0.05);
}

/*
 *
 */
void MainWindow::on_canvas_ShrinkButton_clicked()
{
    ui->Canvas->shiftScale(-0.05);
}
