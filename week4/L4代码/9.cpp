#include <iostream>
using namespace std;
class A
{
    public:
    int data;
    A(int i){data=i;}
    A& operator+=(A& a){
        data += a.data;
        return *this;
    }
};
A operator+(A& a1, A& a2){
    A new_a(a1.data+a2.data);
    return new_a;
}

int main(){
    A a1(2), a2(3);
    a1 += a2;
    cout<<a1.data<<endl;
    cout<< (a1+a2).data <<endl;
    return 0;
}
