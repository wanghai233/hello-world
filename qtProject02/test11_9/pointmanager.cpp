#include "frind.h"
#include "pointmanager.h"
#include <math.h>
void PointManager::Distance(Point &p1, Point &p2)
{

    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    //int dx = p1.getx() - p2.getx();
    //int dy = p1.gety() - p2.gety();
    float d = sqrt(dx*dx + dy*dy);
    cout<<"Distance = "<<d<<endl;

}
