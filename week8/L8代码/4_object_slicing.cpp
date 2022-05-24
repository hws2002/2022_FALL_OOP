#include <iostream>
using namespace std;

class Pet { 
public:  
  void name(){ cout << "Pet::name()" << endl; }
};
class Dog: public Pet { 
public:  
  void name(){ cout << "Dog::name()" << endl; }
};
void getName(Pet p){    p.name();}
int main() {
  Dog g;
  g.name();	
  getName(g); 	/// 对象切片（传参），调用基类的 name 函数
  Pet p = g;
  p.name();   /// 对象切片（赋值），调用基类的 name 函数
  return 0;
}

