#include <iostream>
using namespace std;

int main( )
{
    int i,j;
    cout<<"multiplication table"<<endl;
    for(i=1;i<=9;++i)
    {
        for(j=1;j<=i;++j)
            cout<<i*j<<' ';
        cout<<endl;
    }
    return 0;
}
