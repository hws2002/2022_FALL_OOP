#include <iostream>
using namespace std;

class Base{
private:
  int a{0};
protected:
  int b{0};
};

class Derive : private Base{
public:
  void getA(){cout<<a<<endl;} ///编译错误，不可访问基类中私有成员
  void getB(){cout<<b<<endl;} ///可以访问基类中保护成员
};

int main() 
{
  Derive d;
  d.getB();
  //cout<<d.b; ///编译错误，派生类对象不可访问基类中保护成员
  return 0;
}


