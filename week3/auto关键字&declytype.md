## **auto关键字**
### **使用方法**
由编译器根据上下文自动确定变量的类型，如 
```C
auto i = 3; //i是int型变量
auto f=4.0f; //f是float型变量 
auto a('c'); //a是char型变量
auto b = a; //b是char型变量
auto *x = new auto(3); //x是int*
```


### **要求**

1. auto 变量必须在编译期确定其类型

2. auto 变量必须在定义时初始化
```C
 auto a; //错误
 auto b4 = 10, b5 = 20.0, b6 = 'a’; 
 //错误,没有推导为同一类型
```

3. 参数不能被声明为auto
```C
• void func(auto a) {...} //错误
```
4. auto并不是一个真正的类型。不能使用一些以类 型为操作数的操作符，如sizeof或者typeid。
```C
cout << sizeof(auto) << endl;//错误
```


### **decltype**
decltype可以对变量或表达式结果的类型进行推导

重用匿名类型
```C
struct { int d ; double b;
} anon_s; //没有名字的结构体，定义了一个变量
int main() { decltype(anon_s) as ;
}
```
