//b.cpp
extern int i; //链接时出错，因为i为静态全局变量，仅能用于其声明的文件a.cpp
extern int j;

int add_i(int k) { return k+i; };
int add_j(int k) { return k+j; };

