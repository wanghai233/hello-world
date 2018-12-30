#include "testpicture.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testPicture w;
    w.show();

    return a.exec();
}
