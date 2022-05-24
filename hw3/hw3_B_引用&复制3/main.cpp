#include <iostream>

using namespace std;

class Test {
    int *buf;
public:
    Test() {
        buf = new int(0);
        cout << "Test(): this->buf @ " << hex << buf << endl;
    }
    Test(int val) {
        buf = new int(val);
        cout << "Test(int): this->buf @ " << hex << buf << endl;
    }








    
    ~Test() {
        cout << "~Test(): this->buf @ " << hex << buf << endl;
        if (buf) delete buf;
    }
    Test(const Test& t) : buf(new int(*t.buf)) {
        cout << "Test(const Test&) called. this->buf @ "
            << hex << buf << endl;
    }
    Test(Test&& t) : buf(t.buf) {
        cout << "Test(Test&&) called. this->buf @ "
            << hex << buf << endl;
        t.buf = nullptr;
    }
    Test& operator= (const Test& right) {
        if (this != &right){
            if(buf) delete buf;
            buf = new int(*right.buf);
        }
        cout<<"copy_operator = done"<<endl;
        return *this;
    }
    Test& operator= (Test&& right) {
        if (this != &right){
            if(buf) delete buf;
            this->buf = right.buf;
            right.buf = nullptr;
        }
        cout<<"move_operator = done"<<endl;
        return *this;
    }
    void print(const char *name) {
        cout << name << ".buf @ " << hex << buf << endl;
    }
};


Test F(Test a){
     Test b = std::move(a);
     return b;
 }
 int main(){
     Test a;
     a = 1;
     Test A = F(a);
     return 0;
 }
/*

// A

Test(): this->buf @ 0x6000011d8030
Test(int): this->buf @ 0x6000011d8040
move_operator = done
~Test(): this->buf @ 0x0
Test(const Test&) called. this->buf @ 0x6000011d8030
Test(Test&&) called. this->buf @ 0x6000011d8030
Test(Test&&) called. this->buf @ 0x6000011d8030
~Test(): this->buf @ 0x0
Test(Test&&) called. this->buf @ 0x6000011d8030
~Test(): this->buf @ 0x0
~Test(): this->buf @ 0x0
~Test(): this->buf @ 0x6000011d8030
~Test(): this->buf @ 0x6000011d8040

Test(): this->buf @ 0x600000008000
Test(int): this->buf @ 0x600000008010
move_operator = done
~Test(): this->buf @ 0x0
Test(const Test&) called. this->buf @ 0x600000008000
Test(Test&&) called. this->buf @ 0x600000008000
~Test(): this->buf @ 0x0
~Test(): this->buf @ 0x600000008000
~Test(): this->buf @ 0x600000008010
// B
 Test F(const Test& a){
     Test b = std::move(a);//copy_constructor[1]
     return b;//move_constructor[2]
}
int main(){
     Test A = F(1); //constructor[5]
     //move_constructor[5]
     return 0;
}
// C
Test F(Test &&a){
    Test b = std::move(a);
    return b;
}
int main(){
    Test A = F(1);
    return 0;
}

Test(int): this->buf @ 0x600000008000
Test(Test&&) called. this->buf @ 0x600000008000
~Test(): this->buf @ 0x0
~Test(): this->buf @ 0x600000008000

Test(int): this->buf @ 0x600002c44030
Test(Test&&) called. this->buf @ 0x600002c44030
Test(Test&&) called. this->buf @ 0x600002c44030
~Test(): this->buf @ 0x0
Test(Test&&) called. this->buf @ 0x600002c44030
~Test(): this->buf @ 0x0
~Test(): this->buf @ 0x0
~Test(): this->buf @ 0x600002c44030

// D
 Test&& F(Test &a){
     Test b = a;
     return std::move(b);
 }
 int main(){
     Test A = F(Test(1));
     return 0;
}
// E
 const Test& F(const Test& a){
     Test b = a;
     return Test(1);
 }
 int main() {
     Test a;
     const Test &A = F(std::move(a));
     return 0;
 }

 const Test& F(const Test& a){//copy_constructor[0]
    Test b = a;//copy_assign[1]
    return Test(1);//constructor[2]
    //move_constructor[2]
}
int main() {
    Test a;//constructor[5]
    const Test &A = F(std::move(a));
    //move_constructor[6]
    return 0;
}

*/