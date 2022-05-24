#include <iostream>
using namespace std;
#pragma pack(4)

class Pet { 
public:  int att_i;//表示属性
	Pet(int x=0): att_i(x) {}
};
class Dog: public Pet { 
public:  int att_j;
	Dog(int x=0, int y=0): Pet(x), att_j(y) {}
};
int main() {
  Pet p(1);
  cout << p.att_i << endl;
  Dog g(2,3);
  cout << g.att_i << " " << g.att_j << endl;
  p = g; 		/// 对象切片，只赋值基类数据
  cout << p.att_i << endl;
  //cout << p.att_j << endl;  // 没有该参数，编译错误
  return 0;
}

