#ifndef MYTIME_H
#define MYTIME_H

#include <QDialog>
#include <QTimer>
namespace Ui {
class myTime;
}

class myTime : public QDialog
{
    Q_OBJECT

public:
    explicit myTime(QWidget *parent = 0);
    ~myTime();
public slots:
    void mySlot();

private slots:
    void on_button_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

private:
    Ui::myTime *ui;
    QTimer *time;
};

#endif // MYTIME_H
