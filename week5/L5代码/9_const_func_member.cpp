#include <iostream>
using namespace std;

class Student {
  int ID; 
public:
  Student(int id) : ID(id) {}
  int MyID() const { return ID; } //常量成员函数
  int Next() const { ID++; return ID; } //编译错误，常量成员函数不能修改数据成员
  int Who() { return ID; }
};

int main()
{
  Student stu1(20151145);
  cout << "ID_1 = " << stu1.MyID() << endl;
  cout << "ID_2 = " << stu1.Who() << endl;

  const Student obj2(20160301);
  cout << "id_1 : " << stu2.MyID() << endl;
  cout << "id_2 : " << stu2.Who() << endl; //编译错误，常量对象不能调用非常量成员函数
  return 0;
}

