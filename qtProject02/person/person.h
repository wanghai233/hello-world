#ifndef PERSON_H
#define PERSON_H
#include<iostream>
class person{
public:
    person();
    person(char *pName,int iAge,int iSex);
    person(person &p);
    ~person();
    void   setName(char *pName);
    char * getName();
    int    getAge();
    int    getSex();
    void   setAge(int iAge);
    void   setSex(int iSex);
    void  print();
private:
    char *name;
    int age;
    int sex;//M:1,W:0
};

#endif // PERSON_H
