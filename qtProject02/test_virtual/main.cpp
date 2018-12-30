#include <iostream>
#include"poly.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    point *pt;

    point *p = new point(100,200);
    pt = p;
    pt->area();
    point *r = new rect(100,200,4,5);
    pt = r;
    pt->area();
    point *c = new circular(100,200,3);
    pt = c;
    pt->area();



#if 0
    point p1(100,200);
    p1.area();
    rect r1(100,200,4,5);
    r1.area();
    //类外对象访问基类的属性
    //cout<r1.x<<endl;
    circular c1(100,200,3);
    c1.area();
#endif
    return 0;
}
