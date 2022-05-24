## **内联函数**
为什么用内联函数
使用内联函数，编译器自动产生等价的表达式。
```C
         inline int max(int a, int b) {
             return a > b ? a : b;
         }
         cout << max(a, b) << endl;
```
上述代码等价于
```C
cout  << (a > b ? a : b) << endl;****