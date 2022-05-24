#include <iostream>
using namespace std;

int main(){
    // int x;
    // int *y = &x;
    // int *z = &(x-7);
    const int &z = -1;
    cout<<z;
    return 0;
}