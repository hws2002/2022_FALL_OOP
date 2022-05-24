#include <iostream>
using namespace std;
class B { public: virtual void f() {} };
class D : public B { public: int i{2018}; };
int main() {
    D d; B b;
    //    D d1 = static_cast<D>(b); ///未定义类型转换
    //    D d2 = dynamic_cast<D>(b); ///只允许指针和引用转换
    B* pb = &d;
    D* pd3 = static_cast<D*>(pb);
    if (pd3 != nullptr){
        cout << "static_cast, B*(D) --> D*: OK" << endl;
        cout << "D::i=" << pd3->i <<endl;}
	D* pd4 = dynamic_cast<D*>(pb);
    if (pd4 != nullptr){/// 转换正确
        cout << "dynamic_cast, B*(D) --> D*: OK" << endl;
        cout << "D::i=" << pd4->i <<endl;
    }
    return 0;
}
