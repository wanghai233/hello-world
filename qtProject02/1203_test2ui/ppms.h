#ifndef PPMS_H
#define PPMS_H

#include <QWidget>

namespace Ui {
class ppms;
}

class ppms : public QWidget
{
    Q_OBJECT

public:
    explicit ppms(QWidget *parent = 0);
    ~ppms();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::ppms *ui;
};

#endif // PPMS_H
