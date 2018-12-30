#include <iostream>
#include"complex.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    Complex c1(2,5);
    Complex c2(3,4);
    Complex c3(5,6);

    Complex c4;
    c4 = c1 + c2 + c3;
    c4.PrintComplex();

    Complex c5;
    c5 = c1 - c2 - c3;
    c5.PrintComplex();
    return 0;
}
