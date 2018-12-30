#include <iostream>

using namespace std;

void testip(int ip)
{
    int temp;
    for(int i=4;i>0;i--)
    {
        temp = (ip>>(i-1)*8)&0xff;
        if(i == 1)
            printf("%d",temp);
        else
            printf("%d.",temp);
    }
    cout<<endl;
}

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    int hexl = 0x3b40c812;
   // scanf("%x",hex);
    testip(hexl);
    return 0;
}
