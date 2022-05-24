#include <iostream>
using namespace std;
class T {};
class Base {
public:
  void f() { cout << "B::f()\n"; }
  void f(int i) { cout << "Base::f(" << i << ")\n"; } /// 重载
  void f(double d) { cout << "Base::f(" << d << ")\n"; } ///重载
  void f(T) { cout << "Base::f(T)\n"; } ///重载
};
class Derive : public Base {
public:
  void f(int i) { cout << "Derive::f(" << i << ")\n"; } ///重写隐藏
};
int main() {
  Derive d;
  d.f(10);
  d.f(4.9);		/// 编译警告。执行自动类型转换。
  //  d.f();		/// 被屏蔽，编译错误
  //  d.f(T());	/// 被屏蔽，编译错误
  return 0;
}

