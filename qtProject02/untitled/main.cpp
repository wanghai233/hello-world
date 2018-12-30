/**********************
=======完成
1.添加学生信息
2.显示学生信息
6.退出
=======待完善
3.删除学生信息
4.按姓名查信息
5.按学号查信息
=======没有完成
保存至文件
**********************/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
static int stu_num;

using namespace std;

typedef struct student{
    char name[20+1];
    char id[10+1];//学号
    int age;
    char sex;//M男，W女
    int height;//身高
    bool flag;//此变量确定这个点是否有值存在
}ST_STU;

ST_STU *stu;

#if 0
//用于检测所输入的系统中是否已有
bool GetNumOfInfo(int flag,char *name,int stunum,int &num)
{
    if(flag==0)
    {
        for(int i=0;i<stu_num;i++)
        {
            if(!strcmp(name,stu[i].name))
            {
                num=i;
                return true;
            }
        }
        return false;
    }
    else if(flag==1)
    {
        for(int i=0;i<stu_num;i++)
        {
            if(stunum==stu[i].id)
            {
                num=i;
                return true;
            }
        }
        return false;
    }
}
#endif

void showallstu(struct student *pstu,int *total)//2
{
    printf("===STUDENTS INFORMATION：===\n");
    for(int i=0;i<stu_num;i++)
    {
        if(stu[i].flag==true)
        {
            printf("===the students information:\n");
            printf("name:%s\n",stu[i].name);
            printf("id:%s\n",stu[i].id);
            printf("age:%d\n",stu[i].age);
            printf("sex:%c\n",stu[i].sex);
            printf("height:%d\n",stu[i].height);
        }
    }
    printf("===the end===\n");
}
void get1stu(struct student *pstu,int *total)//1
{
    cout<<"Create student personal information now"<<endl;
    cout<<"Please input students number："<<endl;
    scanf("%d",&stu_num);getchar();
    stu=(student*)malloc(sizeof(student)*stu_num);
    for(int i=0;i<stu_num;i++)
    {
        printf("Create student information\n");
        printf("please input name:");gets(stu[i].name);
        printf("please input sex:");scanf("%c",&stu[i].sex);getchar();
        printf("please input age:");scanf("%d",&stu[i].age);getchar();
        printf("please input id:");scanf("%s",&stu[i].id);getchar();
        printf("please input height:");scanf("%d",&stu[i].height);getchar();
        stu[i].flag=true;
    }
    printf("input completed!\n");

#if 0
    int j=0;
    while(1)
    {
        j=0;
        for(int i=0;i<stu_num;i++)
        {
            if(stu[i].flag==true) j++;
        }
        if(j==stu_num)
        {
            printf("sorry,full\n");return;
        }
        student st;
        printf("====================\n");
        printf("please input name:");gets(st.name);
        printf("please input sex:");scanf("%c",&st.sex);getchar();
        printf("please input age:");scanf("%d",&st.age);getchar();
        printf("please input id:");scanf("%s",&st.id);getchar();
        printf("please input height:");scanf("%d",&st.height);getchar();
        st.flag=true;
        printf("input completed!");
        for(int i=0;i<stu_num;i++)
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
#endif

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
            stu[num].flag=false;
            break;
        }
        if(a==2)
        {
            printf("please input student id：");
            scanf("%d",&stunum);getchar();
            stu[num].flag=false;
            break;
        }
    }
    printf("===ok===\n");

}
void selectbyname(struct student *pstu,int *total)//4
{
    int num,stunum;
    char stuname[20];
    while(1)
    {
        printf("please input the student name：");
        gets(stuname);
        printf("the student information：\n");
        printf("name：%s\n",stu[num].name);
        printf("sex：%c\n",stu[num].sex);
        printf("id：%s\n",stu[num].id);
        printf("age：%d\n",stu[num].age);
        printf("height：%d\n",stu[num].height);
        break;
    }
}
void selectbyid(struct student *pstu,int *total)//5
{
    int num,stunum;
    char stuname[20];
    while(1)
    {
        printf("please input the student id：");
        gets(stuname);
        printf("the student information：\n");
        printf("name：%s\n",stu[num].name);
        printf("sex：%c\n",stu[num].sex);
        printf("id：%s\n",stu[num].id);
        printf("age：%d\n",stu[num].age);
        printf("height：%d\n",stu[num].height);
        break;
    }

}
int menu()
{
    char s;
    cout << "1.add the student information" << endl;
    cout << "2.show all students information" << endl;
    cout << "3.delete the student information" << endl;
    cout << "4.select by name" << endl;
    cout << "5.select by id" << endl;
    cout << "6.quit" << endl;
    cout << "please input:1-6" << endl;
    scanf("%d",&s);getchar();
    return (s);
}
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
    free(stu);
    return 0;
}
