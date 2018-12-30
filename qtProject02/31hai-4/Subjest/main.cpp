#include <iostream>

using namespace std;

int main()
{
    double Subject[3][4]={{98,97,99,76},{100,67,89,98},{78,89,90,95}};
    double ave1 = 0.0,ave2 = 0.0,ave3 = 0.0;
    double sub1 = 0.0,sub2 = 0.0,sub3 = 0.0,sub4 = 0.0;

    int i,j;

    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            ave1+=Subject[0][j];
            ave2+=Subject[1][j];
            ave3+=Subject[2][j];

            sub1+=Subject[i][0];
            sub2+=Subject[i][1];
            sub3+=Subject[i][2];
            sub4+=Subject[i][3];
        }
    }

    cout << "ave:" << endl;
    cout << ave1/3 << ",";
    cout << ave2/3 << ",";
    cout << ave3/3 << endl;

    cout << "sub:" << endl;
    cout << sub1/4 << ",";
    cout << sub2/4 << ",";
    cout << sub3/4 << ",";
    cout << sub4/4 <<endl;

}

