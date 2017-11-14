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
    QSize canvasSize;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString SaveFile(int width, int height, int frames, QVector<QImage*> images);
    void LoadFile(QString);
    QPushButton* canvas_ShrinkScale;
    QPushButton* canvas_GrowScale;
    QWidget *wrap(QLayout *l);
    void resizeEvent(QResizeEvent *event);
    void CurrentToolRequest();
    void AquiredCurrentTool(BaseToolClass *tool);
    void restoreDefaultUI();

signals:
    void addCanvas(QSize);
    void addToStrip(QPixmap, int);
    void loadImage(QImage*);
	void exportToGIF(const QString&, const QVector<QImage*>&, int, int);

    //Signals to update tool info between canvas and toolbar
    void GetcurrentToolFromBar();
    void SendCanvasCurrentTool(BaseToolClass*);

private slots:
    void sendPreviewImages(QVector<QImage*> images);
    void updatePreviewButtonStatus(bool isActive);
    void onCanvasIconClicked(QListWidgetItem* item);
    void exportGIF();
    void on_addCanvasButton_clicked();
    void on_fpsSpeedSlider_valueChanged(int value);
    void on_actionSave_triggered();
    void on_actionLoad_triggered();
    void on_actionNew_triggered();
    void on_previewButton_clicked();
    void on_fullPreviewButton_clicked();
    void on_canvas_ShrinkButton_clicked();
    void on_canvas_GrowButton_clicked();
};

#endif // MAINWINDOW_H
