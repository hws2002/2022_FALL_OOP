#include <iostream>
using namespace std;
#pragma pack(4)

class Pet { 
public:  int att_i;
	Pet(int x=0): att_i(x) {}
};
class Dog: public Pet { 
public:  int att_j;
	Dog(int x=0, int y=0): Pet(x), att_j(y) {}
};
int main() {
  Dog g(2,3);
  cout << g.att_i << " " << g.att_j << endl;
  Pet& p = g; 		/// 引用向上转换
  cout << p.att_i << endl;
  p.att_i = 1;        /// 修改基类存在的数据
  cout << p.att_i << endl;
  cout << g.att_i << " " << g.att_j << endl; /// 影响派生类
  return 0;
}

