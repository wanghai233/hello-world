#include <iostream>
#define uchar unsigned char
#define uint unsigned int
#define N 8

using namespace std;

void testbit(uchar ch)
{
    uchar flag = 0x80;
    for(int i=0;i<N;i++)
    {
        if((ch & flag)==1)
            printf("1");
        else
            printf("0");
        if(i==3)
            printf("-");
        flag = flag >> 1;
    }
    cout <<endl;

}

uchar recyle_right(uchar ch,int bits)
{
    uchar temp1;
    uchar temp2;
    uchar rest;
    temp1 = ch;
    temp1 <<=(8 - bits);
    temp2 = ch;
    temp2 >>=bits;
    return (temp1 | temp2);
}


int main(int argc, char *argv[])
{
    uchar temp = 6;
    testbit(temp);
    cout << temp;
    recyle_right(temp);
    cout << temp;
    return 0;
}
