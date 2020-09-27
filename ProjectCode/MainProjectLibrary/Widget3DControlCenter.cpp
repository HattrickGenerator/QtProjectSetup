#include <Widget3DControlCenter.h>

Widget3DControlCenter::Widget3DControlCenter(QWidget *parent) :QWidget(parent)
{
   slider.SetValue(49);
   layout.addWidget(&slider);
   setLayout(&layout);

   connectWidgets();
}


void Widget3DControlCenter::connectWidgets()
{
    QObject::connect(&slider, &LabelSlider::valueChanged, this, &Widget3DControlCenter::speedSliderValChanged);
}


//Slots
void Widget3DControlCenter::speedSliderValChanged(int val)
{
    emit SpeedSliderValChanged(val);
}
