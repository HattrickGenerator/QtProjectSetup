#include "Widget3DContainer.h"



    Widget3DContainer::Widget3DContainer(QWidget *parent) :QWidget(parent)
    {
        QHBoxLayout* layout= new QHBoxLayout(this);

        Qt3DExtras::Qt3DWindow* view = new Qt3DExtras::Qt3DWindow();
        Qt3DCore::QEntity * scene = createScene();

      // Camera
      Qt3DRender::QCamera *camera = view->camera();
      camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
      camera->setPosition(QVector3D(0, 0, 40.0f));
      camera->setViewCenter(QVector3D(0, 0, 0));

      // For camera controls
      Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(scene);
      camController->setLinearSpeed( 50.0f );
      camController->setLookSpeed( 180.0f );
      camController->setCamera(camera);

      view->setRootEntity(scene);
      QWidget * container = QWidget::createWindowContainer(view);
    layout->addWidget(container);
     setLayout(layout);

    }

    Widget3DContainer::~Widget3DContainer()
    {
        //delete container;
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
        torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), 45.0f));

        torusEntity->addComponent(torusMesh);
        torusEntity->addComponent(torusTransform);
        torusEntity->addComponent(material);
        Qt3DCore::QEntity *sphereEntity = new Qt3DCore::QEntity(rootEntity);
            Qt3DExtras::QSphereMesh *sphereMesh = new Qt3DExtras::QSphereMesh;
            sphereMesh->setRadius(3);
            sphereMesh->setGenerateTangents(true);

            Qt3DCore::QTransform *sphereTransform = new Qt3DCore::QTransform;
            OrbitTransformController *controller = new OrbitTransformController(sphereTransform);
            controller->setTarget(sphereTransform);
            controller->setRadius(20.0f);

            QPropertyAnimation *sphereRotateTransformAnimation = new QPropertyAnimation(sphereTransform);
            sphereRotateTransformAnimation->setTargetObject(controller);
            sphereRotateTransformAnimation->setPropertyName("angle");
            sphereRotateTransformAnimation->setStartValue(QVariant::fromValue(0));
            sphereRotateTransformAnimation->setEndValue(QVariant::fromValue(360));
            sphereRotateTransformAnimation->setDuration(10000);
            sphereRotateTransformAnimation->setLoopCount(-1);
            sphereRotateTransformAnimation->start();

            sphereEntity->addComponent(sphereMesh);
            sphereEntity->addComponent(sphereTransform);
            sphereEntity->addComponent(material);

            return rootEntity;
    }
