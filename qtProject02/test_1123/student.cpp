#include "student.h"
#include "ui_student.h"
#include<QDebug>
student::student(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::student)
{
    ui->setupUi(this);
}

student::~student()
{
    delete ui;
}

void student::on_pushButton_clicked()
{
    qDebug()<<"in clicked button";
    this->close();
}
