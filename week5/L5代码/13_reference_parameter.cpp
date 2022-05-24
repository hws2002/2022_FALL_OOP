#include <iostream>
using namespace std;

class A {
public:
    int *data;
    A(int d) {data = new int(d);}
    ~A() {delete data;} // 注意这里，释放之前申请的内存
};

void fun(A &a) { // 这种情况下，程序不会出现问题
    cout << *(a.data) << endl;
}

int main() {
    A object_a(3);
    fun(object_a);
    return 0;
}

