#include <iostream>
using namespace std;
class B{
  int i;
  float j;
public:
  virtual void fun1() { 
cout << "B::fun1()" << endl; }
  virtual void fun2() { 
cout << "B::fun2()" << endl; }
};
class D: public B{
public:
  double k;
  virtual void fun1() { 
cout << "D::fun1()" << endl; } ///对fun1重写覆盖，对fun2没有，则fun2使用基类的虚函数地址
};
int main() {
  B b; D d;
  B *pB = &d;
  pB->fun1();
  return 0;
}

