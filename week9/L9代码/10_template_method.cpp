#include <iostream>
using namespace std;

class Base{
public:
    void action() {
        step1();
        step2();
        step3();
    }
    virtual void step1() { cout << "Base::step1" << endl; }
    virtual void step2() { cout << "Base::step2" << endl; }
    virtual void step3() { cout << "Base::step3" << endl; }
};

class Derived1 : public Base{
    void step1() { cout << "Derived1::step1" << endl; }
};
class Derived2 : public Base{
    void step2() { cout << "Derived2::step2" << endl; }
};

int main(){
    Base* ba[] = {new Base, new Derived1, new Derived2};
    for (int i = 0; i < 3; ++i) {
        ba[i]->action();
        cout<<"==="<<endl;
    }
    return 0;
}


