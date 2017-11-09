#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Models/toolsmodel.h"
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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //QLabel *label;

    QLabel *getCanvasAsLabel();
    void SaveFile(int width, int height, int frames, QVector<QImage*> images);


    //ToolsModel toolBar;
    //QImage canvasImage;

    //void SetToolBarPics();
    //Temp function to test brush width
    //void paint(QPoint,QImage&,QRgb,int);

public slots:
    //void recieveSelectedColor(QColor);
    //void paintCanvas(QPoint&);

signals:
    //void updateToolBar(QColor);
    //void ToolClicked(QString);

    void addCanvas();
    void addToStrip(QImage*);

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

    //
    void on_addCanvasButton_clicked();
    void on_fpsSpeedSlider_valueChanged(int value);
    void on_actionSave_triggered();
};

#endif // MAINWINDOW_H
