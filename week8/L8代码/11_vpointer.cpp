#include <iostream>
using namespace std;
#pragma pack(4) //按照4字节进行内存对齐

class NoVirtual{ //没有虚函数
  int a;
public:
  void f1() const {}
  int f2() const {return 1;}
};

class OneVirtual{ //一个虚函数
  int a;
public:
  virtual void f1() const {}
  int f2() const {return 1;}
};

class TwoVirtual{//两个虚函数
  int a;
public:
  virtual void f1() const {}
  virtual int f2() const {return 1;}
};


int main(){
    cout<<"int: "<<sizeof(int)<<endl;
    cout<<"NoVirtual: "<<sizeof(NoVirtual)<<endl;
    cout<<"void* : "<<sizeof(void*)<<endl;
    cout<<"OneVirtual: "<<sizeof(OneVirtual)<<endl;
    cout<<"TwoVirtual: "<<sizeof(TwoVirtual)<<endl;
	return 0;
}

