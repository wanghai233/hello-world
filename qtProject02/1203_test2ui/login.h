#ifndef LOGIN_H
#define LOGIN_H
#include "ppms.h"
#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_pushButtonCancel_clicked();

    void on_pushButtonDefine_clicked();

private:
    Ui::login *ui;//在构造函数通过构造函数初始化列表new
    ppms *ps;
};

#endif // LOGIN_H
