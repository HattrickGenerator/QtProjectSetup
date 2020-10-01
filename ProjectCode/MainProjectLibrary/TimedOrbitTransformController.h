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

    void setRotationAxis(const QVector3D & vec);
    void setTranslationBase(const QVector3D & vec);
    void setTarget( Qt3DCore::QTransform * target);

    void setUpdateTime( std::chrono::milliseconds updateTime);
    void setRotationDuration(std::chrono::milliseconds duration);

private slots:
    void timerUpdate();

private:
    //Functions
    float getUpdateAngle() const;

    //Members
    Qt3DCore::QTransform * m_target;    //Non owning

    QVector3D m_rotAxis;
    QVector3D m_translationBase;
    QQuaternion m_incrementRotationQuaternion;


    QTimer* timer;
    std::chrono::milliseconds m_updateRate = std::chrono::milliseconds(10);
    std::chrono::milliseconds m_rotationDuration = std::chrono::milliseconds(2000);
    float m_rotationFrequency_Hz = 0.5; // Default value

    void setIncrementQuaternion();

};


#endif // TIMEDORBITTRANSFORMCONTROLLER_H
