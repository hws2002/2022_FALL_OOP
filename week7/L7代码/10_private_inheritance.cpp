#include <iostream>
using namespace std;
class Base {
public: 
  void baseFunc() { cout << "in Base::baseFunc()..." << endl; }
};

class Derive2: private Base 
{/// 私有继承， is-implementing-in-terms-of：用基类接口实现派生类功能
public:
  void deriveFunc() {
    cout << "in Derive2::deriveFunc(), calling Base::baseFunc()..." << endl;
    baseFunc(); /// 私有继承时，基类接口在派生类成员函数中可以使用
  }
};

int main() {
  Derive2 obj2; 
  cout << "calling obj2.deriveFunc()..." << endl;
  obj2.deriveFunc(); 
  //obj2.baseFunc(); ERROR: 基类接口不允许从派生类对象调用
 
  return 0;
}

