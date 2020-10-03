#include <Widget3DControlCenter.h>

Widget3DControlCenter::Widget3DControlCenter(QWidget *parent) :QWidget(parent)
{
   orbitSpeedSlider.SetValue(49);
   rotationSpeedSlider.SetValue(49);


   layout.addWidget(&orbitSpeedSlider);
   layout.addWidget(&rotationSpeedSlider);

   setLayout(&layout);

   connectWidgets();
}


void Widget3DControlCenter::connectWidgets()
{
    QObject::connect(&orbitSpeedSlider, &LabelSlider::valueChanged, this, &Widget3DControlCenter::orbitSpeedSliderValChanged);
    QObject::connect(&rotationSpeedSlider, &LabelSlider::valueChanged, this, &Widget3DControlCenter::rotationSpeedSliderValChanged);
}


//Slots
void Widget3DControlCenter::orbitSpeedSliderValChanged(int val)
{
    emit OrbitSpeedSliderValChanged(val);
}

void Widget3DControlCenter::rotationSpeedSliderValChanged(int val)
{
    emit RotationSpeedSliderValChanged(val);
}
