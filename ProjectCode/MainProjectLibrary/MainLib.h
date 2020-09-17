#include <QMainWindow>
#include <QVBoxLayout>
//#include "ButtonWidget.h"
//#include "LightWidget.h"

#include <QPushButton>
#include "Widget3DContainer.h"

#include <QQuickView>
#include <Qt3DExtras/Qt3DWindow>
#include <QOrbitCameraController>


class CustomMainWindow : public QMainWindow
{
    Q_OBJECT

public:

 CustomMainWindow() : QMainWindow()
    {
    mainWidget = new QWidget();
     layout = new QVBoxLayout();
     containerWidget = new Widget3DContainer(this);
    layout->addWidget(containerWidget);
     mainWidget->setLayout(layout);
     setCentralWidget(mainWidget);

    }

public:
    virtual void closeEvent ( QCloseEvent * event )
 {
     delete containerWidget;
     event->accept();
 }

signals:
 void mainWindowClosed();

private:
    Widget3DContainer* containerWidget;
    QWidget *mainWidget;
    QVBoxLayout *layout;
};
