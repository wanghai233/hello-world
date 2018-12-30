#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

using namespace std;

class MyString
{
public:
    MyString();
    MyString(const char*const cstr);
    MyString(const MyString &rs);
    ~MyString();
    char & operator[](int index);
    friend ostream & operator <<(ostream &os,MyString &s);
    friend istream &operator >>(istream &is,MyString &s);
    MyString  operator+(const MyString &another);
    MyString  operator+=(const MyString &another);

    MyString & operator=(MyString &s);
private:
    int len;
    char *str;
};


#endif // MYSTRING_H
