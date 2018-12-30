#ifndef MYCONTROL_H
#define MYCONTROL_H

#include <QMainWindow>

namespace Ui {
class Mycontrol;
}

class Mycontrol : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mycontrol(QWidget *parent = 0);
    ~Mycontrol();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Mycontrol *ui;
};

#endif // MYCONTROL_H
