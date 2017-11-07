#ifndef CLICKEDCOLORRESPONSE_H
#define CLICKEDCOLORRESPONSE_H
#include <QObject>
#include <QMouseEvent>
#include <QColorDialog>
#include <QLabel>

class clickedColorResponse : public QLabel
{
    Q_OBJECT
public:
    clickedColorResponse(QWidget *parent);
private:
    QColorDialog cDialog;

 protected:
    void mousePressEvent(QMouseEvent *mouse_event);

 signals:
    void sendColorSelected(QColor);
};

#endif // CLICKEDCOLORRESPONSE_H
