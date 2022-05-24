#include <iostream>
using namespace std;

class Instrument {
public:
  virtual void play() { cout << "Instrument::play" << endl; }
};

class Wind : public Instrument {
public:
  void play() { cout << "Wind::play" << endl; }
};

void tune(Instrument ins) {
  ins.play(); /// 晚绑定只对指针和引用有效，这里早绑定 Instrument::play
}

int main() {
  Wind flute;
  tune(flute); /// 向上类型转换，对象切片
  return 0;
}

