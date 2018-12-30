#include<stdio.h>

int main()
{
    int arr[]={11,9,8,12,33,89,25,3};
    int i,j,t;

    for(i=0;i<8;i++)
    {
        printf("%d,",arr[i]);
    }
    printf("\n");

    for(i=0;i<8-1;i++)
    {
        for(j=0;j<8-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]=t;
            }
        }
    }

    for(i=0;i<8;i++)
    {
        printf("%d,",arr[i]);
    }
    printf("\n");

    return 0;

}
