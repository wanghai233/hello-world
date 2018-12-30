#include<QApplication>
#include<QWidget>
#include<QString>
#include<QPushButton>
#include<QLabel>

int main(int argc,char **argv){

    QApplication a(argc,argv);
    QWidget w;//create one widget
    w.setWindowTitle(QString("hello word"));//windows title

    QPushButton b1(&w);//seting father window
    QLabel *l1;
    l1 = new QLabel(&w);
    l1->setText(QString("hello word"));
    l1->move(200,100);
    /*
     * 1.setParent()  22th code
     * 2.Constructor    13th code
     */
    //b1.setParent(&w);
    b1.setText(QString("OK"));
    b1.move(200,200);
    //l1.move(200,100);
    w.show();
    a.exec();//loop
    delete l1;
    return 0;
}
