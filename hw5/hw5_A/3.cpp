#include <iostream>
#include <vector>

class Data {
private: 
    int _num;
public:
    Data(int num) : _num(num) {
        std::cout << "构造函数" << std::endl;
    }
    Data(const Data& d) : _num(d._num) {
        std::cout << "拷贝构造函数" << std::endl;
    }
    Data(Data&& d) : _num(d._num) {
        std::cout << "移动构造函数" << std::endl;
    }
    Data& operator=(const Data& d) {
        this->_num = d._num;
        std::cout << "拷贝赋值" << std::endl;
        return *this;
    }
    ~Data() {
        std::cout << "析构函数" << std::endl;
    }
};

void choiceA() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto end = vec.end();
    auto begin = vec.begin();
    std::cout << *begin << " " << *end << std::endl; // (1)
}

void choiceB() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto begin_add_2 = vec.begin() + 2;
    auto result = vec.erase(begin_add_2);
    std::cout << *result << std::endl; // (2)
}

void choiceC() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto end = vec.end();
    auto begin_add_2 = vec.begin() + 2;
    auto result = vec.erase(begin_add_2); // (3)
    std::cout << *end << std::endl;
}

std::ostream& operator << (std::ostream& output, std::vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        output << v[i] << " ";
    }
    output << std::endl;
    return output;
}

void choiceD() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << vec; // (4)
}

void choiceE() {
    std::vector<Data> vec;
    for (int i = 0; i < 4; ++i) {
        vec.push_back(Data(i));
    }
    auto begin = vec.begin();
    std::cout << "==分割线==" << std::endl;
    vec.insert(begin, Data(100)); // (5)
    std::cout << "==分割线==" << std::endl;
}

int main() {
    // choiceA();
    // choiceB();
    choiceC();
    // choiceD();
    choiceE();
    return 0;
}