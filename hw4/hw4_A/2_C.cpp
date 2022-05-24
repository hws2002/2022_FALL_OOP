#include <iostream>
using namespace std;

class Base{
public:
    virtual void func1() {}
    virtual void func2() {}
};
class Derived1: public Base{
public:
    void func1() final {cout << "Derive1::func1" << endl;}
    void func2() final {cout << "Derive1::func2" << endl;}
};
class Derived2: public Derived1{};