#include <iostream>

using namespace std;

class A{
     int x;
public:
     A(int x1){ x=x1; }
     void disp()
     {cout<<"\nthis="<<this<<"when x="<<this->x;}
};
int main()
{    A a(1),b(2),c(3);
     cout<< "a address="<<&a<<endl;
     a.disp(); b.disp();c.disp();
     return 0;
}
