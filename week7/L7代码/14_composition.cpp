#include <iostream>
using namespace std;

class Wheel{
public:
  void inflate(){
	cout<<"Wheel::inflate"<<endl;
  }
};

class Engine{
public:
  void start(){
	cout<<"Engine::start"<<endl;
  }
  void stop(){}
};

class Car{
public:
  Engine engine;
  Wheel wheel[4];
};

int main() 
{
  Car car;
  car.wheel[0].inflate();	
  car.engine.start();
  return 0;
}

