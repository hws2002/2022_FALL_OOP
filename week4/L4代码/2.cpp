class Info {
public:
    Info() { Init(); }
    Info(int i) : Info() { id = i; }
    Info(char c) : Info() { gender = c; }
private:
    void Init() { }// 其他初始化,委派构造函数
    int id;
    char gender;
};

//这份文件虽然没有编译错误，但没有main函数，因此不能运行
