#include <iostream>
#include <map>

void choiceA(std::map<std::string, int> m) {
    m["Monday"] = 100; // (1)
    std::cout << m.count("Monday") << std::endl; // (2)
}

// void choiceB(std::map<std::string, int> m) {
//     m.insert(std::pair<int, std::string>(200, "Tuesday")); // (3)
//     std::cout << m.count("Tuesday") << std::endl; // (4)
// }

void choiceC(std::map<std::string, int> m) {
    auto result = m.find("May");
    auto tmp = result == m.end();
    std::cout << tmp << std::endl; // (5)
}

void choiceD(std::map<std::string, int> m) {
    m.erase(++m.begin(), --m.end());
    std::cout << m.size() << std::endl; // (6)
}

void choiceE(std::map<std::string, int> m) {
    for (auto element: m) {
        std::cout << element.first << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::map<std::string, int> m;
    m["Sunday"] = 0;
    m["Monday"] = 1;
    m["Tuesday"] = 2;
    m["Wednesday"] = 3;
    m["Thursday"] = 4;
    m["Friday"] = 5;
    m["Saturday"] = 6;
    choiceA(m);
    // choiceB(m);
    choiceC(m);
    choiceD(m);
    choiceE(m);
    return 0;
}