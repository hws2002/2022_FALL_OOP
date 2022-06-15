#include <iostream> 
using namespace std; 

void f1(shared_ptr<int> p1) {
    cout << p1.use_count();
}

shared_ptr<int> f2(shared_ptr<int> &p1){
    f1(p1);
    cout << p1.use_count();
    return p1;
}

void f3(shared_ptr<int>& p2){
    cout << p2.use_count();  // (1)
}

int main(){
    shared_ptr<int> p1(new int); //(2)
    f1(p1); //(3)
    cout << p1.use_count(); //(4)
    shared_ptr<int> p2 = f2(p1); //(5)
    cout << p1.use_count();  //(6)
    cout << p2.use_count();  //(7)
    f3(p2); // (8)
    cout << p1.use_count();  //(9)
    cout << p2.use_count();  //(10)
    return 0;
}

// 2
// 1
// 2
// 1
// 2
// 2
// 3
// 2
// 2
