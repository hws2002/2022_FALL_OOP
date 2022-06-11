#include <iostream>
using namespace std;

template <typename T> 
class SmartPtr;  //声明智能指针模板类
    
template <typename T>
class U_Ptr { //辅助指针
private:
  friend class SmartPtr<T>;
  //SmartPtr是U_Ptr的友元类
  U_Ptr(T *ptr) :p(ptr), count(1) { }
  ~U_Ptr() { delete p; }
  
  int count;   
  T *p; //实际数据存放                                                     
};
template <typename T>
class SmartPtr { //智能指针
  U_Ptr<T> *rp;
public:
  SmartPtr(T *ptr) :rp(new U_Ptr<T>(ptr)) { }
  SmartPtr(const SmartPtr<T> &sp) :rp(sp.rp) {
    ++rp->count; 
  }
  SmartPtr& operator=(const SmartPtr<T>& rhs) {
    ++rhs.rp->count; 
    if (--rp->count == 0) //减少自身所指rp的引用计数 pA = pB
      delete rp; //删除所指向的辅助指针
    rp = rhs.rp;
    return *this;
  }
  ~SmartPtr() {
    if (--rp->count == 0)
      delete rp;
  }
  T & operator *() { return *(rp->p); }
  T* operator ->() { return rp->p; }
};

int main(int argc, char *argv[]) {
  int *pi = new int(2);
  SmartPtr<int> ptr1(pi); //构造函数
  SmartPtr<int> ptr2(ptr1); //拷贝构造
  SmartPtr<int> ptr3(new int(3)); //能否ptr3(pi)???
  ptr3 =  ptr2; //注意赋值运算
  cout << *ptr1 << endl; //输出2
  *ptr1 = 20;
  cout << *ptr2 << endl; //输出20

  return 0;
}

