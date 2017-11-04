#ifndef TOOLSMODEL_H
#define TOOLSMODEL_H
#include <QObject>
#include <QWidget>

class ToolsModel : public QObject
{

    Q_OBJECT
public:
    ToolsModel();
    QRgb getColor();

private:
    QRgb currentColor;
    qint32 brushWidth;

public slots:
    void SetColor(QColor);

};

#endif // TOOLSMODEL_H
