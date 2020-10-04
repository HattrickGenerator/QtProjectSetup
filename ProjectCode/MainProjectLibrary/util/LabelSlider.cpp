#include "LabelSlider.h"

LabelSlider::LabelSlider(Qt::Orientation orientation, const QString &label, QWidget *parent) : QWidget(parent)
{
    m_orientation = orientation;
    m_label.setText(label);
    initWidget();
}

LabelSlider::LabelSlider(const QString &label, QWidget *parent) : QWidget(parent)
{
    m_label.setText(label);
    initWidget();
}

LabelSlider::LabelSlider(QWidget * parent) : QWidget(parent)
{
    initWidget();
}

void LabelSlider::SetLabel(const QString &label)
{
    m_label.setText(label);
}


void LabelSlider::SetValue(int value)
{
    m_slider.setValue(value);
}

void LabelSlider::setTickInterval(int ti)
{
    m_slider.setTickInterval(ti);
}

void LabelSlider::setTickPosition(QSlider::TickPosition position)
{
    m_slider.setTickPosition(position);
}

int LabelSlider::tickInterval() const
{
    return m_slider.tickInterval();
}

void LabelSlider::connect()
{
    QObject::connect(&m_slider, &QSlider::valueChanged, this, &LabelSlider::sliderValueChanged);
}

void LabelSlider::sliderValueChanged(int val)
{
    emit valueChanged(val);
}

void LabelSlider::initWidget()
{
    m_layout = m_orientation == Qt::Horizontal ? static_cast<QBoxLayout*>(new QHBoxLayout(this)) :  static_cast<QBoxLayout*>(new QVBoxLayout(this)) ;
    m_slider.setOrientation(m_orientation);

    m_layout->addWidget(&m_label);
    m_layout->addWidget(&m_slider);
    setLayout(m_layout);

    connect();
}
