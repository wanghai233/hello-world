#ifndef FRIND_H
#define FRIND_H
#include<iostream>
#include"pointmanager.h"
using namespace std;

class Point{
public:
    Point();
    Point(int mx,int my);
    ~Point();
    void showPoint();
    Point &returnthis();
    static int mc;
    friend void PointManager::Distance(Point &p1,Point &p2);
private:
    int x;
    int y;
};

#endif // FRIND_H
