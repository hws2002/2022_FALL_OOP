#include <tuple>
std::tuple<int, double> f(int x){ 
    return std::make_tuple(x, double(x)/2);
}
int main() {
    int xval; 
    double half_x;
    std::tie(xval, half_x) = f(7);
    return 0;
}

