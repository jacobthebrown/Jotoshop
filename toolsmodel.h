#ifndef TOOLSMODEL_H
#define TOOLSMODEL_H
#include <QObject>
#include <QWidget>
#include <QMouseEvent>

class ToolsModel : public QObject
{

    Q_OBJECT
public:
    ToolsModel();
    QRgb Color();
    QString currentTool;
    qint32 Width();

protected:
    void mouseMoveEvent(QMouseEvent* mouse_event);

private:
    QRgb currentColor;
    qint32 toolWidth;

    qint32 brushWidth;
    qint32 penWidth;
    qint32 eraserWidth;

    void setWidth(qint32);
    void determineTool(QString);

public slots:
    void SetColor(QColor);
    void UpdateTool(QString);
signals:
    void HighlightToolIcon(QString);

};

#endif // TOOLSMODEL_H
