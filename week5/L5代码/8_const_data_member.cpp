#include <iostream>
using namespace std;

class Student {
  const int ID; //常量数据成员
  const int age = 9; // 就地初始化
public:
  Student(int id) : ID(id) {} // 通过初始化列表初始化常量数据成员
  int Next() { 
	ID++; //该处会出现编译错误，因为常量数据成员不可更改
	return ID; 
  }
};

int main() {
  Student stu(20151145);
  cout << "ID = " << stu.Next() << endl;
  return 0;
}

