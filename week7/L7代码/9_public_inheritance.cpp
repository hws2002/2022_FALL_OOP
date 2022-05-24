#include <iostream>
using namespace std;

class Base {
public: 
  void baseFunc() { cout << "in Base::baseFunc()..." << endl; }
};

class Derive1: public Base {}; // D1类的继承方式是public继承

int main() {
  Derive1 obj1; 
  cout << "calling obj1.baseFunc()..." << endl;
  obj1.baseFunc(); // 基类接口成为派生类接口的一部分，派生类对象可调用

  return 0;
}

