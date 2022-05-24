#include <string>
#include <map> 

int main() {
    std::map<std::string, std::string> M;
    M["fp"] = "c";
    M["oop"] = M["fp"] + "++"; // M["oop"] = "c++"
    return 0;
}

