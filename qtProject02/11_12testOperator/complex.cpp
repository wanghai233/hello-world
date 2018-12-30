#include"complex.h"

Complex::Complex():r(100)
{
    this ->a = 0;
    this ->b = 0;
}

Complex::Complex(int ma,int mb):r(200)
{
    this ->a = ma;
    this ->b = mb;
}

Complex::~Complex(){

}

void Complex::PrintComplex(){
    cout<<"Complex:"<<"("<<this->a<<","<<this->b<<"i)"<<endl;
 //   this ->s = 100;
 //   cout<<"static s ="<<s<<endl;
}
void Complex::PrintConstVal()const
{
    cout<<"Conts r="<<r<<endl;
 //   this ->s = 200;
 //   cout<<"static s ="<<s<<endl;
}

Complex::Complex(const Complex &c):r(2333)
{
    this ->a = c.a;
    this ->b = c.b;
    cout<<"(const Complex &c)"<<endl;
}

void Complex::operator = (const Complex &c)
{
    this ->a = c.a;
    this ->b = c.b;
    cout<<"operator="<<endl;
}
Complex  & Complex::operator +(const Complex &c2)// 成员函数的形式
{
    this->a += c2.a;
    this->b += c2.b;
     cout<<"Complex::operator +"<<endl;
    return *this;
}

Complex  operator +(const Complex &c1,const Complex &c2) //友元函数的形式
{
    Complex c;
    c.a = c1.a + c2.a;
    c.b = c1.b + c2.b;
    cout<<"operator +++"<<endl;
    return c;
}

Complex  & Complex::operator -(const Complex &c2)// 成员函数的形式
{
    this->a -= c2.a;
    this->b -= c2.b;
     cout<<"Complex::operator -"<<endl;
    return *this;
}

Complex  operator -(const Complex &c1,const Complex &c2) //友元函数的形式
{
    Complex c;
    c.a = c1.a - c2.a;
    c.b = c1.b - c2.b;
    cout<<"operator ---"<<endl;
    return c;
}
