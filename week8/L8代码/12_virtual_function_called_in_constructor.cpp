#include <iostream>
using namespace std;

class Base {
public:
  virtual void foo(){cout<<"Base::foo"<<endl;}
  Base(){foo();}	 ///在构造函数中调用虚函数foo
  void bar(){foo();};	///在普通函数中调用虚函数foo
};

class Derived : public Base {
public:
  int _num;
  void foo(){cout<<"Derived::foo"<<_num<<endl;}
  Derived(int j):Base(),_num(j){}
};
int main() {
    Derived d(0);
    Base &b = d;
    b.bar();
    b.foo();
    return 0;
}
