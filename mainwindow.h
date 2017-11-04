#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "toolsmodel.h"

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
    ToolsModel toolBar;
    QImage canvasImage;

    void SetToolBarPics();
public slots:
    void recieveSelectedColor(QColor);
    void paintCanvas(QPoint&);

signals:
    void updateToolBar(QColor);
};

#endif // MAINWINDOW_H
