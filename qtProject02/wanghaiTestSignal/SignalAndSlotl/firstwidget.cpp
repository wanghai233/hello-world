#include "firstwidget.h"
#include<QPushButton>
#include<Qdebug>
#include<secondwidget.h>
FirstWidget::FirstWidget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(1500,1500);
    this->setWindowTitle(QString("Internet of things1713,Wang Hai,2017087531"
                                 "        (This is the first window)"));
    this->setGeometry(100,100,800,600);
    p1 = new QPushButton(this);
    p1->setText(QString("Switch to the second window"));
    p1->setFont(QFont("Microsoft YaHei",16,QFont::Normal));
    p1->move(100,400);

    p2 = new QPushButton(this);
    p2->setText(QString("released"));
    p2->setFont(QFont("Microsoft YaHei",16,QFont::Normal));
    p2->move(800,400);
    flag = false;

    secWin = new secondWidget();

    connect(p2,&QPushButton::pressed,this,&FirstWidget::dispButtonState);
    connect(p2,&QPushButton::released,this,&FirstWidget::dispButtonState);
    connect(p1,&QPushButton::clicked,this,&FirstWidget::dispSecondWin);
    connect(this->secWin,&secondWidget::changeWin,this,&FirstWidget::dispFirstWin);
}

FirstWidget::~FirstWidget()
{
    delete p1;
    delete p2;
}

void FirstWidget::dispButtonState(){
    flag = !flag;
    if(flag)
        p2->setText(QString("Pressed"));
    else
        p2->setText(QString("Released"));
    //qDebug()<<"in dispButtonState()";
}

void FirstWidget::dispSecondWin(){
    this->hide();
    this->secWin->show();
}

void FirstWidget::dispFirstWin(){
    this->show();
    this->secWin->hide();
}
