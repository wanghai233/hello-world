#ifndef POLY_H
#define POLY_H

class point{

public:
    point();
    point(int x,int y);
    ~point();
    virtual float area();

//private:
    int x;
    int y;
};

class rect:public point{
public:
    rect();
    rect(int x,int y,int w,int h);//参数总表，需要给基类的参数
    ~rect();
    virtual float area();

private:
    int w;
    int h;
};

class circular:public point{
public:
    circular();
    circular(int x,int y,int length);
    ~circular();
    virtual float area();

private:
    int length;

};

#endif // POLY_H
