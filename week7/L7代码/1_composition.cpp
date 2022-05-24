#include <iostream>
using namespace std;

class Wheel{
	int _num;
public:
	void set(int n){_num=n;}
};

class Engine{
public:
  int _num;
  void set(int n){_num=n;}
};
class Car{
private:
  Wheel w;
public:
  Engine e; /// 公有成员，直接访问其接口
  void setWheel(int n){w.set(n);} /// 提供私有成员的访问接口
};

int main()
{
  Car c;
  c.e.set(1);
  c.setWheel(4);
  return 0;
}


