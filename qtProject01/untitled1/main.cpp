#include <iostream>
#define N 3
#define M 4

using namespace std;

int main()
{
    float subject[N][M]={{1,2,3,4},{55,66,77,88},{99,98,97,96}};
    float arr_a[N],arr_b[M];

    float sum1=0,sum2=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {

             sum1=sum1+subject[i][j];
        }
             arr_a[i]=sum1/M;
             sum1=0;
    }
    for(int j=0;j<M;j++)
    {

        for(int i=0;i<N;i++)
        {

            sum2=sum2+subject[i][j];
         }
            arr_b[j]=sum2/N;
            sum2=0;
    }
    cout<<"array:"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<arr_a[i]<<endl;
    }
    cout<<"The average :"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<arr_b[i]<<endl;
    }
    return 0;
}

