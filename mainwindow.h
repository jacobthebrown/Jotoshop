#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Models/toolsmodel.h"
#include "Models/gifexporter.h"
#include "Widgets/qwidgetcanvas.h"
#include "Widgets/qwidgetpreview.h"
#include "Widgets/qwidgettoolbar.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(GifExporter&, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void SaveFile(int width, int height, int frames, QVector<QImage*> images);
    void LoadFile();


    //ToolsModel toolBar;
    //QImage canvasImage;

    //void SetToolBarPics();
    //Temp function to test brush width
    //void paint(QPoint,QImage&,QRgb,int);

    QWidget *wrap(QLayout *l);
    void resizeEvent(QResizeEvent *event);
public slots:
    //void recieveSelectedColor(QColor);
    //void paintCanvas(QPoint&);

signals:
    //void updateToolBar(QColor);
    //void ToolClicked(QString);

    void addCanvas();
    void addToStrip(QImage*);
    void loadImage(QImage*);
	void exportToGIF(const QString&, const QVector<QImage*>&, int, int);

private slots:
    /*
    void UpdateButtonBorder(QString);
    void on_paintBrushButton_clicked();
    void on_broadBrushButton_clicked();
    void on_eraserButton_clicked();
    void on_dropperButton_clicked();
*/
    //Canvas
    void sendPreviewImages(QVector<QImage*> images);

    void onCanvasIconClicked(QListWidgetItem* item);

	// Open a file dialog to export the current array of canvases into a gif format
    void exportGIF();

    //
    void on_addCanvasButton_clicked();
    void on_fpsSpeedSlider_valueChanged(int value);
    void on_actionSave_triggered();
    void on_actionLoad_triggered();
};

#endif // MAINWINDOW_H
