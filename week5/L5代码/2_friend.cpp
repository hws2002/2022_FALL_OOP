#include <iostream>
using namespace std;
class A {
private:
    int data;
public:
    A(int i) : data(i) {}
    void print() { cout << data << " inside\n"; }
    friend void print(A a)  // 这一行的print是全局函数
		{ cout << a.data << " outside\n"; }
};
int main() {
    A c(1);
    c.print(); // 1 inside
    print(c); // 1 outside
    return 0;
}

