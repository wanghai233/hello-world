#include "student.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    student w;
    w.show();

    return a.exec();
}
