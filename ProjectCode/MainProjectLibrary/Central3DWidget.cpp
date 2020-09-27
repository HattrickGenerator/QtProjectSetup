#include "Central3DWidget.h"

Central3DWidget::Central3DWidget(QWidget * parent) : QWidget(parent)
{
    layout = new QHBoxLayout();
    containerWidget = new Widget3DContainer(this);
    controlWidget = new Widget3DControlCenter(this);

    splitter = new QSplitter(Qt::Horizontal, this);
    splitter->addWidget(containerWidget);
    splitter->addWidget(controlWidget);
    splitter->setStretchFactor(0, 20);
    splitter->setStretchFactor(1, 1);

    layout->addWidget(splitter);
    setLayout(layout);

    connectWidgets();
}


void Central3DWidget::connectWidgets()
{
    QObject::connect(controlWidget, &Widget3DControlCenter::SpeedSliderValChanged, containerWidget, &Widget3DContainer::changeSpeed);
}
