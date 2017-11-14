#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Creates an instance of a GifExporter for signal/slot purposes
    GifExporter gifModel;

    MainWindow w(gifModel);
    a.setWindowIcon(QIcon(":/Images/icons/Resources/application_icon.ico"));
    w.show();
    return a.exec();
}
