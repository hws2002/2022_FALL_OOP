#include <iostream>
using namespace std;

class Base{
public:
    virtual void foo(){cout<<"Base::foo()"<<endl;}
    virtual void foo(int ){cout<<"Base::foo(int )"<<endl;} ///重载
    void bar(){};
};
class Derived1 : public Base {
public:
    void foo(int ) {cout<<"Derived1::foo(int )"<<endl;} /// 是重写覆盖
};
class Derived2 : public Base {
public:
    void foo(float ) {cout<<"Derived2::foo(float )"<<endl;} /// 误把参数写错了，不是重写覆盖，是重写隐藏
};

int main() {
    Derived1 d1;
    Derived2 d2;
    Base* p1 = &d1;
    Base* p2 = &d2;
    //d1.foo(); ///由于派生类都定义了带参数的foo，基类foo()对实例不可见
    //d2.foo();
    p1->foo();  ///但是虚函数表中有继承自基类的foo()虚函数
    p2->foo();
    d1.foo(3); ///重写覆盖
    d2.foo(3.0);   ///调用的是派生类foo(float )
    p1->foo(3);  ///重写覆盖，虚函数表中是派生类的 foo(int )
    p2->foo(3.0);   ///重写隐藏，虚函数表中是继承自基类 foo(int )
    return 0;
}
