#include <iostream>
using namespace std;

class Instrument {
public:
  void play() { cout << "Instrument::play" << endl; }
};
class Wind : public Instrument {
public:
  // Redefine interface function:
  void play() { cout << "Wind::play" << endl; }
};

void tune(Instrument& i) {
  i.play();
}
int main() {
  Wind flute;
  tune(flute); /// 引用的向上类型转换(传参)，编译器早绑定，无对象切片产生
  Instrument &inst = flute;  /// 引用的向上类型转换(赋值)
  inst.play();
  return 0;
}

