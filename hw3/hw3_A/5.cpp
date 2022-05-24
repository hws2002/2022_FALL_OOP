#include <iostream>
using namespace std;
class A {
    public:
        int a=1;
    protected:
        int b=2;
    private:
        int c=3;
};

class B {
    public:
        int d=4;
    protected:
        int b=5;
    private:
        int e=6;
};

class C: public A, private B{
    public:
        void print() {
            cout << [1] << endl;
        }
};

int main() {
    C obj_c;
    obj_c.print();
    cout << [2] << endl;
    return 0;
}
