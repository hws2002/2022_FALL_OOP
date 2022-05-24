#include <iostream>
#include <string>

namespace Campus {
    int building_number;
};

namespace ComputerScience {
    using Campus::building_number;

    std::string dean;
    struct Student {
        std::string id;
        int age;
    };
    int student_number;
    void setDean(std::string name) {
        dean = name;
    }
    void setStudentNumber(int number) {
        student_number = number;
    }
    void setStudent(Student &s, std::string id, int age) {
        s.id = id;
        s.age = age;
    }
};

namespace THU {
    using namespace ComputerScience;
    std::string principle;

    int student_number; 
    void setStudentNumber(int number) {
        student_number = number;
    } 
    void setPrinciple(std::string name) {
        principle = name;
    }
};

// void choiceA() {
//     using namespace THU;
//     setStudentNumber(10000); // (1)
// }

// void choiceB() {
//     using namespace THU;
//     ComputerScience::setStudentNumber(1000); // (2)
// }

// void choiceC() {
//     using namespace THU;
//     ComputerScience::setStudentNumber(1000);
//     THU::setStudentNumber(10000);
//     std::cout << student_number; // (3)
// }

void choiceD() {
    using THU::setDean;
    setDean("Xia Yin"); // (4)
}

void choiceE() {
    using namespace ComputerScience;
    setStudentNumber(10000);
}

int main() {
    // choiceA();
    // choiceB();
    // choiceC();
    choiceD();
    choiceE();
}