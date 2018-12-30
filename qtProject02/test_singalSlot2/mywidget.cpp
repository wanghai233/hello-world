#include "mywidget.h"
#include<QPushButton>
#include<QLabel>
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle(QString("things internet"));//Window title
    //QPushButton b1(this);//Local variable
    b1.setParent(this);
    b1.setText(QString("OK"));
    b1.move(200,200);

    b2 = new QPushButton(this);
    b2->setText("Released");
    b2->move(200,300);

    connect(b2,&QPushButton::clicked,this,&myWidget::close);

    //connect(*b1,&QPushButton::pressed,this,&myWidget::released);

}

myWidget::~myWidget()
{

}
