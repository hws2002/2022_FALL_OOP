#include <iostream>
#include <cstring>
using namespace std;

class Pointer {
    int *m_arr;
    int m_size;
public:
    Pointer(int i):m_size(i) { //构造
        m_arr = new int[m_size];
        memset(m_arr, 0, m_size*sizeof(int));
    }
    ~Pointer(){/*delete []m_arr;*/} //析构
    void set(int index, int value) {
        m_arr[index] = value;
    }
    void print();
};
void Pointer::print()
{
    cout << "m_arr: ";
    for (int i = 0; i < m_size; ++ i)
    {
        cout << " " << m_arr[i];
    }
    cout << endl;
}

int main() {
 	Pointer a(5);
 	Pointer b = a; //调用默认的拷贝构造
    a.print();
    b.print();
    b.set(2, 3);//a의 m_arr까지도 변경될것임
    b.print();
    a.print();
    return 0;
}

