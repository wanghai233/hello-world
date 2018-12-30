#include"frind.h"
#include<math.h>

int Point::mc = 100;
Point::Point()
{
    cout<<"Point() this="<<this<<endl;
}

Point::Point(int mx, int my)
{
    cout<<"Point(mx,my)this="<<this<<endl;
    this->x = mx;
    this->y = my;
}

Point::~Point()
{

}

void Point::showPoint()
{
    cout<<"Point:"<<"("<<this->x<<","<<this->y<<")"<<endl;
}

Point &Point::returnthis()
{
    return *this;
}

void Distance(Point &p1,Point &p2)
{
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;

    float d = sqrt(dx*dx + dy*dy);
    cout<<"Distance = "<<d<<endl;
}
