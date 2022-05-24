#include <iostream>
using namespace std;

class Base {
public:
  int a{0};
};

class MiddleA : public Base {
public:
  void addA() { cout << "a=" << ++a << endl; };
  void bar() { cout << "A::bar" << endl; };
};

class MiddleB : public Base {
public:
  void addB() { cout << "a=" << ++a << endl; };
  void bar() { cout << "B::bar" << endl; };
};

class Derive : public MiddleA, public MiddleB{
};

int main() {
  Derive d;
  d.addA(); 		/// 输出 a=1。
  d.addB(); 		/// 仍然输出 a=1。
  d.addB();     /// 输出 a=2。
  //cout << d.a; 	   /// 编译错误，MiddleA和MiddleB都有成员a
  cout << d.MiddleA::a << endl;    /// 输出A中的成员a的值 1
  //d.bar(); 		   /// 编译错误，MiddleA和MiddleB都有成员函数bar
  cout << d.MiddleB::a << endl; 
 /// 输出B中的成员a的值 2
  return 0;
}

