#include "qwidgetslidercombo.h"

/*
 *  Creates new Slider Combo widget
 */
QWidgetSliderCombo::QWidgetSliderCombo(QWidget *parent, QString sliderLabel, int xPos, int yPos, int width, int height) : QWidget(parent)
{
    // Move outer widget into pos, and set proper size.
    this->move(xPos, yPos);
    this->setMinimumSize(width, height);

    // Create slider object and set it up.
    Slider = new QSlider(Qt::Horizontal, this);
    Slider->move(0, 0 + (height / 2));
    Slider->setTickInterval(5);
    Slider->setRange(0, 100);
    Slider->setSingleStep(1);
    Slider->setMinimumSize(width, height / 2);
    Slider->show();

    // Create a label to display above slider.
    SliderLabel = new QLabel(sliderLabel + ": " +  QString::number(Slider->value()), this);
    SliderLabel ->move(0,0);
    SliderLabel ->setMinimumSize(width, height / 2);
    SliderLabel ->show();

    // Create a trigger for when slider value is changed.
    // Updates Label with current value.
    connect(Slider, &QSlider::valueChanged, this, [this, sliderLabel]() {
        SliderLabel->setText(sliderLabel + QString(": ") +  QString::number(Slider->value()) );
    });

}

/*
 *  Destructor for Slider Combo widget
 */
QWidgetSliderCombo::~QWidgetSliderCombo()
{
    //delete this;
}
