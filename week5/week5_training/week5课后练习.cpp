/*实现一个类 A，这个类有一个 int 类型的静态成员变量 count。当这个类被创建时，这个变量会增加1；当这个类被销毁时，这个变量会减少1。在类中添加一个成员函数打印这个变量。 测试代码见下页
这样的变量可能会有什么用处？

*/
#include <iostream>
#include "A.h"

void f() {
    A obj;
    obj.printRef();
}

int main() {
    A *p = new A;
    p->printRef();
    f();
    delete p;
    return 0;
}

/*编写一个向量 Vector 类，这个类的一个对象代表一个三维向量，三个坐标都是 double 类型。通过重载运算符实现向量直接的加减，向量和常数之间的加减、数乘（注意需要满足交换律），以及使用标准输入输出流进行打印。测试代码见下页： 

*/
#include <iostream>
#include "Vector.h"

int main() {
    Vector v1(1.1, 1.2, 1.3);
    Vector v2(0, -3.4, 2.5);
    Vector v3 = v1 + v2;
    std::cout << v3 << std::endl;
    Vector v4 = v3 + 2;
    Vector v5 = 3 * v4 + 5;
    std::cout << v5 << std::endl;
    Vector v6 = 1.4 - (3 * v2 - v1);
    std::cout << v6 << std::endl;
    return 0;
}
