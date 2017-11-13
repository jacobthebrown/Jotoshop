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
    connect(this, SIGNAL(addCanvas()), ui->Canvas, SLOT(addCanvas()));
    connect(ui->Canvas, SIGNAL(sendImages(QVector<QImage*>)), this, SLOT(sendPreviewImages(QVector<QImage*>)));
    connect(ui->Preview,SIGNAL(activityStatus(bool)),this,SLOT(updatePreviewButtonStatus(bool)));

    // Connects "Export to GIF" menu button to the gif exporting logic
    connect(ui->exportAction, &QAction::triggered, this, &MainWindow::exportGIF);
    connect(this, &MainWindow::exportToGIF, &gifModel, &GifExporter::exportToGIF);

    // Connects canvas widget images with animation strip
	connect(ui->AnimationStrip, SIGNAL(sendClickedCanvas(QListWidgetItem*)), this, SLOT(onCanvasIconClicked(QListWidgetItem*)));
    //connect(this, SIGNAL(addToStrip(QLabel*)), ui->AnimationStrip, SLOT(addQImage(QLabel*)));

    // Upon loading an image creates a new canvas
    connect(this,SIGNAL(loadImage(QImage*)),ui->Canvas,SLOT(load(QImage*)));

    //
    connect(ui->Canvas, SIGNAL(ImageUpdate(QImage*,int)), ui->AnimationStrip, SLOT(refreshImage(QImage*,int)) );

    //this->ui->Right_horzLayout->setAlignment(this->ui->Preview, Qt::AlignHCenter);
    //this->ui->Right_horzLayout->setSizeConstraint(QLayout::SetMaximumSize);

    //this->ui->Preview->setSizePolicy(QSizePolicy::ExpandFlag);
    //this->ui->Preview->
            //setLayout(QLayout::SetMaximumSize);
    this->ui->ExpandableScroller_1->WidgetToScroll = ui->scrollArea_2;
    this->ui->ExpandableScroller_1->WidgetToProtect = ui->scrollArea;
    //this->ui->ExpandableScroller_1->DefaultWidth = ui->scrollArea_2->width();

    //QWidgetToolbar* tool = new QWidgetToolbar();

    connect(ui->Canvas,SIGNAL(RequestCurrentTool()),this,SLOT(CurrentToolRequest()));
    connect(this,SIGNAL(GetcurrentToolFromBar()),ui->Toolbar,SLOT(CurrentToolRequested()));
    connect(ui->Toolbar,SIGNAL(SendCurrentTool(BaseToolClass*)),this,SLOT(AquiredCurrentTool(BaseToolClass*)));
    connect(this,SIGNAL(SendCanvasCurrentTool(BaseToolClass*)),ui->Canvas,SLOT(RecieveTool(BaseToolClass*)));
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
        ui->AnimationStrip->addQImage(QPixmap::fromImage(t), ui->Canvas->getAllCompositeImages().indexOf(ui->Canvas->getActiveCanvasImage()));



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

    // update animation bar
//    ui->AnimationStrip->addQImage(QPixmap::fromImage(*ui->Canvas->getActiveCanvasImage()),
//                                  ui->Canvas->getAllCompositeImages().indexOf(ui->Canvas->getActiveCanvasImage()));

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
    //Add new canvas and update display
    addCanvas();
    ui->Canvas->update();

    // Add current canvas to animation strip
    // TODO: MAKE THIS AN EMITTED RESPONSE.
    ui->AnimationStrip->addQImage(QPixmap::fromImage(*ui->Canvas->getActiveCanvasImage()),
                                  ui->Canvas->getAllCompositeImages().indexOf(ui->Canvas->getActiveCanvasImage()));

    // TODO: ERROR CHECK

}

/*
 *
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
        // If the user didn't dismiss the dialog, do something with the fields

        int width = fields[0]->text().toInt();
        int height = fields[1]->text().toInt();
        QVector<QImage*> canvasVector;
        Canvas* defaultCanvas = new Canvas(width, height);
        canvasVector.push_back(defaultCanvas->GetImage());
        QString fileName = SaveFile(width, height, 1, canvasVector);
        LoadFile(fileName);

    }
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
 *
 */
void MainWindow::resizeEvent(QResizeEvent *event)
{
    //MainWindow::resizeEvent(event);
    if(this)
    {
        //int deltaChange = event->oldSize().width() - event->size().width();
        //int oldMinimum = this->ui->scrollArea_2->minimumWidth();

        //this->ui->scrollArea_2->setMinimumWidth(oldMinimum + deltaChange);
    }
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

void MainWindow::CurrentToolRequest()
{
    emit GetcurrentToolFromBar();
}

void MainWindow::AquiredCurrentTool(BaseToolClass * tool)
{
    emit SendCanvasCurrentTool(tool);
}

