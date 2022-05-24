#include <iostream>
using namespace std;
class T {};
class Base {
public:
  void f() { cout << "Base::f()\n"; }
  void f(int i) { cout << "Base::f(" << i << ")\n"; }
  void f(double d) { cout << "Base::f(" << d << ")\n"; }
  void f(T) { cout << "Base::f(T)\n"; }
};
class Derive : public Base {
public:
  using Base::f;
  void f(int i) { cout << "Derive::f(" << i << ")\n"; }
};
int main() {
  Derive d;
  d.f(10);
  d.f(4.9);
  d.f();
  d.f(T());
  return 0;
}

