#include <iostream>

using namespace std;

void swap_address(int *x,int *y)
{
    int temp;
    temp = *x;
    *x   = *y;
    *y   = temp;

}

void swap_data(int x,int y)
{
    int temp;
    temp = x;
    x    = y;
    y    = temp;

}

void test_array()
{
    int arr[5]={0,1,2,3,4};

    int len = sizeof(arr)/sizeof(int);
    cout <<"-------------1--------"<<endl;
    for(int i=0;i<len;i++)
        cout << arr[i] << endl;

    int *p = arr;
    cout <<"-------------2--------"<<endl;
    for(int i=0;i<len;i++)
        cout << *(p+i) << endl;             //之前的错误是指针已经移动到数组最后一个元素了
                                            //再移动指针就会出错
    cout <<"-------------3--------"<<endl;
    for(int i=0;i<len;i++)
        cout << *p++ << endl;
}

int main(int argc, char *argv[])
{
    int x=10,y=20;
    cout <<"Before:"<< x << "," << y <<endl;
    swap_data(x,y);
    cout <<"After:"<< x << "," << y <<endl;
    swap_address(&x,&y);
    cout <<"End:"<< x << "," << y <<endl;

    test_array();

    return 0;
}
