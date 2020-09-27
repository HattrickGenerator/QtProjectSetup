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
    void SpeedSliderValChanged(int); //Signal

private slots:
    void speedSliderValChanged(int);    //Slot





private:
    void connectWidgets();

    QVBoxLayout layout;
    LabelSlider slider{"Rotation Speed: "};
};
