#include "MyString.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
MyString::MyString()
{
    len = 0;
    str = new char[1];
    str[0] = '\0';

}
MyString::MyString(const char*const cstr)
{
    this->len = strlen(cstr);
    this->str = new char [this->len +1];
    strcpy(this->str,cstr);
}
MyString::MyString(const MyString &rs)
{
    cout<<"---String2 copy constructor---"<<endl;
    len = rs.len;
  str = new char[len + 1];
  for(unsigned int i = 0 ;i < len; i++) {
    str[i] = rs.str[i];
  }
  str[len] = '\0';
}
MyString::~MyString()
{
    if(this->str != NULL)
    {
        delete [] this->str;
        this->len =0;
        this->str = NULL;
    }
}
ostream &operator <<(ostream &os,MyString &s)
{
    os<<s.str<<endl;
    return os;
}

istream &operator >>(istream &is,MyString &s)
{
    char temp[4096];
    memset(temp,0,sizeof(temp));
    cout<<"Please input a string:";
    is>>temp;

    s.len = strlen(temp);
    s.str = new char [s.len +1];
    strcpy(s.str,temp);
    return is;
}



MyString & MyString::operator=(MyString &s)
{
    if(this->str != NULL){
        delete [] this->str;
        this->len=0;
    }
    this->len = s.len;
    this->str = new char [s.len +1];
    strcpy(this->str,s.str);
    return *this;
}

char & MyString::operator[](int index)
{
    return this->str[index];
}

MyString MyString::operator+(const MyString &another)
{
    MyString temp;
    temp.len = this->len + another.len;
    temp.str = new char [temp.len+1];
    memset(temp.str,0,temp.len);
    strcpy(temp.str,this->str);
    strcat(temp.str,another.str);
    return temp;
}

MyString MyString::operator+=(const MyString &another)
{
    MyString temp;
    temp.len = this->len;
    strcpy(temp.str,this->str);

    if(this->str != NULL) {
        delete this->str;
        this->len = 0;
    }

    int len = temp.len + another.len ;
    this->len = len;
    this->str = new char [len +1];
    strcpy(this->str,temp.str);
    strcat(this->str,another.str);
    return *this;
}

