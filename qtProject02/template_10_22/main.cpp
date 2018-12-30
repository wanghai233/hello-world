#include <iostream>
#include <string.h>

using namespace std;
//模板函数
template <class T>
T mymax (T a,T b){
    return (a>b)?a:b;
}
//结构
#if 0
struct student{
    int id;
    char name[64];
};

struct student stu1,stu2;

void initStu(struct student& s,int myid,char *pname){
    s.id = myid;
    strcpy(s.name,pname);
}

void disStu(struct student& s){
    cout <<"Name:"<<s.name<<",ID:"<<s.id<<endl;
}
#endif
//类
class classStu{
public:
    int id;
    char name[64];

    void initStu(int myid,char *pname){
        id = myid;
        strcpy(name,pname);
    }

    void disStu(){
        cout <<"Name:"<<name<<",ID:"<<id<<endl;
    }
};

classStu stu1,stu2;

int main(int argc, char *argv[])
{
    int a = 123,b = 456;
    double c = 23.234,d = 56.02;
    char e = 'a',f = 'A';
    int temp_int = 0;
    double temp_double = 0.0;
    char temp_char = 'A';
    cout << "Hello World!" << endl;
    temp_int = mymax(a,b);
    cout << "temp_int =" << temp_int <<endl;
    cout << "----------------" <<endl;
    temp_double = mymax(c,d);
    cout << "temp_double =" << temp_double <<endl;
    cout << "----------------" <<endl;
    temp_int = mymax(e,f);
    cout << "temp_char =" << temp_char <<endl;
    cout << "----------------" <<endl;
#if 0
    initStu(stu1,001,"luyang");
    disStu(stu1);
    initStu(stu2,002,"lisi");
    disStu(stu2);
#endif
    stu1.initStu(001,"zhangsan");
    stu1.disStu();
    stu2.initStu(002,"lisi");
    stu2.disStu();
    return 0;
}
