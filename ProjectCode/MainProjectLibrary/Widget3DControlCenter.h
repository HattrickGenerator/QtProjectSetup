#include <QWidget>
#include <QVBoxLayout>
#include <QSlider>

#include "util/LabelSlider.h"

#pragma once



class Widget3DControlCenter : public QWidget
{
    Q_OBJECT

public:
    Widget3DControlCenter(QWidget *parent = nullptr);


signals:
    void OrbitSpeedSliderValChanged(int); //Signal
    void RotationSpeedSliderValChanged(int); //Signal

private slots:
    void orbitSpeedSliderValChanged(int);    //Slot
    void rotationSpeedSliderValChanged(int);    //Slot





private:
    void connectWidgets();

    QVBoxLayout layout;
    LabelSlider orbitSpeedSlider{"Orbit Speed: "};
    LabelSlider rotationSpeedSlider{"Rotation Speed: "};
};

