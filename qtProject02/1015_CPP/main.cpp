#include <iostream>

using namespace std;

union data{
    int i;
    char a[4];
};

namespace A{
    int x;

    namespace B {
        int x;
}
}//名空间，可以嵌套

void test_a(){
    data p;
    p.i = 0x01345678;
    for(int j=4;j>0;j--)
        printf("%02x\n",p.a[j-1]);
}//共用体举例

void test_const(){
    const int PI = 314;

    //PI = 4.13;
    int *p;
    p = (int *)&PI;
    *p = 413;

    printf("PI = %d\n",PI);//C++里修改不了

    const char *q="abcdefg";
    //q[0] = '0';
    q = "1234567890";
    //q[0]='a';

    cout<<q<<endl;
}//const关键字修饰变量为只读类型

void test_3oper(){
    int a = 10;
    int b = 10;
    int c;

    (a<b?a:b) = 50;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
}//三目运算符做左值

bool test_bool(){
    bool flag;
    int a = 10;
    int b = 20;
    if(a<b)
        flag = true;
    else
        flag = false;
    cout<<"flag="<<flag<<endl;
    return flag;
}//布尔值

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    A::x = 10;
    A::B::x = 10;
    test_a();
    test_const();
    test_3oper();
    test_bool();
    return 0;
}
