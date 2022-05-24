#include <iostream>
using namespace std;

class Base1 {
public:
  ~Base1() { cout << "~Base1()\n"; }
};

class Derived1 : public Base1 {
public:
  ~Derived1() { cout << "~Derived1()\n"; }
};

class Base2 {
public:
  virtual ~Base2() { cout << "~Base2()\n"; }
};

class Derived2 : public Base2 {
public:
  ~Derived2() { cout << "~Derived2()\n"; }
};

int main() {
  Base1* bp = new Derived1;
  delete bp; /// 只调用了基类的虚析构函数
  Base2* b2p = new Derived2;
  delete b2p; /// 派生类虚析构函数调用完后调用基类的虚析构函数
  return 0;
}

