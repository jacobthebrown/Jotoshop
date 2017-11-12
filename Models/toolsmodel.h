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

    void updateWidth(int);

    void SetColor(QColor);
    void setSecondaryColor(QColor);

    QRgb currentColor;
    QRgb backupColor;
protected:
    void mouseMoveEvent(QMouseEvent* mouse_event);

private:

    int toolWidth;

    int brushWidth;
    int penWidth;
    int eraserWidth;

    void setWidth(int);
    void determineTool(QString);

public slots:
    void UpdateTool(QString);
signals:
    void HighlightToolIcon(QString);
    void SignalDefaultWidth(int);

};

#endif // TOOLSMODEL_H
