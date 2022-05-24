#include <iostream>
using namespace std;
class B {
private:
    int data{0};
public:
    int getData(){ return data; }
    void setData(int i){ data=i; }
};
class D1 : private B {
public:
    using B::getData;
};
int main(){
    D1 d1;
    cout << d1.getData();
    //d1.setData(10);   ///隐藏了基类的setData函数，不可访问
    //B& b = d1;        ///不允许私有继承的向上转换
    //b.setData(10);    ///否则可以绕过D1，调用基类的setData函数
    return 0;
}