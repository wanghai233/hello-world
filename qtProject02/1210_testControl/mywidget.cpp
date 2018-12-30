#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDateTime>
#include <QFont>
#include <QPalette>
myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);
    ui->cb_auto->setChecked(false);
    ui->cb_remember->setChecked(false);
    ui->rb_gb2312->setChecked(true);
    ui->rb_gbk->setChecked(false);
    ui->rb_gb18030->setChecked(false);
}

myWidget::~myWidget()
{
    delete ui;
}

void myWidget::on_pushButton_clicked()
{
    bool flag = ui->cb_auto->isChecked();
    if(flag==true)
        ui->cb_remember->setChecked(true);
    else if(flag==false)
        ui->cb_remember->setChecked(false);

    bool state;
    state = ui->rb_gb2312->isChecked();
    if(state == true)
        ui->lb_time->setText("gb2312 is checked");

    state = ui->rb_gbk->isChecked();
    if(state == true)
        ui->lb_time->setText("gbk is checked");

    state = ui->rb_gb18030->isChecked();
    if(state == true)
        ui->lb_time->setText("gb18030 is checked");
}

void myWidget::on_pushButton_2_clicked()
{
    //获取系统时间，并转换成QString字符串格式
    QDateTime dt;
    dt = QDateTime::currentDateTime();
    QString str = dt.toString("yyyy年MM月dd日 hh:mm:ss dddd");
    //定义字体对象,并设置字体名称及大小
    QFont font;
    font.setFamily("sim sun");
    font.setPointSize(16);
    //设置标签的调色板，设置文字颜色及背景颜色
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::red);
    pe.setColor(QPalette::Background,Qt::green);
    ui->lb_time->setAutoFillBackground(true);
    ui->lb_time->setPalette(pe);
    ui->lb_time->setFont(font);
    ui->lb_time->setText(str);
}

void myWidget::on_pushButton_3_clicked()
{
    QString path(":/image/好学.jpg");
    ui->lb_picture->setScaledContents(true);
    ui->lb_picture->setPixmap(QPixmap(path));
}
