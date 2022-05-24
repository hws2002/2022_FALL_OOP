#include <iostream>
using namespace std;

class Base{
public:
    Base() { func1(); }
    virtual void func1() {cout << "Base" << endl; }
};
class Derived : public Base{
public:
    Derived() { func1(); }
    void func1() {cout << "Derived" << endl; }
};
int main(){
    Base* p = new Derived();
    return 0;
}

//Derived;
//