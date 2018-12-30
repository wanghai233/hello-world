#include"poly.h"
#include<iostream>
using namespace std;

point::point(){
    this->x = 0;
    this->y = 0;
}

point::point(int x,int y){
    this->x = x;
    this->y = y;
}

point::~point(){
t w,int
}

float point::area(){
    cout<<"point area = 0"<<endl;
}
//**************************************************没明白
rect::rect():point (){
    this->w = 1;
    this->h = 1;
}

rect::rect(int x,int y,in h):point (x,y){
//    this->x = x;
//    this->y = y;
    this->w = w;
    this->h = h;

}//参数总表，需要给基类的参数,子类的构造函数先要构造基类，构造的形式就是如图：
rect::~rect(){

}

float rect::area(){
    cout<<"point->x="<<this->x<<endl;
    float s =this->w*this->h;
    cout<<"rect area = "<<s<<endl;
    return s;
}

circular::circular(){
    this->length = 1;
}

circular::circular(int x,int y,int length):point (x,y){
    this->x = x;
    this->y = y;
    this->length = length;
}

circular::~circular(){

}

float circular::area(){
    cout<<"circular->x"<<this->x<<endl;
    float s = 3.14*length*length;
    cout<<"length area = "<<s<<endl;
    return s;
}
