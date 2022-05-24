class Base { public: virtual ~Base()=0; };
Base::~Base() {} /// 必须有函数体
class Derive : public Base {};
int main() {
  Base b; /// 编译错误，基类是抽象类
  Derive d1; /// 派生类不必实现纯虚析构函数
  return 0;
}
