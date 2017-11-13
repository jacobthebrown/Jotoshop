#ifndef FULLPREVIEWWINDOW_H
#define FULLPREVIEWWINDOW_H

#include <QWidget>

namespace Ui {
class FullPreviewWindow;
}

class FullPreviewWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FullPreviewWindow(QWidget *parent = 0);
    ~FullPreviewWindow();

private:
    Ui::FullPreviewWindow *ui;
};

#endif // FULLPREVIEWWINDOW_H
