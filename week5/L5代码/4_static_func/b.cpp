//b.cpp
extern int add_j(int k); 
//链接时出错，因为add_j为静态函数，仅能用于其声明的文件a.cpp
int add() { return add_j(1); };

