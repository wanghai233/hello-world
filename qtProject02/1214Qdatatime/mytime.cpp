#include "mytime.h"
#include "ui_mytime.h"
#include <QDateTime>
#include <QDebug>
myTime::myTime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myTime)
{
    ui->setupUi(this);
    this->time = new QTimer(this);//new出来，父窗口
    time->setInterval(1000);//时间间隔
    time->start();//启动定时器
    connect(this->time,&QTimer::timeout,this,&myTime::mySlot);
    //关联信号和槽
}

myTime::~myTime()
{
    delete ui;
}

void myTime::mySlot(){
    QDateTime dt;
    QString str;
    dt = QDateTime::currentDateTime();
    str = dt.toString("yyyy年MM月dd日 hh:mm:ss");
    ui->labTimer->setText(str);
}

void myTime::on_button_clicked()
{
    QStringList str;
    str<<"COM1"<<"COM2"<<"COM3"<<"COM4"<<"COM5";
    for(int i=0;i<str.size();i++){

        qDebug()<<str.at(i);
    }
    ui->comboBox->addItems(str);
    ui->listWidget->addItems(str);
    ui->comboBox->setCurrentIndex(3);
    ui->listWidget->setCurrentRow(2);
    //ui->listWidget->setCurrentIndex(2);
}

void myTime::on_spinBox_valueChanged(int arg1)
{
    qDebug()<<arg1;
    int value2 = ui->spinBox_2->value();
    int res = arg1 + value2;
    qDebug()<<"result"<<res;
}

void myTime::on_spinBox_2_valueChanged(int arg1)
{
    qDebug()<<arg1;
    int value1 = ui->spinBox->value();
    int res = arg1 + value1;
    qDebug()<<"result"<<res;
}
