#include <iostream>
using namespace std;

class Test {
public:
    Test() { //构造函数
        cout << "Test()" << endl; 
    }
    Test(const Test& src) { //拷贝构造
        cout << "Test(const Test&)" << endl; 
    }
    ~Test() { //析构函数
        cout << "~Test()" << endl;
    }
};
Test copyObj(Test obj) { 
    cout << "func()..." << endl; 
    return Test();
}

int main() {
    cout << "main()..." << endl;
    Test t;
    Test a = copyObj(t);//修改代码
    return 0;
}

