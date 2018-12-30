/*#include <iostream>
#include <string>
#include <string.h>

using namespace std;

void string_test()
{
    char *p1 = "I am a student";
    char temp[128];
    char p2[] = "I am a teacher";

    string str1 ("I am C++ string");
    string str = "I am haha";

 /*   int len = strlen(p1);
    len = str.length();
    cout<<"len = "<< len <<endl;

    memset(temp,0,sizeof(temp));
    strcpy(temp,p1);
    memcpy(temp,p1,strlen(p1));
    strcat(temp,p2);
    cout<<temp<<endl;

    memset(temp,0,sizeof(temp));
    cout<<"Please input a string:"<<endl;
    //0. 做不到 scanf("%s",temp);
    //1.
    gets(temp);
    // 2. cin
    cin.getline(temp,128,'\n');

    cout<<temp;
    cout <<str1<<endl;
    cout <<str<<endl;
}

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    string_test();
    return 0;
}*/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

unsigned char checksum(char *src)
{
    unsigned char crc = 0;
    for(int i =0;i <strlen(src);i++)
        crc+=src[i];
    return crc;
}

int  pack(char *src,char *dst)
{
    unsigned char crc =0;
    crc = checksum(src);
    int len = strlen(src);
    sprintf(dst,"%04d|%s|%03d",len,src,crc);
    return 0;
}

int unpack()
{


}

int main(int argc, char *argv[])
{
    char temp[128];
    memset(temp,0,sizeof(temp));

    char *p="this is a dong";
    pack(p,temp);
    cout<<temp<<endl;

    return 0;
}
