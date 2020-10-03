#include <QWidget>
#include <QHBoxLayout>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QOrbitCameraController>

#include "OrbitTransformController.h"
#include "TimedOrbitTransformController.h"

#include <Qt3DCore/QEntity>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QCameraLens>
#include <Qt3DCore/QTransform>
#include <Qt3DCore/QAspectEngine>
#include <Qt3DInput/QInputAspect>
#include <Qt3DRender/QRenderAspect>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QTorusMesh>
#include <QPropertyAnimation>
#include <cmath>

#include "OrbitTransformController.h"

#pragma once

class Widget3DContainer : public QWidget
{
    Q_OBJECT

public:
    Widget3DContainer(QWidget *parent = nullptr);

public slots:
    void changeOrbitSpeed(int percent);
    void changeRotationSpeed(int percent);

private:
    Qt3DCore::QEntity *createScene();
    QWidget *container;

    //Speed
    TimedOrbitTransformController *controller;

    long calcLogPercentageTransform(long percent);

};
