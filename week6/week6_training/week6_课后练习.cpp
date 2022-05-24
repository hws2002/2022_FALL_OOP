/*
引用与复制
编写一个头文件，实现三个全局函数f1,f2和f3。Test类的实现如课件32、46、47页所示。
*/

int main() {
	Test a, b;
	Test A = f1(a);
	Test& B = f2(b);
	Test C = f3(a, b);
	return 0;
}
/*
Test(): this->buf @ 0x1008c20
Test(): this->buf @ 0x1009050
Test(const Test&) called. this->buf @ 0x1009070
Test(const Test&) called. this->buf @ 0x1009090
Test(Test&&) called. this->buf @ 0x1009090
~Test(): this->buf @ 0
Test(Test&&) called. this->buf @ 0x1009090
~Test(): this->buf @ 0
~Test(): this->buf @ 0x1009070
Test(Test&&) called. this->buf @ 0x1008c20
Test(const Test&) called. this->buf @ 0x1009070
~Test(): this->buf @ 0
Test(Test&&) called. this->buf @ 0x1009070
~Test(): this->buf @ 0
~Test(): this->buf @ 0x1009070
~Test(): this->buf @ 0x1009090
~Test(): this->buf @ 0x1008c20
~Test(): this->buf @ 0x1009050
*/

/*
类型转换
创建一个Course类，包含数据成员教师姓名（Name）、学分（Credit）、课程难度（Diff）。并编写类型转换运算符将一个Course对象转换成string、int、double，分别用于输出Name、Credit、Diff。并思考是否应该将这些转换运算符设置为explicit？
*/

int main() {
	Course oop(Name=“Huang”, Credit=2, Diff=99.6);
	cout << oop << endl;
	cout << static_cast<string>(oop) << endl;
	cout << static_cast<int>(oop) << endl;
	cout << static_cast<double>(oop) << endl;
	return 0;
}
