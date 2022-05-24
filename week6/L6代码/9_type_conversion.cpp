#include <iostream>
using namespace std;

class Src;	// 前置类型声明，因为在Dst中要用到Src类
class Dst {
public:
  Dst() { cout << "Dst::Dst()" << endl; }
  Dst(const Src& s) { 
	cout << "Dst::Dst(const Src&)" << endl; 
  }
};

class Src {
public:
  Src() { cout << "Src::Src()" << endl; }
};
void Transform(Dst d) { } 

int main()
{
  Src s;
  //Src::src()
  Dst d1(s);
  //Dst::Dst(const Src&)

  Dst d2 = s; 
  //Dst::dst(const)
  Transform(s);    
  //Dst::Dest(const)
  return 0;
}

