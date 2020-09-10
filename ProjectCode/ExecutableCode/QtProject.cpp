#include <QApplication>
#include <QCoreApplication>
#include <QMainWindow>
#include "MainLib.h"

//Example from Qt Website to differentiate between GUI and non GUI version
 QCoreApplication* createApplication(int &argc, char *argv[])
{
    for (int i = 1; i < argc; ++i) {
        if (!qstrcmp(argv[i], "-no-gui"))
            return new QCoreApplication(argc, argv);
    }
    return new QApplication(argc, argv);
}


int main(int argc, char* argv[])
{
  QScopedPointer<QCoreApplication> app(createApplication(argc, argv));

   if (qobject_cast<QApplication *>(app.data())) {
        CustomMainWindow * mainWindow = new CustomMainWindow();
        mainWindow->show();
    }
    else {
    //start non-GUI version...
   }

    return app->exec();
}
