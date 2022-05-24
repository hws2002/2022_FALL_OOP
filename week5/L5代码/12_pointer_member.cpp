#include <iostream>
using namespace std;

class A {
public:
    int *data; // 注意这是一个指针
    A(int d) {data = new int(d);}
    ~A() {delete[] data;} // 注意这里，释放之前申请的内存
};

void fun(A a) { 
    cout << *(a.data) << endl;
}

int main() {
    A object_a(3);
    fun(object_a);
    return 0; // 在程序结束时会出错
}

