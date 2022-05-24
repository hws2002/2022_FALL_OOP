#include <iostream>

class Test{
    friend Test operator !(const Test& a, const Test& b);
    public:
    int data;
    Test(int d): data(d){}
};

Test operator !(const Test& a, const Test& b){
  return Test(!(a.data + b.data));
}

int main(){
    Test t(1);
    Test s(2);
}