#include <iostream>
#include <string.h>
using namespace std;

namespace A{
int x;
}
namespace B{
int x;
}
typedef struct student{
    char id[10+1];
    char name[64];
    char sex;// 'M' = man 'F'
    int age;
    char classInfo[12];
    float score;
}ST_STU;//不分配内存

ST_STU stu[2]={{"20172511","wangjun2",'F',19,"wxw1711",90.8},
               {"20172512","wangjun1",'F',19,"wxw1713",10.8}};
ST_STU *sp;

void showstu()
{
    for(int i=0;i<sizeof(stu)/sizeof(ST_STU);i++){

        printf("Id:%s,name=%s,age = %d,score = %f\n",stu[i].id,stu[i].name,stu[i].age,stu[i].score);

    }
    return ;
}



int main(int argc, char *argv[])
{
    A::x = 10;
    B::x = 20;
    cout << A::x << "----" << B::x << endl;

    showstu();

    return 0;
}
