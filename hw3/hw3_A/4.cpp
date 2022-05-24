#include <iostream>
using namespace std;
int main(){
    int a=5;
    int &&x = a;
    // int &&x=3;x=5;
    cout<<x;
    return 0;
}