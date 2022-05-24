#include <iostream>
using namespace std;

class Animal{ 
public:  
  void action() {
	speak();
	motion();
  }
  virtual void speak() { cout << "Animal speak" << endl; }
  virtual void motion() { cout << "Animal motion" << endl; }
};

class Bird : public Animal
{
public:
    void speak() { cout << "Bird singing" << endl; }
    void motion() { cout << "Bird flying" << endl; }
};
class Fish : public Animal
{
public:
    void speak() { cout << "Fish cannot speak ..." << endl; }
    void motion() { cout << "Fish swimming" << endl; }
};

int main() {
  Fish fish;
  Bird bird;
  fish.action();	 ///不同调用方法
  bird.action();

  Animal *pBase1 = new Fish;
  Animal *pBase2 = new Bird;
  pBase1->action(); ///同一调用方法，根据
  pBase2->action(); ///实际类型完成相应动作 
  return 0;
}


