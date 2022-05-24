//a.cpp
#include <iostream>
using namespace std;

static int i = 1; //静态全局变量，只能用于a.cpp
int j = 2; //非静态全局变量，可用于其他文件
int add_i(int k);
int add_j(int k);

int main() {
  cout << i << " " << j << endl;
  return 0;
}

