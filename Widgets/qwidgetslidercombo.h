#ifndef QWIDGETSLIDERCOMBO_H
#define QWIDGETSLIDERCOMBO_H

#include <QWidget>
#include <QLabel>
#include <QSlider>

class QWidgetSliderCombo : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetSliderCombo(QWidget *parent = nullptr);
    ~QWidgetSliderCombo();
    QWidgetSliderCombo(QWidget *parent, QString sliderLabel, int xPos, int yPos, int width, int height);
    QSlider* Slider;

private:
    QLabel* SliderLabel;

};

#endif // QWIDGETSLIDERCOMBO_H
