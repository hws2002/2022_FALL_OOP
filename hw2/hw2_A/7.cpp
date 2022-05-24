#include <iostream>

class Counter{
private:
    int cnt;
public:
  Counter(): cnt(0) {
      std::cout<<"Initializing Counter."<<std::endl;
  }
  void count() {
      ++cnt;
  }
  int getCount() {
      return cnt;
  }
};

class Test{
public:
    static Counter counter;
  Test() {
      std::cout<<"Initializing Test."<<std::endl;
      counter.count();
  }
};

Counter Test::counter = Counter();

int main() {
  std::cout<<"main"<<std::endl;
  Test();
  std::cout<<Test::counter.getCount()<<std::endl;
  Test();
  std::cout<<Test::counter.getCount()<<std::endl;
  return 0;
}
// Initializing counter cnt = 0;
// main
// Initializing Test  ++cnt;
// 1
// initializing Test ++cnt;
// 2