#include <iostream>

using namespace std;

int main()
{
    double Subject[3][4]={{1,2,3,4},{50,60,70,80},{98,99,100,100}};
    double ave1 = 0.0,ave2 = 0.0,ave3 = 0.0;
    double sub1 = 0.0,sub2 = 0.0,sub3 = 0.0,sub4 = 0.0;

    int i,j;

    for(i=0;i<3;i++)
    {  
        for(j=1;j<=3;j++)
        {
            subj+=Subject[i][0];
            subj+=Subject[i][0];
            subj+=Subject[i][0];
        }
    }

    for(j=0;j<4;j++)
    {
        ave1+=Subject[0][j];
        ave2+=Subject[1][j];
        ave3+=Subject[2][j];
    }

    ave1=ave1/3;
    ave2=ave2/3;
    ave3=ave3/3;

    sub1=sub1/4;
    sub2=sub2/4;
    sub3=sub3/4;
    sub4=sub4/4;

    cout << "ave:" << endl;
    cout << ave1 << ",";
    cout << ave2 << ",";
    cout << ave3 << endl;

    cout << "sub:" << endl;
    cout << sub1 << ",";
    cout << sub2 << ",";
    cout << sub3 << ",";
    cout << sub4 <<endl;

}
