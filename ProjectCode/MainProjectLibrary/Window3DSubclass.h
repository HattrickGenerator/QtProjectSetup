#pragma once
#include <Qt3DExtras>
#include <QPoint>
#include <Qt3DInput>
#include <memory>


class Window3DSubclass : public Qt3DExtras::Qt3DWindow
{
    Q_OBJECT

public:
    Window3DSubclass(QScreen *screen = nullptr);
    void setRootEntity(Qt3DCore::QEntity *root);
    //void connectToRootEntity(Qt3DCore::QEntity * root);

private:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event);

    void setXRotation(double angle);
    void setYRotation(double angle);

    void setXTranslation(double translation);
    void setYTranslation(double translation);

    QPoint m_lastPos;

    Qt3DInput::QMouseDevice * m_mouseDevice;

    double xRot = 0;
    double yRot = 0;
    double zRot = 0;
    double xTranslation = 0;
    double yTranslation = 0;


    Qt3DCore::QTransform * m_transform;
    Qt3DCore::QEntity *m_rootEntity = nullptr;
};
