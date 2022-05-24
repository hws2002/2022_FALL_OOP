//a.cpp
#include <iostream>
using namespace std;

int j = 2; 
static int add_j(int k) { //静态函数，只能用于a.cpp
  return k+j; 
};

int main() {
  cout << add_j(3) << endl;
  return 0;
}

