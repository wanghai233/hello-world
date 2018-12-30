#include <iostream>
#include <string.h>
#include <conio.h>
#define MAXNUM 1024

using namespace std;

typedef struct student{
    char name[20+1];
    char id[10+1];//学号
    int age;
    char sex;//M男，W女
    int height;//身高
    bool flag;//此变量确定这个点是否有值存在
}ST_STU;

ST_STU stu[MAXNUM]={{"hai","2017081111",19,'M',165},{"jkl","2017082222",20,'M',175},{"qwe","2017083333",21,'W',185}};

void show1stu(struct student *pstu)
{}
void showallstu(struct student *pstu,int *total)//2
{
    printf("===students information：===");
    for(int i=0;i<MAXNUM;i++)
    {
        printf("===the students information:");
        printf("name:%s\n",stu[i].name);
        printf("id:%s\n",stu[i].id);
        printf("age:%s\n",stu[i].age);
        printf("sex:%s\n",stu[i].sex);
        printf("height:%s\n",stu[i].height);
    }
    printf("===the end===");
}
void get1stu(struct student *pstu,int *total)//1
{
    int j=0;
    while(1)
    {
        j=0;
        for(int i=0;i<MAXNUM;i++)
        {
            if(stu[i].flag==true) j++;
        }
        if(j==MAXNUM)
        {
            printf("sorry,full\n");return;
        }
        student st;
        printf("====================\n");
        printf("please input name:");gets(st.name);
        printf("please input sex:");scanf("%d",&st.sex);getchar();
        printf("please input age:");scanf("%d",&st.age);getchar();
        printf("please input id:");scanf("%d",&st.id);getchar();
        printf("please input height:");scanf("%d",&st.height);getchar();
        st.flag=true;
        printf("input completed!");
        for(int i=0;i<MAXNUM;i++)
        {
            if(stu[i].flag==false)
                stu[i]=st;
        }
        char m[2];
        char Y[2]="Y",N[2]="N";
        printf("Do you still want to continue typing?Y/N");
        gets(m);
        if(!strcmp(m,Y))continue;
        else return;
    }

}
void delete1stu(struct student *pstu,int *total)//3
{
    int num,a,stunum;
    char stuname[20];
    while(1)
    {
        printf("please input student information\n name-input 1\n id input 2\n");
        scanf("%d",&a);getchar();
        if(a==1)
        {
            printf("please input student name：");
            gets(stuname);
            bool b=GetNumOfInfo(0,stuname,0,num);
            if(b)
            {
                stu[num].flag=false;
                break;
            }
            else
            {
                printf("sorry,is bool\n");
                char m[2];
                char Y[2]="Y",N[2]="N";
                printf("Do you still want to continue deleting?Y/N");
                gets(m);
                if(!strcmp(m,Y))continue;
                else return;
            }
        }
        if(a==2)
        {
            printf("please input student id：");
            scanf("%d",&stunum);getchar();
            bool b=GetNumOfInfo(1,NULL,stunum,num);
            if(b)
            {
                stu[num].flag=false;
                break;
            }
            else
            {
                printf("sorry,is bool\n");
                char m[2];
                char Y[2]="Y",N[2]="N";
                printf("Do you still want to continue deleting?Y/N");
                gets(m);
                if(!strcmp(m,Y))continue;
                else return;
            }
        }
    }
    printf("===ok===\n");

}
void selectbyname(struct student *pstu,int *total)//4
{}
void selectbyid(struct student *pstu,int *total)//5
{}
int menu()
{
    char s;
    cout << "1.添加学生信息" << endl;
    cout << "2.显示学生信息" << endl;
    cout << "3.删除学生信息" << endl;
    cout << "4.按姓名查信息" << endl;
    cout << "5.按学号查信息" << endl;
    cout << "6.退出" << endl;
    cout << "请选择菜单【1-6】" << endl;
    scanf("%d",&s);getchar();
    return (s);
}

int total;//记录当前学生总数，不超过最大值

int main(int argc, char *argv[])
{
    int s,i=0;
    int totalcnt = 0;

    while(1)
    {
      system("cls");
      s = menu();
      if(s == 6)
      break;
      switch(s)
      {
      case 1:  get1stu(stu,&totalcnt);
          break;
      case 2:  showallstu(stu,&totalcnt);
          getchar();
          break;
      case 3: delete1stu(stu,&totalcnt);
         break;
      case 4:  selectbyname(stu,&totalcnt);
          break;
      case 5:  selectbyid(stu,&totalcnt);
          break;
      default:
          break;
      }
    }

    return 0;
}
