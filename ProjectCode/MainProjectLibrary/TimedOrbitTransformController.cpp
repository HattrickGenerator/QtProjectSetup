#include "TimedOrbitTransformController.h"

TimedOrbitTransformController::TimedOrbitTransformController(QObject *parent): QObject(parent)
{
    m_timer.setInterval(m_updateTime);

    //Set up orbit

    //Set up rotation
    //m_incrementRotationQuaternion = QQuaternion::fromAxisAndAngle(m_orbitRotAxis, getUpdateAngle(m_orbitDuration));

    //Set up increment Quaternions
    setIncrementQuaternions();

    //Connect
    connect(&m_timer, &QTimer::timeout, this, &TimedOrbitTransformController::timerUpdate);
}



void  TimedOrbitTransformController::timerUpdate()
{
    if(m_target != nullptr)
    {
        m_orbitTranslationBase = m_incrementOrbitQuaternion.rotatedVector(m_orbitTranslationBase);
        m_target->setTranslation(m_orbitTranslationBase);

        m_rotationBaseQuat =  m_incrementRotationQuaternion * m_rotationBaseQuat;
        m_target->setRotation(m_rotationBaseQuat);
    }
}

float TimedOrbitTransformController::getUpdateAngle(std::chrono::milliseconds periodDuration) const
{
    return 1/float(periodDuration.count()) * m_updateTime.count() *360;
}

void TimedOrbitTransformController::setIncrementQuaternions()
{
    m_incrementOrbitQuaternion = QQuaternion::fromAxisAndAngle(m_orbitRotAxis, getUpdateAngle(m_orbitDuration));
    m_incrementRotationQuaternion = QQuaternion::fromAxisAndAngle(m_rotationRotAxis, getUpdateAngle(m_rotationDuration));
}

void TimedOrbitTransformController::setTarget(Qt3DCore::QTransform *target)
{
    m_target = target;
}

void TimedOrbitTransformController::setUpdateTime(std::chrono::milliseconds updateTime)
{
    m_updateTime = updateTime;
    m_timer.setInterval(m_updateTime);
    setIncrementQuaternions();
}

void TimedOrbitTransformController::setOrbitDuration(std::chrono::milliseconds rotationDuration)
{
    m_orbitDuration = rotationDuration;
    setIncrementQuaternions();
}

void TimedOrbitTransformController::setRotationRotAxis(const QVector3D &vec)
{
    m_rotationRotAxis = vec;
    setIncrementQuaternions();
}

void TimedOrbitTransformController::setRotationBaseQuat(const QQuaternion &quat)
{
    m_rotationBaseQuat = quat;
}

void TimedOrbitTransformController::setRotationDuration(std::chrono::milliseconds duration)
{
    m_rotationDuration = duration;
    setIncrementQuaternions();
}

void TimedOrbitTransformController::start()
{
    m_timer.start();
}

void TimedOrbitTransformController::stop()
{
    m_timer.stop();
}

void TimedOrbitTransformController::setOrbitRotAxis(const QVector3D &vec)
{
    m_orbitRotAxis = vec;
    setIncrementQuaternions();
}


void TimedOrbitTransformController::setOrbitTranslationBase(const QVector3D &vec)
{
    m_orbitTranslationBase = vec;
    setIncrementQuaternions();
}

