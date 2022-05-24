#include <iostream> 
using namespace std;
class A { 
private: 
    int a;
    void f(int i=2) { a = i; } 
public:
    void f(int i, int j=2) { a = i + j; } 
    int get_a() { return a; }
};
int main() {
    A aa;
    aa.f(1,2);
    cout << aa.get_a() << endl; return 0;
}