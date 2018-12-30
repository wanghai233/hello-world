#include <iostream>
#include "frind.h"

using namespace std;

int main(int argc, char *argv[])
{
#if 0
    cout << "Hello World!" << endl;

    Point p1(10,20);
    cout<<"sizeof Point="<<sizeof(p1)<<endl;
    cout<<"p1 adress="<<&p1<<endl;
    p1.showPoint();

    Point p2(20,40);
    cout<<"sizeof Point="<<sizeof(p2)<<endl;
    cout<<"p1 adress="<<&p2<<endl;
    p2.showPoint();

    Point p3;
    p3 = p1.returnthis();
    p3.showPoint();

    cout<<"------------------"<<endl;
    Distance(p1,p2);
#endif
    cout<<"---------------"<<endl;
    Point p1(12,30);
    Point p2(100,200);
    PointManager pm;

    pm.Distance(p1,p2);
    return 0;
}
