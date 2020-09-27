#include <QWidget>
#include <QHBoxLayout>
#include <QSplitter>

#include "Widget3DContainer.h"
#include "Widget3DControlCenter.h"

#pragma once

class Central3DWidget : public QWidget
{
    Q_OBJECT

public:
    Central3DWidget(QWidget *parent = nullptr);


private:
    void connectWidgets();

    QSplitter *splitter;
    Widget3DContainer * containerWidget;
    Widget3DControlCenter * controlWidget;
    QHBoxLayout *layout;
};
