#include <QMainWindow>
#include <QTextEdit>

class CustomMainWindow : public QMainWindow
{
public:

 CustomMainWindow() : QMainWindow()
    {
     this->setCentralWidget(&mainWidget);
     textEdit.setParent(&mainWidget);
    }

private:
    QWidget mainWidget;
    QTextEdit textEdit;

};
