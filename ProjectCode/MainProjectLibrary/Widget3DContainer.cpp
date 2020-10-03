#include "Widget3DContainer.h"



Widget3DContainer::Widget3DContainer(QWidget *parent) :QWidget(parent)
{
    QHBoxLayout* layout= new QHBoxLayout(this);

    Qt3DExtras::Qt3DWindow*   view = new Qt3DExtras::Qt3DWindow();
    Qt3DCore::QEntity* scene = createScene();

    // Camera
    Qt3DRender::QCamera * camera = view->camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0, 0, 40.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));

    // For camera controls
    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(scene);
    camController->setLinearSpeed(50.0f);
    camController->setLookSpeed(180.0f);
    camController->setCamera(camera);

    view->setRootEntity(scene);
    QWidget * container = QWidget::createWindowContainer(view);
    layout->addWidget(container);
    setLayout(layout);

}



Qt3DCore::QEntity * Widget3DContainer::createScene()
{
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;
    Qt3DRender::QMaterial *material = new Qt3DExtras::QPhongMaterial(rootEntity);
    Qt3DCore::QEntity *torusEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QTorusMesh *torusMesh = new Qt3DExtras::QTorusMesh;
    torusMesh->setRadius(5);
    torusMesh->setMinorRadius(1);
    torusMesh->setRings(100);
    torusMesh->setSlices(20);

    Qt3DCore::QTransform *torusTransform = new Qt3DCore::QTransform;
    torusTransform->setScale3D(QVector3D(1.5, 1, 0.5));
    torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), 0));

    torusEntity->addComponent(torusMesh);
    torusEntity->addComponent(torusTransform);
    torusEntity->addComponent(material);
    Qt3DCore::QEntity *sphereEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QSphereMesh *sphereMesh = new Qt3DExtras::QSphereMesh;
    sphereMesh->setRadius(3);
    sphereMesh->setGenerateTangents(true);

    Qt3DCore::QTransform* sphereTransform = new Qt3DCore::QTransform;   //Set up transform for sphere



    controller = new TimedOrbitTransformController(this);
    controller->setTarget(torusTransform);

    controller->setOrbitRotAxis(QVector3D(0, 1,0));
    controller->setOrbitTranslationBase(QVector3D(0, 0, 15));
    controller->setOrbitDuration(std::chrono::milliseconds(3000));

    controller->setRotationBaseQuat(QQuaternion::fromAxisAndAngle(QVector3D(0, 0, 1), 90.0f));
    controller->setRotationRotAxis(QVector3D(0, 1, 0));
    controller->setRotationDuration(std::chrono::milliseconds(3000));

    controller->setUpdateTime(std::chrono::milliseconds(10));



    controller->start();
    sphereEntity->addComponent(sphereMesh);
    sphereEntity->addComponent(sphereTransform);
    sphereEntity->addComponent(material);

    return rootEntity;
}

long Widget3DContainer::calcLogPercentageTransform(long percent)
{
    return long ( -4490 * std::log10(percent) + 10000 );
}


// Slots
void Widget3DContainer::changeOrbitSpeed(int percent)
{
    auto tempDuration = std::chrono::milliseconds(calcLogPercentageTransform(percent));

    controller->setOrbitDuration(tempDuration );
}

void Widget3DContainer::changeRotationSpeed(int percent)
{
    auto tempDuration = std::chrono::milliseconds(calcLogPercentageTransform(percent));

    controller->setRotationDuration(tempDuration );
}


