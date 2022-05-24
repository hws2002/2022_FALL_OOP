//main.cpp
#include <iostream>
#include "Test.h"
using namespace std;

int main() {
  Test t[10];
  cout << "Test#: " << Test::count << " or " << t[0].count << endl;
  //通过类名或对象访问静态数据成员
  return 0;
}

