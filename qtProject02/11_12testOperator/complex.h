#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
using namespace std;
class Complex{
public:
    static int s;
    Complex();
    Complex(int ma,int mb);
    Complex(const Complex &c);
    ~Complex();
    void operator = (const Complex &c);
    void PrintComplex();
    void PrintConstVal()const;
    friend Complex  operator +(const Complex &c1,const Complex &c2);//友元加运算符重载
    Complex  &operator +(const Complex &c2);//加运算符重载
    friend Complex  operator -(const Complex &c1,const Complex &c2);
    Complex  &operator -(const Complex &c2);

private:
    const int r;
    int a;
    int b;
};
#endif // COMPLEX_H
