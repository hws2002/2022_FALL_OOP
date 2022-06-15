#include<iostream>
using namespace std;

void bar(char ch, int i) {
    cout << "bar " << ch << ' ' << i << " ";
    return ;
}

class func {
    public: //(7)
        void operator()(char ch, int i) const { 
            cout << "func " << ch << ' ' << i << " ";
        }
};

template<class Pclass>
void foo(char ch, int i, Pclass p) { // (6)
    p(ch, i);
}

int main() {
    void (*P) (char, int); // (1)
    P = bar; // (2)
    foo('e', 13, P); // (3) 

    auto F = func(); // (4)
    foo('e', 13, F); // (5)
}