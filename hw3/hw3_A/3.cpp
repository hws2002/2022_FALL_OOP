#include <iostream>
using namespace std;

class Complex
{  
public:  
    int real;  
    int imag; 
    Complex():real(0),imag(0){}
    Complex(int r, int i):real(r),imag(i){cout<<"B";}
    Complex(int r): real(r),imag(0){cout<<"A";}
    explicit operator int(){
        return real;
    }
    // Complex operator+(const Complex& c){
    //     return Complex(this->real+c.real,this->imag+c.imag);
    // } 
};  

int main()
{
    Complex c(3,4);
    c = c+3.4;
    cout<<c.real+c.imag;
    return 0;
}
//B

//A
//6