class Test{};

Test& func(){
  Test t;
  return t;
}

int main() {
  Test& t = func();
  return 0;
}