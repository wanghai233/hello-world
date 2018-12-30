#include <iostream>
#include "person.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    person c1("sql",20,1);
    c1.print();

    person c2("java",32,0);
    c2.getName();
    c2.getAge();
    c2.getSex();
    c2.setName("python");
    c2.setAge(19);
    c2.setSex(1);
    c2.print();
    return 0;
}
