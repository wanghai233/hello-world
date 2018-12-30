#include <iostream>
#define N 81
using namespace std;

int small9x9_line;          //行
int small9x9_col;           //列
int small9x9_first_data;    //大九宫格首元素
int sd[N];

void show(int k)            //找出输入数字所在的小九宫格 并输出
{

    small9x9_line = k/27;
    small9x9_col = ((k%27) % 9) /3;
    small9x9_first_data = small9x9_line*27+small9x9_col*3;
    cout<<"small9x9_line ="<<small9x9_line<<"  small9x9_col="<<small9x9_col<<endl;
    cout<<"small9x9 first data = "<<small9x9_first_data<<endl;
    cout<<"The small9x9:"<<endl;
    cout<<small9x9_first_data<<" "<<small9x9_first_data+1<<" "<<small9x9_first_data+2<<endl;
    cout<<small9x9_first_data+9<<" "<<small9x9_first_data+10<<" "<<small9x9_first_data+11<<endl;
    cout<<small9x9_first_data+18<<" "<<small9x9_first_data+19<<" "<<small9x9_first_data+20<<endl;
    cout <<endl;
}

void Column(int k,int col)          //找出输入数字所在的那一列 并输出
{
    int i;
    switch(col)
    {
        case 0:
        for(i=0;i<3;i++)
            if(k%i==0)
            {
                for(int j=i;j<=(i+72);j+=9)
                    cout <<j <<endl;
                break;
            }break;

        case 1:
        for(i=3;i<6;i++)
            if(k%i==0)
            {
                for(int j=i;j<=(i+72);j+=9)
                    cout <<j <<endl;
                break;
            }break;

        case 2:
        for(i=6;i<9;i++)
            if(k%i==0)
            {
                for(int j=i;j<=(i+72);j+=9)
                    cout <<j <<endl;
                break;
            }break;
    }

    cout <<endl;
}

void Line(int k,int line)       //找出输入数字所在的那一行 并输出
{
    for(int i=0;i<=72;i+=9)
        if(k-i>=0&&k-i<=9)
        {
            line = i;
            for(int j=0;j<9;j++)
                cout <<line++<<" ";
            break;
        }
}

int main()
{
    int a;
    for(int i=0;i<N;i++)
        sd[i]=i;
    for(int i=0;i<N;i++)            //打印9*9宫格内所有的元素
    {
        if(i != 0 && i%9 == 0)
            cout <<endl;
        cout << sd[i]<<" ";
    }
    cout <<endl <<endl;

    cout <<"Please input number:"<<endl;
    cin >>a;
    show(a);
    Column(a,small9x9_col);
    Line(a,small9x9_line);
    return 0;
}
