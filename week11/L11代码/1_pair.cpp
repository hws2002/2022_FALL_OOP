#include <string>
int main(){
  std::pair<std::string, double> p1("Alice", 90.5);
  std::pair<std::string, double> p2;

  p2.first = "Bob";
  p2.second = 85.0;

  auto p3 = std::make_pair("David", "95.0");
  return 0;
}

