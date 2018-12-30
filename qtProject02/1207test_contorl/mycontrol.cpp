#include "mycontrol.h"
#include "ui_mycontrol.h"
#include "QDebug"
Mycontrol::Mycontrol(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mycontrol)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("测试窗口"));
    ui->lineEdit->setMaxLength(10);
    ui->lineEdit->setEchoMode(QLineEdit::Normal);
}

Mycontrol::~Mycontrol()
{
    delete ui;
}

void Mycontrol::on_pushButton_clicked()
{
    QString str1("Hello World");
    QString str2="hello world";
    QString str;
    str = str1 +str2;
    qDebug()<<"str ="<<str;
    int len = str.length();
    qDebug()<<"str length="<<len;
    //str1.insert(6,str2);
    //qDebug()<<str1;

    str.clear();
    str.append(str1);
    str.append(str2);
    qDebug()<<"str ="<<str;

    char *p;//把Qstring数据类型转换成char*
    p = str1.toLatin1().data();
    qDebug()<<p;

    int a = 1234;
    str = QString::number(a,16);
    qDebug()<<str;

    str.clear();
    str.sprintf("a = %04x",a);
    qDebug()<<str;

    str = "1234";
    int is;
    is = str.toInt();
    qDebug()<<is;

}

void Mycontrol::on_pushButton_2_clicked()
{
    QRegExp rx("[0-9]+");
    ui->lineEdit->setValidator(new QRegExpValidator);
    QString str;
    QString num;
    str = ui->lineEdit->text();
    if(str.isEmpty())   return;
    //字符串不是空；
    for(int i = 0;i<str.length();i++)
    {
        QChar qc;
        char ch;
        qc = str.at(i);
        if(qc.isNumber()){
            //'1','2','3'
            // 1   2   3
            ch = qc.toLatin1();
            if(((ch - 0x30)%2)!=0)
                num.append(qc);
        }

    }
    ui->label->setText(num);
}
