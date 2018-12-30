#include <iostream>

using namespace std;

void pointer_test()
{
    int i;
    int *p;
    int **q;

    i = 10;
    p = &i;
    q = &p;

    cout <<"Adress:"<< &i << "," << &p << ","<< &q <<endl;
    cout <<"Pointer_adress:"<< &*p << "," << &**q <<endl;
    cout <<"Value:"<< *p << "," << *q <<endl;
    cout <<"**p_Value:"<< **q <<endl;
}
int main(int argc, char *argv[])
{
    pointer_test();
    return 0;
}
