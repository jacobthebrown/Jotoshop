#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GifExporter gifModel;
    MainWindow w(gifModel);
    w.show();

    return a.exec();
}
