class Student {
 int ID1; //声明
 int ID2; //声明
public:
    Student(int id) : ID2(id), ID1(ID2) { }
    //编译器先初始化ID1，再初始化ID2，因此ID1的值将不可预测
};

//这份文件虽然没有编译错误，但没有main函数，因此不能运行