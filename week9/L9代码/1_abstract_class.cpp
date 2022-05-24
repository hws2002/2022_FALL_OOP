#include <iostream>
using namespace std;

class Pet { 
public:  
  virtual void motion()=0;
};
void Pet::motion(){ cout << "Pet motion: " << endl; } 
class Dog: public Pet { 
public: 
  void motion() override {Pet::motion(); cout << "dog run" << endl; } 
};
class Bird: public Pet {
public: 
  void motion() override {Pet::motion(); cout << "bird fly" << endl; } 
};
int main() {
  Pet* p = new Dog; /// 向上类型转换
  p->motion();
  p = new Bird; /// 向上类型转换
  p->motion();
  //p = new Pet; /// 不允许定义抽象类对象
  return 0;
}
