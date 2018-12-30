#ifndef SECONDWIDGET_H
#define SECONDWIDGET_H
#include<QPushButton>
#include <QWidget>

class secondWidget : public QWidget
{
    Q_OBJECT
public:
    explicit secondWidget(QWidget *parent = 0);
    ~secondWidget();
private:
    QPushButton *btn;

signals:
    void changeWin();

public slots:
    void sendSignal();

};

#endif // SECONDWIDGET_H
