#include <iostream>
using namespace std;

class Test
{

public:
    int id;
    Test(int i) : id(i) { cout << "obj_" << id << " created\n"; }

    friend istream &operator>>(istream &in, Test &dst);
    friend ostream &operator<<(ostream &out, const Test &src);
};
istream &operator>>(istream &in, Test &dst)
{
    in >> dst.id;
    return in;
}
ostream &operator<<(ostream &out, const Test &src)
{
    out << src.id << endl;
    return out;
}

int main()
{
    Test obj(1);
    cout << obj; // operator<<(cout,obj)
    cin >> obj;  // operator>>(cin,obj)
    cout << obj;
    ostream& out1 = operator<<(cout, obj);
    return 0;
}
