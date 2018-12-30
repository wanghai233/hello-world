#include "mystring.h"
#include <string.h>
using namespace std;

mystring::mystring(){
    str = NULL;
}
                        //拷贝构造函数只有一个参数，即同类对象的引用。
mystring::mystring(char *s){
    int len = strlen(s);
    str = new char[len];
    strcpy(str,s);
}

mystring::mystring(mystring &ms)
{
    // 深度拷贝，每个对象都要有明确的空间。
    int len = strlen(ms.str);
    str = new char[len];
    strcpy(str,ms.str);

}
void mystring::operator=(char *s)
{
    if(str != NULL ) delete [] str;
    int len = strlen(s);
    str = new char[len];
    strcpy(str,s);
}
mystring::~mystring()
{
 if(str != NULL ) delete [] str;
}
void mystring::showstring()
{
    if(str)
        cout<<str<<endl;
    else
        cout<<"null"<<endl;
}
