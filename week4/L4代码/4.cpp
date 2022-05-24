#include <iostream>
using namespace std;
class Member
{
public:
    Member() { cout << "Member()" << endl; }
};
class Test
{
public:
    Member m;
    Test() { cout << "Test()" << endl; }
};
Test t;
//编译器会自动调用成员变量的魔人构造函数
int main() { return 0; }