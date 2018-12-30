#include "login.h"
#include "ui_login.h"
#include "qDebug"
#include "ppms.h"
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    //setFixedSize(500,500);
    //this->setGeometry(200,200,3000,3000);
    ui->setupUi(this);
    this->ui->lineEditId->setText(QString("wanghai"));
    this->ui->lineEditPassword->setText(QString("123456"));
    this->setWindowTitle(QString("Hello World"));
    this->ps = new ppms();
    ps->setWindowTitle(QString("电力收费系统"));
}

login::~login()
{
    delete ui;
}

void login::on_pushButtonCancel_clicked()
{
    this->close();
}

void login::on_pushButtonDefine_clicked()
{
    this->hide();
    qDebug()<<"OK";//Qmaisiquruis,错误提示
    if((ui->lineEditId->text() ==QString("wang hai"))&&
    (ui->lineEditPassword->text() == QString("123456")))
        this->ps->show();
    else
        qDebug()<<"error";
}
