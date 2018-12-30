#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
using namespace std;

class mystring{
public:
    mystring();//缺省构造函数
    mystring(char *s);//拷贝构造
    mystring(mystring &ms);
    void operator=(char *s);//运算符重载
    ~mystring();//析构
    void showstring();//显示
private:
    char *str;
};

#endif // MYSTRING_H
