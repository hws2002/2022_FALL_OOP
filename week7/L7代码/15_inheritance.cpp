#include <iostream>
using namespace std;

class Pet{
public:
  void eat(){cout<<"Pet eat"<<endl;}
  void sleep(){cout<<"Pet sleep"<<endl; }
};

class Duck : public Pet{
public:
  void eat(){cout<<"Duck eat"<<endl;}
};

int main() 
{
  Duck duck;
  duck.eat();
  duck.sleep();
  return 0;
}


