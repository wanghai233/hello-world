#include "mywidget.h"
#include <QApplication>
extern int flag = 0;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myWidget w;
    w.show();

    return a.exec();
}
