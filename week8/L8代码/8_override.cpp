#include <iostream>
using namespace std;

class Instrument {
public:
  virtual void play() { cout << "Instrument::play" << endl; }
};
class Wind : public Instrument {
public:
  void play() { cout << "Wind::play" << endl; }
     /// 重写覆盖(稍后：重写隐藏和重写覆盖的区别）
};

void tune(Instrument& ins) {
  ins.play(); /// 由于 Instrument::play 是虚函数，编译时不再直接绑定，运行时根据 ins 的实际类型调用。
}
int main() {
  Wind flute;
  tune(flute); /// 向上类型转换
  return 0;
}

