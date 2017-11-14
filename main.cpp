#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Creates an instance of a GifExporter for signal/slot purposes
    GifExporter gifModel;

    MainWindow w(gifModel);
    w.show();
    return a.exec();
}
