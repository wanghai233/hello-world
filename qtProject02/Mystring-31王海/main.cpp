#include <iostream>
#include <stdio.h>
#include <string.h>
#include "MyString.h"

using namespace std;

int main(int argc, char *argv[])
{
    MyString s1("999");
    MyString s2("aaa");
    MyString s3 = s1 + s2;
    cout<<s3;
    MyString s4("zhangsan");
    s3 += s4;
    cout<<s3;
    getchar();
    return 0;
}
