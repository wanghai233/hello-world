#include <iostream>
#include <string>

using namespace std;

class MyString
{
public:
    MyString();
    MyString(const char*const cstr);//一定要带const，深度拷贝
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

MyString::MyString(){
    this->len = 0;
    this->str = NULL;
}

MyString::MyString(const char*const cstr){
    if(this->str!=NULL)
    {
        delete [] str;
        str = NULL;//小心悬摆指针
        len = 0;
    }
    int len = strlen(cstr);
    this->len = len;
    this->str = new char [len+1];
    srtcpy(str,cstr);
}

MyString::MyString(const MyString &rs){
    if(this->str!=NULL)
    {
        delete [] str;
        str = NULL;//小心悬摆指针
        len = 0;
    }
    int len = strlen(rs.str);
    this->len = len;
    this->str = new char [len+1];
    srtcpy(str,rs.str);
}

MyString::~MyString(){
    if(str!=NULL)
    {
        delete [] str;
        str = NULL;
        len = 0;
    }

}

char & operator[](int index){

}

friend ostream & operator <<(ostream &os,MyString &s){

}

friend istream &operator >>(istream &is,MyString &s){

}

MyString  MyString::operator+(const MyString &another){

}

MyString  MyString::operator+=(const MyString &another){

}
//char指针
MyString & MyString::operator=(MyString *str){
    if(this->str!=NULL)
    {
        delete [] str;
        str = NULL;//小心悬摆指针
        len = 0;
    }
    int len = strlen(str);
    this->len = len;
    this->str = new char [len+1];
    srtcpy(str,str);
    return *this;
}
//对象
MyString & MyString::operator=(MyString &s){
    if(this->str!=NULL)
    {
        delete [] str;
        str = NULL;//小心悬摆指针
        len = 0;
    }
    int len = strlen(rs.str);
    this->len = len;
    this->str = new char [len+1];
    srtcpy(str,rs.str);
    return *this;
}

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    string s1("abc");
    string s2("123");

    s1 = s2;

    return 0;
}
