#include <QMainWindow>
#include <QCloseEvent>
#include <QDesktopWidget>

#include "Central3DWidget.h"


class CustomMainWindow : public QMainWindow
{
    Q_OBJECT

public:

    CustomMainWindow() : QMainWindow()
    {
        mainWidget = new Central3DWidget(this);
        setCentralWidget(mainWidget);

        resize(QDesktopWidget().availableGeometry(this).size() * 0.5);
    }


    virtual void closeEvent ( QCloseEvent * event )
    {
        delete mainWidget;  //It is necessary to call the destrutor here manually. This might be a bug in the 3D window
        event->accept();
    }


private:
    Central3DWidget *mainWidget;
};
