#include <iostream>
using namespace std;

template<typename T0>
T0 func(T0 a, T0 b){
    T0 c = a + b;
    return c;
}

template<typename T1>
T1 func2(T1 a, T1 b){
    T1 c = a - b;
    return c;
}

int main(){
    int a = func(1.2, 1.3); // (1)
    int b = func2(func(1, 2), func(2, 3)); //(2)
    // int c = func(1, 1.2); // (3)
    int d = func<int>(1, 1.2); // (4)
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<d<<endl;
    return 0;
}