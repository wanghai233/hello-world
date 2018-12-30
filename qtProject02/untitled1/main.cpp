#include <iostream>

using namespace std;

int test_new()
{
    int* p = NULL;
    p = new int(1234);

    if(p==NULL)
    {
        printf("malloc failed");
        return -1;
    }

    *p=5678;
    cout<<*p<<endl;
    delete p;
    return 0;
}

int test_new_array()
{
    int* p = NULL;
    p = new int[24];

    if(p==NULL)
    {
        printf("malloc failed");
        return -1;
    }

    for(int i=0;i<24;i++)
        p[i]=10+i;
    for(int i=0;i<24;i++)
        cout<<p[i]<<endl;
    delete [] p;
    return 0;
}

void test_swap(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void test_swapa(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char *argv[])
{
    int c = 10,d = 20;
    cout << "Hello World!" << endl;
    test_new();
    test_new_array();
    cout <<"-----------"<<endl;
    test_swap(c,d);
    cout << c <<","<< d <<endl;
    test_swapa(&c,&d);
    cout << c <<","<< d <<endl;
    return 0;
}
