#include <iostream>
#include <list>
#include <algorithm>

void choiceA(std::list<int> lst) {
    auto begin = lst.begin();
    for (int i = 0; i < 2; ++i) {
        begin ++;
    }
    *begin = 100;
}

// void choiceB(std::list<int> lst) {
//     lst[2] = 100;
// }

void choiceC(std::list<int> lst) {
    auto result = std::find(lst.begin(), --lst.end(), 100);
    std::cout << *result << std::endl; // (1)
}

void choiceD(std::list<int> lst) {
    auto begin = lst.begin();
    auto end = --lst.end();
    lst.insert(begin, 101);
    std::cout << *end << std::endl; // (2)
}

// void choiceE(std::list<int> lst) {
//     auto result = std::find(lst.begin(), lst.end(), 4);
//     lst.erase(result);
//     --result;
//     std::cout << *result << std::endl; // (3)
// }

int main() {
    std::list<int> lst;
    for (int i = 0; i < 5; ++i) {
        lst.push_back(i * 2);
    }
    // std::list<int>::iterator ptr;
    // for(ptr = lst.begin();ptr!=lst.end();ptr++){
    //     std::cout<<*ptr<<std::endl;
    // }
    choiceA(lst);
    // choiceB(lst);
    choiceC(lst);
    choiceD(lst);
    // choiceE(lst);
    std::cout<<"===================================="<<std::endl;
    // for(ptr = lst.begin();ptr!=lst.end();ptr++){
    //     std::cout<<*ptr<<std::endl;
    // }
    return 0;
}