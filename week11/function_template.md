# **函数模板特化**
注意：对于函数模板，如果有多个模板参数 ，则特化时必须提供所有参数的特例类型，不能部分特化。
但可以用重载来替代部分特化。

函数重载
```C++
#include <iostream>
using namespace std;

template<class T, class A>
T sum(const A& val1, const A& val2)
{
    cout << "using template" << endl;
    return T(val1 + val2);
}

template<class A>
int sum(const A& val1, const A& val2)
{   //不是部分特化，而是重载函数
    cout << "overload" << endl;
    return int(val1 + val2);
}
int main()
{
    float y = sum<float, float>
                (1.4, 2.4);
    cout << y << endl;
    int x = sum(1, 2);
    cout << x << endl;
    return 0;
}

```

**函数模板重载解析顺序：**
类型匹配的普通函数基础函数模板全特化函数模板

如果有普通函数且类型匹配，则直接选中，重载解析结束

如果没有类型匹配的普通函数，则选择最合适的基础模板

如果选中的基础模板有全特化版本且类型匹配，则选择全特化版本，否则使用基础模板

