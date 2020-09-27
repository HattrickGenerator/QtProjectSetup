#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QLabel>

#pragma once

class LabelSlider : public QWidget
{
    Q_OBJECT

public:
    LabelSlider(Qt::Orientation orientation, const QString & label, QWidget *parent = nullptr);
    LabelSlider(const QString & label, QWidget *parent = nullptr);
    LabelSlider(QWidget *parent = nullptr);

    void SetLabel(const QString & label);
    void SetValue(int val);


signals:
    void valueChanged(int val);

private slots:
    void sliderValueChanged(int val);


private:
   void initWidget();
   void connect();

    QBoxLayout * m_layout;    //base class to layout we want to have

    QSlider m_slider;
    QLabel m_label;
    enum Qt::Orientation m_orientation = Qt::Horizontal;

};
