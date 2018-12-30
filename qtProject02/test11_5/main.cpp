#include <iostream>
#include "mystring.h"
#include <string>
using namespace std;

static int count;
//int mystring::count = 0;
void test_string(){

    string str1;
    string str2("abc");
    string str3(10,'a');
    string str4("1234567890",5);

    cout<<str2<<endl;
    cout<<str3<<endl;
    cout<<str4<<endl;

    str2 = str4;
    cout<<str2<<endl;
    string str5;

    str5 = str3+str4;
    cout<<str5<<endl;
    cout<<"str5 length = "<<str5.length()<<endl;

}
void mystring::showString()
{
    count++;
    if(str)
        cout<<"cout="<<count<<":"<<str<<endl;
    else
        cout<<"null"<<endl;
}


int main(int argc, char *argv[])
{
    //cout << "Hello World!" << endl;
    mystring str1;
    str1.showstring();
    mystring str2("abc");
    str2.showstring();
    str1 = str2;
    str1.showstring();
    mystring str3("abcdefg");
    str1 = str3;
    str1.showstring();
    test_string();
    return 0;
}
