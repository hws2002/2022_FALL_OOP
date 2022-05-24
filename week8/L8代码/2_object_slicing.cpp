#include <iostream>
using namespace std;
#pragma pack(4)
class Pet { 
	public:  int att_i;//表示属性
	Pet(int x=0): att_i(x) {};
};
class Dog: public Pet { 
	public:  int att_j;
	Dog(int x=0, int y=0): Pet(x), att_j(y) {}
};
void getSize(Pet p){
  cout << "Pet size:" << sizeof(p) << endl;
}
int main() {
  Pet p;
  cout << "Pet size:" << sizeof(p) << endl;
  Dog g;
  cout << "Dog size:" << sizeof(g) << endl;
  getSize(g); 	/// 对象切片(传参)，数据丢失
  p = g; 		/// 对象切片(赋值)，数据丢失
  cout << "Pet size:" << sizeof(p) << endl;
  return 0;
}

