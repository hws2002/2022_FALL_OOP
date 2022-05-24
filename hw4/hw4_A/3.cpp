#include <iostream>
using namespace std;

class Base{
public:
    void func1() {cout << "Base::func1()" << endl;}
    virtual void func2() {cout << "Base::func2()" << endl;}
    virtual void func2(int) {cout << "Base::func2(int)" << endl;}
    void func2(float) {cout << "Base::func2(float)" << endl;} // (1)
};

class Derived1: public Base{
public:
    void func1() {cout << "Derived1::func1()" << endl;} // (2)
    void func2(float) {cout << "Derived1::func2(float)" << endl;}
};

class Derived2: public Base{
public:
    void func2(int) final override {cout << "Derived2::func2(int)" << endl;} // (3)
};

int main(){
    Derived1 obj;
    Base *p = new Derived1;
    p->func1();
    delete p;
    obj.func1(); // (4)
    return 0;
}
