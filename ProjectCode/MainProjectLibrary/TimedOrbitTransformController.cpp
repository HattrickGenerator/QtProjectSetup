#include "TimedOrbitTransformController.h"

TimedOrbitTransformController::TimedOrbitTransformController(QObject *parent): QObject(parent)
{
    timer = new QTimer(this);
    timer->setInterval(m_updateRate);

    m_incrementRotationQuaternion = QQuaternion::fromAxisAndAngle(m_rotAxis, getUpdateAngle());
    connect(timer, &QTimer::timeout, this, &TimedOrbitTransformController::timerUpdate);
    timer->start();
}



void  TimedOrbitTransformController::timerUpdate()
{
    if(m_target != nullptr)
    {
        m_translationBase = m_incrementRotationQuaternion.rotatedVector(m_translationBase);
        m_target->setTranslation(m_translationBase);
    }
}

float TimedOrbitTransformController::getUpdateAngle() const
{
    return 1/float(m_rotationDuration.count()) * m_updateRate.count() *360;

    //return (m_rotationFrequency_Hz * m_updateRate)/1000 * 360;
}

void TimedOrbitTransformController::setIncrementQuaternion()
{
    m_incrementRotationQuaternion = QQuaternion::fromAxisAndAngle(m_rotAxis, getUpdateAngle());
}

void TimedOrbitTransformController::setTarget(Qt3DCore::QTransform *target)
{
    m_target = target;
}

void TimedOrbitTransformController::setUpdateTime(std::chrono::milliseconds updateTime)
{
    m_rotationDuration = updateTime;
    timer->setInterval(m_updateRate);
    setIncrementQuaternion();
}

void TimedOrbitTransformController::setRotationDuration(std::chrono::milliseconds rotationDuration)
{
    m_rotationDuration = rotationDuration;
    setIncrementQuaternion();
}

void TimedOrbitTransformController::setRotationAxis(const QVector3D &vec)
{
    m_rotAxis = vec;
    setIncrementQuaternion();
}


void TimedOrbitTransformController::setTranslationBase(const QVector3D &vec)
{
    m_translationBase = vec;
    setIncrementQuaternion();
}

