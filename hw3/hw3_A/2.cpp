#include<iostream>
using namespace std;
class T{
public:
    T(){}
    T(T& t){cout<<"A";}
    T(T&& t){cout<<"B";}
    T& operator =(T&& t){cout<<"C"; return *this;}
};

void swap(T& a, T& b) { 
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

int main(){
    T a;
    T b;
    swap(a,b);
    return 0;
}
//B
//C
//C


