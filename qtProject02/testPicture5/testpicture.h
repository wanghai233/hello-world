#ifndef TESTPICTURE_H
#define TESTPICTURE_H

#include <QMainWindow>

namespace Ui {
class testPicture;
}

class testPicture : public QMainWindow
{
    Q_OBJECT

public:
    explicit testPicture(QWidget *parent = 0);
    ~testPicture();

private:
    Ui::testPicture *ui;
};

#endif // TESTPICTURE_H
