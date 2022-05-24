template<typename T, unsigned size>
class array {
  T elems[size];
}; 

int main(){
  int n = 5;
  //array<char, n> array0; //不能使用变量
  const int m = 5;
  array<char, m> array1; //可以使用常量
  array<char, 5> array2; //或具体数值
  return 0;
}
