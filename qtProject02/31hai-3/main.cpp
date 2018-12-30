#include <iostream>
#include<stdlib.h>
#define N 10

using namespace std;

int main()
{

    int i,j,min,max,t;
    int arr[N];
    for(i=0;i<N;i++)
        arr[i]=rand();
    for(i=0;i<N;i++)
        cout<<arr[i]<<",";
    cout<<endl;

    min=arr[0];
    max=arr[0];
    for(j=0;j<N;j++)
    {
        if(arr[j]>max) max=arr[j];
        if(arr[j]<min) min=arr[j];
    }

    cout<<"max="<<max<<"min="<<min<<endl;

    for(i=0;i<N-1;i++)
    {
        for(j=0;j<N-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }

    for(i=0;i<N;i++)
        cout<<arr[i]<<endl;
}
