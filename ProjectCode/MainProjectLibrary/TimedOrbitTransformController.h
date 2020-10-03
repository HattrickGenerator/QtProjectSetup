#ifndef TIMEDORBITTRANSFORMCONTROLLER_H
#define TIMEDORBITTRANSFORMCONTROLLER_H

#include <QObject>
#include <QQuaternion>
#include <QTimer>
#include <Qt3DCore/QTransform>
#include <chrono>

class TimedOrbitTransformController : public QObject
{
    Q_OBJECT

public:
    TimedOrbitTransformController(QObject * parent = nullptr);

    void setTarget( Qt3DCore::QTransform * target);
    void setUpdateTime( std::chrono::milliseconds updateTime);
    void start();
    void stop();

    // Orbit Controller
    void setOrbitRotAxis(const QVector3D & vec);
    void setOrbitTranslationBase(const QVector3D & vec);
    void setOrbitDuration(std::chrono::milliseconds duration);

    //Rotation Controller
    void setRotationRotAxis(const QVector3D & vec);
    void setRotationBaseQuat(const QQuaternion & quat);
    void setRotationDuration(std::chrono::milliseconds duration);

private slots:
    void timerUpdate();

private:
    //Functions
    float getUpdateAngle(std::chrono::milliseconds duration) const;

    //Members
    Qt3DCore::QTransform * m_target;    //Non owning

    //Orbit Members
    QVector3D m_orbitRotAxis;
    QVector3D m_orbitTranslationBase;
    QQuaternion m_incrementOrbitQuaternion;
    std::chrono::milliseconds m_orbitDuration = std::chrono::milliseconds(2000);

    //Rotatoin Members
    QQuaternion m_rotationBaseQuat;
    QVector3D m_rotationRotAxis;
    QQuaternion m_incrementRotationQuaternion;
    std::chrono::milliseconds m_rotationDuration = std::chrono::milliseconds(2000);

    //Timer
    QTimer m_timer;
    std::chrono::milliseconds m_updateTime = std::chrono::milliseconds(10);


    //Set increment Quaternion
    void setIncrementQuaternions();

};


#endif // TIMEDORBITTRANSFORMCONTROLLER_H
