#include <iostream>
using namespace std;


class Dst { //目标类Destination
public:
  Dst() { cout << "Dst::Dst()" << endl; }
};



class Src { //源类Source
public:
  Src() { cout << "Src::Src()" << endl; }
    operator Dst() const { 
      cout << "Src::operator Dst() called" << endl;
      return Dst(); 
    }
};
void Transform(Dst d) { } 

int main()
{
  Src s;
  //Src::Src()
  Dst d1(s);
  //Src::operator
  //Dst::Dst()

  Dst d2 = s;
  //Src::operator Dst() called
  //Dst::Dst()
  Transform(s);    
  //Src::operator Dest() 
  //Dst::Dst();
  return 0;
}

