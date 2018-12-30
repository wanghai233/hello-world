#include <iostream>

using namespace std;

int main()
{
    int i,j,t,number;
    int arr[100];
    cout << "Please input a number!" << endl;
    cin >> number;

    cout << "Please input a array!" <<endl;
    for(i=0;i<number;i++)
    {
        cin >> arr[i];

    }

    cout << "Original array:" <<endl;
    for(i=0;i<number;i++)
    {
        cout << arr[i]<<",";
    }
    cout <<endl;

    for(i=0;i<number-1;i++)
    {
        for(j=0;j<number-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }

    cout << "array after:" <<endl;
    for(i=0;i<number;i++)
    {
        cout << arr[i]<<",";
    }

    return 0;
}
