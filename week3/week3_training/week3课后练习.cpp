//如何在C++中打印变量类型
/*
https://stackoverflow.com/questions/81870/ is-it-possible-to-print-a-variables-type- in-standard-c
#include<iostream>
#include<typeinfo>
#include<cxxabi.h>
class Test{
};
template<typename T>
char* get_type(const T& instance){
return abi::__cxa_demangle(typeid((instance)).name(), nullptr, nullptr, n ullptr);
}
int main(){
auto* x = "abc";
auto y = new int[5];
auto z = Test();
std::cout << get_type(x) << std::endl; std::cout << get_type(y) << std::endl; std::cout << get_type(z) << std::endl;
}
*/

//请提供成员函数的实现(注意实现和定义分开)
//并测试这个类是否正常运行(你还需要测试访问权限)

/*
class Move {
         private:
           double x;
           double y;
           double calc(); // calculate x * y
         public:
           Move(double a = 0, double b = 0);
                  // init x and y to a and b
           void display(); // display the result of calc()
           double get_x(); // return x
           double get_y(); // return y
           void reset(double a = 0, double b = 0);
                     // reset x and y to a and b
};
*/

//函数重载、参数默认值

/*
 编写一个接受一个字符串参数，并打印该字符串的函
数。不过，如果提供了第二个参数(bool 类型)， 且该参数为 true，则该函数打印 n 次字符串，其中
n 是该函数被调用的次数。
int main() {
      f("OOP0");
      f("OOP1");
      f("OOP2", true);
      f("OOP3", false);
      f("OOP4", true);
return 0; }
输出:
OOP0
OOP1
OOP2
OOP2
OOP2
OOP3
OOP4
OOP4
OOP4
OOP4
OOP4 65
*/


//内联函数
/*
• 创建两个功能相同的函数 f1() f2()。f1() 是内联
函数，f2() 是非内联函数。使用 <ctime> 中的标
准 C 函数 clock() 标记这两个函数的开始点和结
   束点，比较它们哪一个运行的更快，为了得到有效数
   字，也许需要在计时循环中重复调用这两个函数。
• 注意:由于编译器可能会忽略inline或自动执行其他 优化。该特性和编译器优化指令有关，如"-O2"。
*/