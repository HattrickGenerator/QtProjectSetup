#include "Window3DSubclass.h"


Window3DSubclass::Window3DSubclass(QScreen * screen)  : Qt3DExtras::Qt3DWindow (screen)
{
}

void Window3DSubclass::setRootEntity(Qt3DCore::QEntity *root)
{
    Qt3DExtras::Qt3DWindow::setRootEntity(root);
    m_rootEntity = root;
    m_transform = new Qt3DCore::QTransform();
    root->addComponent(m_transform);
}


//------------------------------------------------------------------------------
void Window3DSubclass::mousePressEvent(QMouseEvent *event)
//------------------------------------------------------------------------------
{
    m_lastPos = event->pos();
}

void Window3DSubclass::mouseMoveEvent(QMouseEvent *event)
{
    double dx = event->x() - m_lastPos.x();
    double dy = event->y() - m_lastPos.y();

    if (event->buttons() & Qt::LeftButton)
    {
       setXRotation(xRot + 1 * dy);
        setYRotation(yRot + 1 * dx);
    } else if (event->buttons() & Qt::RightButton)
    {
        setXTranslation(xTranslation + 0.1*dx);
        setYTranslation(yTranslation + 0.1*dy);
    }
    m_lastPos = event->pos();
}

bool Window3DSubclass::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress )
    {
        mousePressEvent(static_cast<QMouseEvent*>(event));    //Call function
    }

    return false;
}



//------------------------------------------------------------------------------
static void qNormalizeAngle(double &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}


//------------------------------------------------------------------------------
void Window3DSubclass::setXRotation(double angle)
//------------------------------------------------------------------------------
{
    qNormalizeAngle(angle);
    if (angle != xRot)
    {
        xRot = angle;

       m_transform->setRotationX(angle);
    }
}


//------------------------------------------------------------------------------
void Window3DSubclass::setYRotation(double angle)
//------------------------------------------------------------------------------
{
    qNormalizeAngle(angle);
    if (angle != yRot)
    {
        yRot = angle;

        m_transform->setRotationY(angle);
    }
}

void Window3DSubclass::setXTranslation(double translation)
{
    if (translation != xTranslation) {
        xTranslation = translation;
        m_transform->setTranslation(QVector3D(xTranslation,yTranslation,0));
    }
}

void Window3DSubclass::setYTranslation(double translation)
{
    if (translation != yTranslation) {
        yTranslation = translation;
        m_transform->setTranslation(QVector3D(xTranslation,yTranslation,0));
    }
}


