# **string 字符串类**

## 构造方式
```C++
string s1;//默认空字符串
string s2(s0, 8, 3);		 //截取：“str”，index从8开始，长度为3
string s3(“Another character sequence”, 12);		  //截取：“Another char”
string s4(10, 'x');		 //复制字符：xxxxxxxxxx
string s5(s0.begin(), s0.begin()+7);					 //复制截取: Initial
```

**새롭게 알게된 지식**

1. 원래 있던 string 의 부분만 가져올수있음 (截取！)
2. (10,'x') -> xxxxxxxxxxx


## 함수 : **c_str()**

!! 常量字符指针(const char*)，不能修改 !!
```C++
string s0("some string");
s0.c_str();
```

## **string类常用函数**
vector와 비슷하게 사용가능
```c++
访问/修改元素：cout << str[1]; str[1]='a';
查询长度：str.size()
清空:     str.clear()
查询是否为空：str.empty()
迭代访问: for(char c : str)
向尾部增加：		str.push_back('a');		str.append(s2);
```


**새롭게 알게된 지식**
string도 push_back, append 함수를 쓸수 있다!!!?

**不同之处** // 어떤 不同之处인지 모르겠음?
1. 查询长度也可以使用str.length()，与size()返回值相同
2. 向尾部增加也可以使用 str += 'a' 或者 str += s2

### **拼接**
string fullname = firstname + " " + lastname;

**注意：拼接的时间复杂度为生成的字符串长度**

例如：
```C++
	for(int i = 0; i < n; i++)
      allname = allname + name[i] + "\n"
	//时间复杂度O(n^2*L)的时间，L表示每个子串的平均长度
```
拼接多个字符串最好使用 operator+= 或者 stringstream

### **比较**

我们可以直接使用运算符按字典序比较字符串大小
```C++
string a = "alice", b = "bob";
a == b //False
a < b  //True
```

### **数值类型字符串化**

```C++
to_string(1)//"1"
to_string(3.14)//"3.14"
to_string(3.1415926)//"3.141593" 注意精度损失
to_string(1+2+3)//"6"
```

### **字符串转数值类型**
```C++
int a = stoi("2001")		  //a=2001
std::string::size_type sz;  //代表长度的类型 无符号整数
int b = stoi("50 cats", &sz)  //b=50 sz=2 代表读入长度
int c = stoi("40c3", nullptr, 16) //c=0x40c3 十六进制
int d = stoi("0x7f", nullptr, 0)  //d=0x7f 自动检查进制
double e = stod("34.5")	  //e=34.5
```

## **string 输入方式**

**三种输入方式**
```C++
//读取可见字符直到遇到空格
cin >> firstname;		//Mike

//读一行
getline(cin, fullname); //Mike William

//读到指定分隔符为止（可以读入换行符）
getline(cin, fullnames, ‘#’);		//“Mike William\nAndy William\n"

```
