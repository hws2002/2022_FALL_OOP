#include <iostream>
using namespace std;

class Test {
public:
  static int count; //声明静态数据成员
  float value;
  Test(int v): value(v) { count ++; }
  ~Test() { count --; }
  static int how_many() { return count; } 
  //静态成员函数how_many仅能访问count，无法访问value
};

int Test::count = 0;//定义静态数据成员

int main() {
  Test t(2);
  cout << "Test#: " << Test::how_many() << endl;
  cout << "Test.value: " << t.value << endl;
  return 0;
}


