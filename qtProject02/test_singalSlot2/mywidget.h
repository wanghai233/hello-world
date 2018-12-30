#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include<QPushButton>
class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = 0);
    ~myWidget();
private:
    QPushButton b1;
    QPushButton *b2;
};

#endif // MYWIDGET_H
