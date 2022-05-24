class A
{
private:
	int a = 1;	   //声明+初始化
	double b{2.0}; //声明+初始化,就地初始化
public:
	A() {}							   // a=1 b=2.0,默认构造函数,缺省构造函数
	A(int i) : a(i) {}				   // a=i b=2.0
	A(int i, double j) : a(i), b(j) {} // a=i b=j
};

//这份文件虽然没有编译错误，但没有main函数，因此不能运行