#include <iostream>
using namespace std;

class SmallInt{
public:
//构造函数:从int转换为SmallInt
    SmallInt (int i=0): val(i){
        cout<<"SmallInt_Init"<<endl;
    }
    operator int() const { //转换运算符:从SmallInt 转换为int
        cout<<"Int_Transform"<<endl;
        return val; 
    }
    void print() { 
        cout << val << endl; 
    }
private:
    size_t val;
};
int main()
{
	SmallInt si;
	si = 4.10;//译器默认的=赋值运算
	si = si + 3;
	si.print();
	return 0;
}

//SamllInt_Init
//SmallInt_Iint
//Int_transform
//SmallInt_Init
//7
/*
Si = 4.10;  4.10  4   SmallInt(4) --》编译器默认的=赋值运算
Si= si+3  这里，为什么不能采用 3SmallInt（3）再加呢？
因为： 编译器不能自动生成默认+的重载版本； 所以只会产生 si --》 int 调用转换运算符

然后如果我们增加一个+号重载，会怎么样？ 编译器提示出错，模糊调用。
当只有+重载的时候，所有的整数都会转换为SmallInt (调用构造函数转换），即第二种转换类型
*/