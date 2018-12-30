#ifndef FIRSTWIDGET_H
#define FIRSTWIDGET_H
#include <QPushButton>
#include"secondwidget.h"

#include <QWidget>

class FirstWidget : public QWidget
{
    Q_OBJECT

public:
    FirstWidget(QWidget *parent = 0);
    ~FirstWidget();
private:
    QPushButton *p1;
    QPushButton *p2;
    bool flag;
    secondWidget *secWin;
public slots:
    void dispButtonState();
    void dispSecondWin();
    void dispFirstWin();
};

#endif // FIRSTWIDGET_H
