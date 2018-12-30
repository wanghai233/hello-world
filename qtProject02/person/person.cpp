#include"person.h"
#include<iostream>
#include<string.h>
using namespace std;

person::person(){
    name = NULL;
    age = 0;
    sex = 0;
}

person::person(char *pName,int iAge,int iSex){
    int len = strlen(pName);
    name = new char[len];
    strcpy(name,pName);
    age = iAge;
    sex = iSex;
}

person::person(person &p){
    if(name !=NULL)
        delete [] name;
    else
    {
        int len = strlen(p.name)+1;
        name = new char[len];
        strcpy(name,p.name);
    }
    age = p.age;
    sex = p.sex;
}

person~person(){
    if(name != NULL)
        delete [] name;
}

void   person::setName(char *pName){
    int len = strlen(pName)+1;
    name = new char[len];
    strcpy(name,pName);
}

char *person::getname(){
    char *iname = name;
    cout<<"name:"<<iname<<endl;
}

int    person::getAge(){
    int iage = age;
    cout<<"age:"<<iage<<endl;
}

void   person::setAge(int iAge){
    age = iAge;
}

int    person::getSex(){
    int isex = sex;
    cout<<"sex:"<<isex<<endl;
}

void   person::setSex(int iSex){
    sex = iSex;
}

void person::print()
{
   char *iname = name;
   int iage = age;
   int isex = sex;
   cout<<"name:"<<iname<<endl
      <<"age:"<<iage<<endl
     <<"sex:"<<isex<<endl;
}
