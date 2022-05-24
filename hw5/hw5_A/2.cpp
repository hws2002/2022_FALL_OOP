#include <iostream>
#include <tuple>

void choiceA() {
    std::tuple<int, std::string> a;
}

void choiceB() {
    std::tuple<int, int> a;
    auto b = std::make_tuple(2022, 2023);
    a = b;
}

void choiceC() {
    std::tuple<int, int> a;
    auto b = std::make_tuple(2022, 2023);
    a = b;
    std::cout << std::get<0>(a) << " " << std::get<1>(a) << std::get<2>(a) << std::endl;
}

void choiceD() {
    std::tuple<int, int> a = std::make_tuple(1299, 1923);
    int number1;
    int number2;
    a = std::tie(number1, number2) = std::make_tuple(395, 1453);
}

void choiceE() {
    std::tuple<int, int, int> long_tuple = std::make_tuple(0, 0, 0);
    std::tuple<int, int> short_tuple = long_tuple;
}

int main() {
    choiceA();
    choiceB();
    choiceC();
    choiceD();
    choiceE();
    return 0;
}