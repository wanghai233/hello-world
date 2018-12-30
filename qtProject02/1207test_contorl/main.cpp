#include "mycontrol.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mycontrol w;
    w.show();

    return a.exec();
}
