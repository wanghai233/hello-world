#include "mytime.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myTime w;
    w.show();

    return a.exec();
}
