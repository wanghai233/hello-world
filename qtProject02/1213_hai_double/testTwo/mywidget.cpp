#include "mywidget.h"
#include "ui_mywidget.h"
extern int flag;
myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);
}

myWidget::~myWidget()
{
    delete ui;
}

void myWidget::on_pushButton_clicked()
{
    flag = flag + 1;
    QString number = QString::number(flag);
    ui->label->setText(number);
}
