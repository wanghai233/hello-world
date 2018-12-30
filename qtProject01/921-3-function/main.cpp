#include <iostream>

using namespace std;

void function(void* p,int len)
{
    char* temp = (char *)p;
    for(int i=len;i>0;i--)
    {
        printf("%02x",*(temp+i-1));
        if(i>1)
            cout <<"-";
    }
    cout <<endl;

}
int main(int argc, char *argv[])
{
    char one = 0x12;
    short two = 0x1234;
    int three = 0x12345678;

    function(&one,sizeof(one));
    function(&two,sizeof(two));
    function(&three,sizeof(three));
    return 0;
}
