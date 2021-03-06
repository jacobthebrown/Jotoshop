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

    // Initial set up of ui
    ui->setupUi(this);
    this->setWindowTitle("JotoShop");
    this->canvasSize = QSize(0,0);

    // Connects canvas widget images with preview widget images
    connect(this, SIGNAL(addToStrip(QPixmap, int)), ui->AnimationStrip, SLOT(addQImage(QPixmap,int)));
    connect(ui->Canvas, SIGNAL(sendImages(QVector<QImage*>)), this, SLOT(sendPreviewImages(QVector<QImage*>)));
    connect(ui->Preview,SIGNAL(activityStatus(bool)),this,SLOT(updatePreviewButtonStatus(bool)));

    // Connects "Export to GIF" menu button to the gif exporting logic
    connect(ui->exportAction, &QAction::triggered, this, &MainWindow::exportGIF);
    connect(this, &MainWindow::exportToGIF, &gifModel, &GifExporter::exportToGIF);

    // Connects canvas widget images with animation strip
	connect(ui->AnimationStrip, SIGNAL(sendClickedCanvas(QListWidgetItem*)), this, SLOT(onCanvasIconClicked(QListWidgetItem*)));

    // Connects canvas and animation strip
    connect(ui->Canvas, SIGNAL(ImageUpdate(QImage*,int)), ui->AnimationStrip, SLOT(refreshImage(QImage*,int)) );

    // Assigning scroller children.
    this->ui->ExpandableScroller_1->WidgetToScroll = ui->scrollArea_2;
    this->ui->ExpandableScroller_1->WidgetToProtect = ui->scrollArea;

    // TODO
    connect(ui->Canvas,SIGNAL(grabTool()),ui->Toolbar,SLOT(giveTool()));
    connect(ui->Toolbar, SIGNAL(tool(BaseToolClass*)),ui->Canvas, SLOT(currentTool(BaseToolClass*)));
    
    // Scroll set up
    this->ui->ExpandableScroller_1->WidgetToScroll = ui->scrollArea_2;
    this->ui->ExpandableScroller_1->WidgetToProtect = ui->scrollArea;

    // Begin setup with a add new action
    emit ui->actionNew->triggered();

    //TODO
    connect(ui->Canvas,SIGNAL(returnDropperColor(QColor)),ui->Toolbar,SLOT(setDropperColor(QColor)));
}

/*
 * Destructor for main window
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Exports the images in the vectors to a Gif
 * TODO: SET FPS OF GIF.
 */
void MainWindow::exportGIF()
{
    // Dialog to get gif export path.
    const QString fileName = QFileDialog::getSaveFileName(this, tr("Export to GIF"), "C:/Users/Sam/Documents", tr("Image Files (*.gif)"));

    // Grab all the Canvas images and push them into a vector.
    QVector<QImage*> temp;
    foreach (QImage *im, ui->Canvas->getAllCompositeImages())
    {
        QImage* ima = new QImage;
        *ima = *im;
        temp.push_back(ima);
    }

    int width = ui->Canvas->width();
    int height = ui->Canvas->height();


    emit exportToGIF(fileName, temp, width, height);
}



/*
 * Queries the user to choose a file name and directory
 * Throws an error if the path is invalid
 * Writes the HxW followed by number of frames and each frame's pixels in rgba fashion
 */
QString MainWindow::saveFile(int width, int height, int frames, QVector<QImage*> images)
{
    // Grabs the filename saved; forcing the filter to be the extension
    const QString filter = "(*.ssp)";
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save File"),tr(".ssp"),filter);

    if (fileName.length() <= 0) {
        return "";
    }

    QFile file(fileName);

    // Throws a warning dialog box if the file won't open
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Save Error","Error saving file! No permissions to read.");
        return "";
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
 * Queries the user to load a .ssp file
 * Throws and error if the file is corrupt
 * Empties vectors or previous project if there was one
 * Reads the ssp line by line constructing the images and displaying them accordingly
 */
void MainWindow::loadFile(QString fileName)
{
    QFile file(fileName);

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Error", "Couldn't Open File");
        return;
    }
    int height, width, frames;

    QStringList lineSplit;
    QString line;
    QTextStream in(&file);

    line = in.readLine();
    lineSplit = line.split(' ');

    height = lineSplit[0].toInt();
    width = lineSplit[1].toInt();

    line = in.readLine();
    frames = line.toInt();

    QImage *im;

    int row = 0, col = 0;

    canvasSize.setHeight(height);
    canvasSize.setWidth(width);
    this->ui->Canvas->resize(this->canvasSize.width(), this->canvasSize.height(), 1.0);


    for(int z = 0; z < frames; z++)
    {
        im = new QImage(width, height, QImage::Format_ARGB32);
        for(int y = 0; y < height; y++)
        {
            line = in.readLine();
            lineSplit = line.split(' ');
            for(int x = 0; x < lineSplit.size(); x += 4)
            {
                im->setPixel(col,row,qRgba(lineSplit[x].toInt(),lineSplit[x + 1].toInt(),lineSplit[x + 2].toInt(),lineSplit[x + 3].toInt()));
                col++;
                if(col == width)
                    col = 0;
            }
            row++;
            if(row == height)
                row = 0;

        }

        this->ui->Canvas->addCanvas(im);

    }

    int iteration = 1;
    foreach (Canvas* canvas, ui->Canvas->composites)
    {
        emit addToStrip(QPixmap::fromImage(*canvas->GetImage()), iteration);
        iteration++;
    }

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
    if(isActive) {
        ui->previewButton->setText("Stop Preview");
        ui->previewButton->setStyleSheet(QString("color: orange;"));
        ui->fullPreviewButton->setEnabled(true);
    }
    else {
        ui->previewButton->setText("Start Preview");
        ui->previewButton->setStyleSheet(QString("color: silver;"));
        ui->fullPreviewButton->setEnabled(false);
    }
}
/*
 * Handler for when an icon is clicked on the animation strip
 */
void MainWindow::onCanvasIconClicked(QListWidgetItem *item)
{

    for(int i = 0; i < ui->AnimationStrip->listArea->count(); i++)
    {
        if (ui->AnimationStrip->listArea->item(i) == item)
        {
            ui->Canvas->setActiveCanvas(ui->Canvas->composites.at(i));
            ui->Canvas->update();
        }
    }
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
 * TODO
 */
void MainWindow::on_actionSave_triggered()
{
    QVector<QImage*> canvasVector = ui->Canvas->getAllCompositeImages();
    saveFile((canvasVector[0])->width(), (canvasVector[0])->height(), canvasVector.count(), canvasVector);
}

/*
 * Prompts the user to enter a new size for the sprite. This size will be used for later canvas creation.
 * Restores the UI back to its default state (only now with a different sized QCanvasWidget)
 */
void MainWindow::on_actionNew_triggered()
{
    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);

    // Add some text above the fields
    form.addRow(new QLabel("Please select an initial non-zero size for the Canvas:"));

    QList<QLineEdit*> fields;
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
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));



    // Show the dialog as modal
    if (dialog.exec() == QDialog::Accepted)
    {
        // restore ui to its default state
        restoreDefaultUI();

        // If the user didn't dismiss the dialog, do something with the fields
        int width = fields[0]->text().toInt();
        int height = fields[1]->text().toInt();

        if (width == 0 || height == 0)
        {
            on_actionNew_triggered();
            return;
        }

        // Reset, canvas size.
        canvasSize = QSize(width, height);
        this->ui->Canvas->resize(this->canvasSize.width(),this->canvasSize.height(),1.0);
    }

    else
    {
        if (canvasSize.height() == 0 && canvasSize.width() == 0)
        {
            on_actionNew_triggered();
            return;
        }
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
    ui->previewButton->setText("Start Preview");
    ui->fullPreviewButton->setEnabled(false);
    ui->previewButton->setStyleSheet(QString("color: silver;"));
    ui->canvas_scaleSlider->setValue(100);
}

/*
 * Starts the Loadfile processes
 */
void MainWindow::on_actionLoad_triggered()
{
    // Creates a dialog to select a project to load.
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load Project"), "", tr("*.ssp"));

    if (fileName.length() > 0) {
        this->restoreDefaultUI();
        loadFile(fileName);
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

/*
 * Handles the transfer of the paint tool between widget
 */
void MainWindow::currentToolRequest()
{
    emit getcurrentToolFromBar();
}

/*
 * Handles the transfer of the paint tool between widget
 */
void MainWindow::aquiredCurrentTool(BaseToolClass * tool)
{
    emit sendCanvasCurrentTool(tool);
}

/*
 * Handler for grow button
 * For increasing canvas zoom view
 */
void MainWindow::on_canvas_GrowButton_clicked()
{
    ui->Canvas->shiftScale(+0.25);
}

/*
 * Handler for shrink button
 * For decreasing canvas zoom view
 */
void MainWindow::on_canvas_ShrinkButton_clicked()
{
    ui->Canvas->shiftScale(-0.25);
}

/*
 * Handler for clone last button
 * Takes the last canvas on animation strip
 * and makes a copy to canvas list
 */
void MainWindow::on_animationstrip_CloneButton_clicked()
{
    if (ui->Canvas->composites.length() == 0)
        return;

    ui->Canvas->addCanvas(ui->Canvas->composites.last()->GetImage());
    ui->Canvas->update();

    if(ui->Canvas->getAllCompositeImages().count() > 0)
    {
        int framePos = ui->Canvas->composites.length() - 1;
        emit addToStrip(QPixmap::fromImage(*(ui->Canvas->composites.last()->GetImage())), framePos);
    }
}

/*
 * Handler for clone current button
 * Takes the selected canvas on animation strip
 * and makes a copy to canvas list
 */
void MainWindow::on_animationstrip_CloneCurrentButton_clicked()
{
    if (ui->Canvas->getActiveCanvas() == nullptr)
        return;

    ui->Canvas->addCanvas(ui->Canvas->getActiveCanvas()->GetImage());
    ui->Canvas->update();

    if(ui->Canvas->getAllCompositeImages().count() > 0)
    {
        int framePos = ui->Canvas->composites.length() - 1;
        emit addToStrip(QPixmap::fromImage(*(ui->Canvas->getActiveCanvas()->GetImage())), framePos);
    }
}

/*
 * Handler for new canvas button
 * adds a new canvas to animation strip
 * and canvas editing area
 */
void MainWindow::on_animationstrip_NewButton_clicked()
{
    ui->Canvas->addCanvas();
    ui->Canvas->update();

    if(ui->Canvas->getAllCompositeImages().count() > 0)
    {
        int framePos = ui->Canvas->composites.length() - 1;
        emit addToStrip(QPixmap::fromImage(*(ui->Canvas->getActiveCanvas()->GetImage())), framePos);
    }
}

/*
 * Handler for delete button
 * Deletes the selected canvas item from animation strip
 * Makes sure all aspects using deleted canvas are updated
 */
void MainWindow::on_animationstrip_DeleteCurrentButton_clicked()
{

    if (ui->Canvas->getActiveCanvas() == nullptr)
        return;

    int indexOfDeletion = ui->Canvas->composites.indexOf(ui->Canvas->getActiveCanvas());

    ui->Canvas->composites.removeOne(ui->Canvas->getActiveCanvas());

    delete ui->Canvas->getActiveCanvas();
    ui->Canvas->setActiveCanvas(nullptr);

    ui->AnimationStrip->clear();
    int iteration = 1;

    foreach (Canvas* canvas, ui->Canvas->composites)
    {
        emit addToStrip(QPixmap::fromImage(*canvas->GetImage()), iteration);
        iteration++;
    }

    if (ui->Canvas->composites.length() > indexOfDeletion - 1 && indexOfDeletion - 1 >= 0) {
        ui->Canvas->setActiveCanvas(ui->Canvas->composites.at(indexOfDeletion - 1));
        ui->AnimationStrip->listArea->item(indexOfDeletion - 1)->setSelected(true);
    }
    else if (indexOfDeletion == 0 && ui->Canvas->composites.length() > 0) {
        ui->Canvas->setActiveCanvas(ui->Canvas->composites.at(0));
        ui->AnimationStrip->listArea->item(0)->setSelected(true);
    }

    // Make sure preview is up to date
    sendPreviewImages(ui->Canvas->getAllCompositeImages());

}

/*
 * Handler for scale slider, adjusts scale of canvas
 */
void MainWindow::on_canvas_scaleSlider_sliderMoved(int position)
{
   this->ui->Canvas->setScale(1.0 * ((position + 0.0)/100.0));
}
