#include <iostream>
using namespace std;
class Base {
public: 
  void baseFunc() { cout << "in Base::baseFunc()..." << endl; }
};

class Derive3: private Base {// B的私有继承
public:
  /// 私有继承时，在派生类public部分声明基类成员名字
  using Base::baseFunc; 
};

int main() {
  Derive3 obj3;
  cout << "calling obj3.baseFunc()..." << endl;
  obj3.baseFunc(); //基类接口在派生类public部分声明，则派生类对象可调用

  return 0;
}


