## **常量**
常量关键字const常用于修饰变量、引用/指针、函数返回值等

**修饰变量时（如const int n = 1;），必须就地初始化，该变量的值在其生命周期内都不会发生变化**
**修饰引用/指针时（如int a=1; const int& b=a;），不能通过该引用/指针修改相应变量的值，常用于函数参数以保证函数体中无法修改参数的值**

**修饰函数返回值时（如const int* func() {…}），函数返回值的内容（或其指向的内容）不能被修改**

## **常量数据成员**
常量数据成员：使用const修饰的数据成员，称为类的常量数据成员，在对象的整个生命周期里不可更改

**常量数据成员可以在构造函数的初始化列表中被初始化、就地初始化、**

**不允许在构造函数的函数体中通过赋值来设置**

示例
```C++
#include <iostream>
using namespace std;

class Student {
  const int ID; //常量数据成员
  const int age = 9; // 就地初始化
public:
  Student(int id) : ID(id) {} // 通过初始化列表初始化常量数据成员
  int Next() { 
	ID++; //该处会出现编译错误，因为常量数据成员不可更改
	return ID; 
  }
  int Next(2){
      age = 2; //不允许在构造函数的函数体中通过赋值来设置
      return age;
  }
};

int main() {
  Student stu(20151145);
  cout << "ID = " << stu.Next() << endl;
  return 0;
}
//*编译器错误提示：
//[Error] increment of read-only member 'Test::ID'

```

## **常量成员函数**
常量成员函数：成员函数也能用const来修饰，称为常量成员函数.
*常量成员函数的访问权限：实现语句不能修改类的数据成员，即不能改变对象状态（内容）*

*ReturnType Func(…) const {…}*
*注意区别：const ReturnType Func(…) {…}*

*若对象被定义为常量(const ClassName a;)，则它只能调用以const修饰的成员函数*
*常量对象：对象中的“数据”不能变*


示例
```C++
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

  const Student obj2(20160301); //常量对象：对象中的“数据”不能变
  cout << "id_1 : " << stu2.MyID() << endl;//若对象被定义为常量(const ClassName a;)，则它只能调用以const修饰的成员函数
  cout << “id_2 : ” << stu2.Who() << endl; //编译错误，常量对象不能调用非常量成员函数
  return 0;
}
```

## **常量静态变量**
const static
**常量静态变量需要在类外进行定义**

和静态变量一样

**但有两个例外：int和enum类型可以就地初始化**

常量静态变量和静态变量一样，满足访问权限的任意函数均可访问，但都不能修改

**注意：不存在常量静态函数**
静态函数隶属于类，可以不实例化而直接通过类名访问
常量/非常量函数的访问权限需要通过实例化后的对象是否为常量对象来决定。常量修饰函数必须绑定在对象上
因此，静态函数和常量函数互相冲突

示例
```C++
class foo {
	static const char* cs; // 不可就地初始化
static const int i = 3; // 可以就地初始化
static const int j; // 也可以在类外定义
};

const char* foo::cs = "foo C string";
const int foo::j = 4;
```

## **常量对象的构造与析构**
**常量全局/局部对象的构造与析构时机和普通全局/局部对象相同**
常量全局对象：在main()函数调用之前进行初始化，在main()函数执行完return，程序结束时，对象被析构

常量局部对象：在程序执行到该局部对象的代码时被初始化。在局部对象生命周期结束、即所在作用域结束后被析构
