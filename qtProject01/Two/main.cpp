#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int a;
    float b,c;
    cout<<"*************"<<endl;
    cout<<"*  1.add    *"<<endl;
    cout<<"*  2.sub    *"<<endl;
    cout<<"*  3.mul    *"<<endl;
    cout<<"*  4.div    *"<<endl;
    cout<<"*  5.squ    *"<<endl;
    cout<<"*  6.esc    *"<<endl;
    cout<<"*************"<<endl;

    cout<<"please input Select category"<<endl;
    cin>>a;
    if(a==6)
      exit(0);
    cout<<"please input two numbers"<<endl;
    cin>>b>>c;
    cout<<"The result is:"<<endl;

    if(a==1)
      cout<<b+c;
    if(a==2)
      cout<<b-c;
    if(a==3)
      cout<<b*c;
    if(a==4)
      cout<<b/c;
    if(a==5)
      cout<<sqrt(b);

    return 0;

}
