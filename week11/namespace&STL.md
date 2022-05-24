# **命名空间**
为了避免在大规模程序的设计中，以及在程序员使用各种各样的C++库时，标识符的命名发生冲突，标准C++引入了关键字namespace（命名空间），可以更好地控制标识符的作用域。

标准C++库（不包括标准C库）中所包含的所有内容（包括常量、变量、结构、类和函数等）都被定义在命名空间std（standard标准）中.

eg)
cout、cin、vector、set、map


```C++
//定义命名空间：
    namespace A {
        int x, y;
    }
//使用命名空间：
    A::x = 3;
    A::y = 6;
```

### 使用using声明简化命名空间使用
```C++
//使用整个命名空间：所有成员都直接可用
    using namespace A;
    x = 3; y = 6;
//使用部分成员：所选成员可直接使用
    using A::x;
    x = 3; A::y = 6;
//任何情况下，都不应出现命名冲突
```

# **STL简介**
1. 标准模板库（英文：Standard Template Library，缩写：STL），是一个高效的C++软件库，它被容纳于C++ 标准程序库C++ Standard Library中。其中包含4个组件，分别为算法、容器、函数、迭代器。
2. 基于模板编写。
3. 关键理念：将“在数据上执行的操作”与“要执行操作的数据”分离。

### STL的命名空间是std

一般使用std::name来使用STL的函数或对象

也可以使用using namespace std来引入STL的命名空间（不推荐在大型工程中使用，容易污染命名空间）

### 关于STL的文档和例子可以在以下网址查询

http://www.cplusplus.com/

多写多查多用，是学习STL库的最好方法

## **STL容器**

容器是包含、放置数据的工具。通常为数据结构。
> 简单容器（simple container）
> 
> 序列容器（sequence container）
> 
> 关系容器（associative container）

___
### **pair**

简单的容器，由两个单独数据组成。
```C++
   template<class T1, class T2> struct pair{
	T1 first;
	T2 second;
	//若干其它函数
   };

//通过first、second两个成员变量获取数据。
std::pair<int, int> t;
t.first = 4; t.second = 5;

//进一步阅读：http://hahaya.github.io/study-std-pair/ 
```

创建：使用函数make_pair。
```C++
    auto t = std::make_pair(“abc”, 7.8);
```
优势：自动推导成员类型。

支持小于、等于等比较运算符。

先比较first，后比较second。要求成员类型支持比较(实现比较运算符重载)。
```C++
std::make_pair(1, 4) < std::make_pair(2, 3);
std::make_pair(1, 4) > std::make_pair(1, 2);
```

```C++
pair使用举例:
#include <string>
int main(){
  std::pair<std::string, double> p1("Alice", 90.5);
  std::pair<std::string, double> p2;

  p2.first = "Bob";
  p2.second = 85.0;

  auto p3 = std::make_pair("David", "95.0");
  return 0;
}
```
## **tuple**
C++11新增，pair的扩展，由若干成员组成的元组类型。
```C++ 
 template< class ... Types > class tuple;
创建：make_tuple函数
    auto t = std::make_tuple(“abc”, 7.8, 123, ‘3’);

创建：tie函数—返回左值引用的元组
    std::string x; double y; int z;
    std::tie(x, y, z) = std::make_tuple(“abc”, 7.8, 123);
    //等价于 x = "abc"; y = 7.8; z = 123
通过std::get函数获取数据。
 auto t = std::make_tuple(“abc”, 7.8, 123, ‘3’); 
 auto v0 = std::get<0>(t);
 auto v1 = std::get<1>(t);

其下标需要在编译时确定：不能设定运行时可变的长度，不能当做数组

int i = 0;
v = std::get<i>(tuple); //编译错误

用于函数多返回值的传递：
#include <tuple>
std::tuple<int, double> f(int x){ 
    return std::make_tuple(x, double(x)/2);
}
int main() {
    int xval; 
    double half_x;
    std::tie(xval, half_x) = f(7);
    return 0;
}

```
作为tuple的特例，pair可用于两个返回值的传递
除此之外，pair在map中大量使用。


### **vector**
会自动扩展容量的数组，以循序(Sequential)的方式维护变量集合。		
```C++
    template<class T, class Allocator = std::allocator<T>> 
    class vector;
```
STL中最基本的序列容器，提供有效、安全的数组以替代C语言中原生数组。

允许直接以下标访问。（高速）
```C++
创建：std:vector<int> x;

当前数组长度： x.size();

清空： x.clear();

在末尾添加/删除：（高速）
 x.push_back(1); x.pop_back();

（使用迭代器）在中间添加/删除：（低速）
  x.insert(x.begin()+1, 5);
 x.erase(x.begin()+1);
```
#### **迭代器**
一种检查容器内元素并遍历元素的数据类型。

提供一种方法顺序访问一个聚合对象中各个元素, 而又不需暴露该对象的内部表示。

为遍历不同的聚合结构（需拥有相同的基类）提供一个统一的接口。

使用上类似指针。

```C++
定义：
template<class T, class Allocator = std::allocator<T>> 
class vector {
	class iterator {
		...
	}
};
```
```c++
vector<int>::iterator iter;
定义了一个名为iter的变量，它的数据类型是由vector<int>定义的iterator类型。

begin函数：x.begin()，返回vector中第一个元素的迭代器。

end函数：x.end()，返回vector中最后一个元素之后的位置的迭代器。

begin和end函数构成所有元素的左闭右开区间。

下一个元素：++iter

上一个元素：--iter

下n个元素：iter += n

上n个元素：iter -= n

访问元素值——解引用运算符 *
    *iter = 5;
解引用运算符返回的是左值引用
```
```C++
迭代器移动：与整数作加法
 iter += 5;
元素位置差：迭代器相减
 int dist = iter1 – iter2;
其本质都是重定义运算符
```
#### **遍历vector**
```C++
  for(vector<int>::iterator it = vec.begin(); 
	it != vec.end(); ++it)  //use *it

C++11中常使用auto替代vector<int>:: iterator，以简化代码
  for(auto it = vec.begin(); it != vec.end(); ++it)
						//use *it

C++11中按范围遍历vector：
for(auto & x : vec)
//c++11按范围遍历好像不能对vector的数据进行修改，只能取值

 //直接利用vec中元素x
与以下代码等价：
for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
 //使用 *it，即it是指向元素的指针
```
#### **迭代器：失效**

**问题！！**
```C++
 auto it = vec.begin();
vec.erase(it);
是否能继续使用it迭代器？
```
当迭代器不再指向本应指向的元素时，称此迭代器失效。

vector中什么情况下会发生迭代器失效？

看作纯粹的指针
调用insert/erase后，所修改位置之后的所有迭代器失效。（原先的内存空间存储的元素被改变）
调用push_back等修改vector大小的方法时，可能会使所有迭代器失效（为什么？）

#### **vector 原理**
vector是会自动扩展容量的数组

除了size，另保存capacity：最大容量限制。

如果size达到了capacity，则另申请一片capacity*2的空间，并整体迁移vector内容。

其时间复杂度为均摊O(1)。

整体迁移过程使所有迭代器失效。

#### **迭代器：失效**
在遍历的时候增加元素，可能会导致迭代器失效
```c++
#include <iostream>
#include <vector>
using namespace std;
int main(){   
   vector<int> vec = {1,2,3,4,5};
   for(auto it = vec.begin(); it != vec.end(); ++it)
      vec.push_back(*it); //Error
   return 0;
}
```
使用erase删除元素，被删除元素及之后的所有元素均会失效
```c++
   vector<int> vec = {1,2,3,4,5};
   auto first = vec.begin();
   auto second = vec.begin() + 1;
   auto third = vec.begin() + 2;
   auto ret = vec.erase(second);
   //first指向1，second和third失效
   //ret指向3
```
迭代器是否会失效，和实现容器的数据结构有关

在文档中，容器的修改操作有一项Iterator validity，表示该操作是否会引发迭代器失效

一个绝对安全的准则：
	在修改过容器后，不使用之前的迭代器

若一定要使用，查文档确定迭代器是否有效

## **STL容器：list**
```C++
链表容器（底层实现是双向链表）
template<
    class T,
    class Allocator = std::allocator<T>
> class list;
定义：
std::list<int> l;

插入前端：
 l.push_front(1);
插入末端：
 l.push_back(2); 
查询：
 std::find(l.begin(), l.end(), 2); //返回迭代器
插入指定位置：
 l.insert(it, 4); //it为迭代器

```
1. 不支持下标等随机访问
2. 支持在任意位置高速插入/删除数据
3. 其访问主要依赖迭代器
4. 插入和删除操作不会导致迭代器失效（除指向被删除的元素的迭代器外）

## **STL容器 ： set**

不重复元素构成的无序集合
```c++
 template< class Key,
   class Compare = std::less<Key>,
   class Allocator = std::allocator<Key>
 > class set;
内部按大小顺序排列，比较器由函数对象Compare完成。

注意：无序是指不保持插入顺序，容器内部排列顺序是根据元素大小排列。
定义：
 std::set<int> s;
```
```C++
插入（不允许出现重复元素）：
 s.insert(val);
查询值为val的元素：
 s.find(val);   //返回迭代器
删除：
 s.erase(s.find(val));   //导致迭代器失效
统计：
 s.count(val);   //val的个数，总是0或1
```

### **STL容器：map**
关联数组
每个元素由两个数据项组成，map将一个数据项映射到另一个数据项中。
```C++
 template<class Key,
   class T,
   class Compare = std::less<Key>,
   class Allocator =
      std::allocator<std::pair<const Key, T> >
 > class map;
```

其值类型为
```C++
pair<Key, T>。
```
map中的元素key必须互不相同。

可以通过下标访问（即使key不是整数）。下标访问时如果元素不存在，则创建对应元素。

也可使用insert函数进行插入。   
```C++
#include <string>
#include <map> 
int main() {
    std::map<std::string, int> s;
    s["Monday"] = 1;
    s.insert(std::make_pair(std::string("Tuesday"), 2));
    return 0;
}
```

```C++
查询键为key的元素：
   s.find(key);               // 返回迭代器
统计键为key的元素个数：
   s.count(key);            // 返回0或1
删除：
   s.erase(s.find(key));   //导致被删元素的迭代器失效
```

map常用作稀疏数组或以字符串为下标的数组。
```C++
#include <string>
#include <map> 

int main() {
    std::map<std::string, std::string> M;
    M["fp"] = "c";
    M["oop"] = M["fp"] + "++"; // M["oop"] = "c++"
    return 0;
}
```

Set和Map所用到的数据结构都是红黑树（一种二叉平衡树）
其几乎所有操作复杂度均为O(logn)
相关内容将在数据结构课程中学习
### **STL容器 ： 总结**
序列容器：vector、list

关联容器：set、map


序列容器与关联容器的区别：
> 序列容器中的元素有顺序，可以按顺序访问。
> 
> 关联容器中的元素无顺序，可以按数值（大小）访问。
> 
> vector中插入删除操作会使操作位置之后全部的迭代器失效。
> 
> 其他容器中只有被删除元素的迭代器失效。
> 
**选择合适的容器：**
   在实际应用中，容器的选择可能需要综合考虑多方面因素，包括算法复杂度，功能需求，内存分配策略等，下面提供几个可供参考但不完整的角度（可以进一步阅读《Effective STL》）：

   （1）算法复杂度：对于序列容器而言，如果在序列中间存在频繁的插入或删除操作，使用list，否则使用vector（或deque）

   （2）元素的顺序：如果需要在容器的任意位置插入新元素，需要选择序列容器而不是关联容器

   （3）元素查找速度：如元素的查找速度是关键的考虑因素，可以考虑排序的vector或关联容器set、map等

   （4）迭代器、指针或引用失效：如果希望在元素插入和删除操作后,迭代器、指针或引用失效的情况尽可能少出现，可以考虑使用list和关联容器set、map等

### **例子：同义词查询库**
场景：针对一个大型同义词库，频繁查询给定词语的所有同义词
```C++
// 测试函数，SynonymBase是待实现的同义词查询库类
void test(SynonymBase& base){
    base.add("happy", "pleased"); //加入happy同义词pleased
    base.add("happy", "satisfied");
    base.add("pleased", "happy");
    base.add("angry", "irritated");
    base.query("happy");   //查询输出所有happy的同义词
    base.query("pleased");
    base.query("angry");
}
class SynonymBase {
private:
    map<string, vector<string>> synonyms;
public:
    void add(string word, string synonym){
        synonyms[word].push_back(synonym);
    }
    void query(string word){
        if(synonyms.find(word) == synonyms.end()){ //没有找到
            cout << "no synonyms found" << endl;
        }
        else{
            for(auto & x: synonyms[word]) cout << x << endl;
        }
    }
};
/*增加需求：判定给定的两个词是否是同义词
分析
功能需求：构建词语与其同义词的映射关系
效率：词语的查找速度很关键，考虑使用map
key是词语，使用字符串类型
value是相应的同义词容器。对于新增需求，需要查询一个词是否在另一个词的同义词容器里；如果一个词的同义词较多，可以使用set<string>作为同义词容器
*/
class SynonymBase {
private:
    map<string, set<string>> synonyms;
public:
    /*省略 add 和 query 函数*/
    bool _has_synonym(string word1, string word2){
        return synonyms.find(word1) != synonyms.end() && synonyms[word1].find(word2) != synonyms[word1].end();
    }
    bool isSynonyms(string word1, string word2){
        if(word1 == word2) return true;
        else if(_has_synonym(word1, word2) || _has_synonym(word2, word1)) return true;
        else return false;
    }
};
```



