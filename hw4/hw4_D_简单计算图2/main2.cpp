#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class Node {
protected:
    //结点数值
    float value_;

    //结点名字
    string name_;

public:
    Node(string _name, float _value = 0) : name_(_name), value_(_value) {}

    //interface of value_
    inline float value() { return value_; }

    //interface of name_
    inline string name() { return name_; }

    // 节点调用子节点的计算，之后更新自身值的操作
    virtual void calc() {}

    // 节点通过子节点更新value_的方法
    virtual void UpdateValue() {}

    virtual ~Node() = 0;

};

class PlaceholderNode : public Node {
public:
    PlaceholderNode(string name) : Node(name) {}
    void set_val(float val);
    void calc() /*override*/;
};

class ConstantNode : public Node {
public:
    ConstantNode(string name, float value) : Node(name, value) {}
};

Node::~Node(){};

// ConstantNode::ConstantNode(string name, float value) : Node(name,value){};

// ConstantNode::~ConstantNode(){};


// PlaceholderNode::PlaceholderNode(string name) : Node(name){};

void PlaceholderNode::calc() {
    
};

void PlaceholderNode::set_val(float val){
    value_ = val;
};

class OperationNodeTwo : public Node {
protected:
    //指向与运算符相连的操作数
    Node *input1, *input2;
public:
    OperationNodeTwo(string name, Node *x1, Node *x2) : Node(name), input1(x1), input2(x2) {}

    void calc() override;

    virtual ~OperationNodeTwo() = 0;

};
OperationNodeTwo::~OperationNodeTwo() = default;

void OperationNodeTwo::calc() {
	// 递归计算
    input1->calc();		
    input2->calc();		
	// 更新当前节点值 (根据input1和input2的value进行加法/减法)
    UpdateValue();		
}

class Operation_Node : public OperationNodeTwo{
    public:
    int sign;
    Operation_Node(const string& _name, Node* ptr1,Node* ptr2,int _sign) : OperationNodeTwo(_name,ptr1,ptr2),sign(_sign){
    };
    void UpdateValue();
    ~Operation_Node(){};
};

void Operation_Node::UpdateValue(){
    float value1 = this->input1->value();
    float value2 = this->input2->value();
    value_ = value1 + sign*value2;
};

// 通过string关键字查询Node*
class myMap {
public:
    myMap() = default;
    // 初始化存储数组的大小
    void initialize(int capacity_);

    // 插入操作
    void insert(const string &key, Node* value);

    // 重载下标号实现查找操作
    Node* operator[](const string &key);

    ~myMap();

private:
    int capacity, size = 0, history_size;
    string* key_list_;
    Node** value_list_;

    // 存储所有历史节点，在析构时使用
    Node** history_value_list_;

};

void myMap::initialize(int capacity_){
    capacity = capacity_;
  
    size = 0;
    key_list_ = new string[capacity];
    value_list_ = new Node*[capacity];

    history_size = 0;
    history_value_list_ = new Node*[capacity];
}

void myMap::insert(const string &key, Node* value) {
    // 先看是否有同名节点，若有则替换之
    for (int i = 0; i < size; ++ i) {
        if (key==key_list_[i]) {
            value_list_[i] = value; 
            return;
        }
    } 

    // 若没有同名节点，则新建一个
    key_list_[size] = key;
    value_list_[size] = value;
    size += 1;

    // 存储历史信息 
    history_value_list_[history_size++] = value;
}


Node* myMap::operator[](const string &key) {
    for (int i = 0; i < size; ++ i) {
        if (key==key_list_[i]) {
            return value_list_[i]; 
        }
    } 
    // 查找失败
	return nullptr;
}

myMap::~myMap() {    
    if(size) { 
        delete[] key_list_; 
        delete[] value_list_;

        // 析构出现过的节点
        for (int i = 0; i < history_size; ++ i) 
        	delete history_value_list_[i];	

        delete history_value_list_;
    }
}

// Graph类实现对计算图节点的管理以及计算操作的记录
class Graph {
private:
    // 管理计算图中的所有结点，同名节点仅保留最新版本，使用nodes->insert(key, value)增加节点
    myMap nodes_;

public:
    Graph(int num_node);

    //禁止默认拷贝构造，防止重复delete
    Graph(const Graph &) = delete;

    //禁止默认赋值，防止重复delete
    void operator=(const Graph &) = delete;

    //插入placeholder
    void InsertPlaceholder(const string &node_name);

    //插入constant
    void InsertConstant(const string &node_name, float value);

    //插入二元运算符结点
    void InsertOperation(const string &node_name, const string &operation_type, 
                            const string &input1, const string &input2);

    //进行EVAL操作 输入待EVAL的节点名称 以及placeholder的初始化列表
    void Eval(const string &node_name, const int &argument_num, 
                const string* argument_name_list_, const float* argument_value_list_);

    ~Graph();
};
Graph::Graph(int num_node) {
    // 预分配节点空间
    nodes_.initialize(num_node);
}

void Graph::InsertPlaceholder(const string &node_name) {
    // PlaceholderNode new_hnode(node_name);
    Node* pn = new PlaceholderNode(node_name);
    // std::cout<<pn<<endl;
    nodes_.insert(node_name,pn);
}

void Graph::InsertConstant(const string &node_name, float value) {
    Node* pn = new ConstantNode(node_name,value);
    // cout<<pn<<endl;
    nodes_.insert(node_name,pn);
}

void Graph::InsertOperation(const string &node_name, const string &operation_type, 
                                const string &input1, const string &input2) {
    // wait to fill, 根据operation_type的名字调用相应的运算符节点构造函数
    Node * p1 = nodes_[input1];
    // cout<<hex<<p1<<endl;
    Node * p2 = nodes_[input2];
    // cout<<hex<<p2<<endl;
    if(operation_type == "+"){
        Node * pn = new Operation_Node(node_name,p1,p2,1);
        // cout<<pn<<endl;
        nodes_.insert(node_name,pn);
    } else {
        Node * pn = new Operation_Node(node_name,p1,p2,-1);
        // cout<<pn<<endl;
        nodes_.insert(node_name,pn);
    }
}

void Graph::Eval(const string &node_name, const int &argument_num, 
                    const string* argument_name_list_, const float* argument_value_list_) {
    // wait to fill, 调用相应的placeholder的set_val函数
    for(int i=0;i<argument_num;i++){//여기 나오는 애들은 다 placeholder 포인터일것!
        PlaceholderNode * ptr = dynamic_cast<PlaceholderNode*>(nodes_[argument_name_list_[i]]);
        ptr->set_val(argument_value_list_[i]);
    }
    nodes_[node_name]->calc();//여기에 나오는 Node들은 전부다 Operation_Node들뿐임!
    float temp_value = nodes_[node_name]->value();
    cout << temp_value << endl;   
}

Graph::~Graph() {
    
}

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    // 最多产生n+m个节点
    Graph tf(n+m);

    for (int i = 0; i < n; ++i) {
        string node_name, node_type;
        cin >> node_name >> node_type;    //读入变量信息
        if (node_type == "P") tf.InsertPlaceholder(node_name);
        else if (node_type == "C") {
            float value;
            cin >> value;
            tf.InsertConstant(node_name, value);
        }
    }

    for (int i = 0; i < m; ++i) {        //读入结点信息
        string node_name, _, operation, left, right;
        cin >> node_name >> _ >> left >> operation >> right;
        tf.InsertOperation(node_name, operation, left, right);
    }

    for (int i = 0; i < q; ++i) {        //读入操作信息
        string op;
        cin >> op;
        if (op == "EVAL") {
            string node_name;
            int argument_num;

            cin >> node_name;
            cin >> argument_num;

            string* argument_name_list_ = new string[argument_num];
            float* argument_value_list_ = new float[argument_num];

            for (int j = 0; j < argument_num; ++ j) {
                cin >> argument_name_list_[j] >> argument_value_list_[j];
            }
 
            tf.Eval(node_name, argument_num, argument_name_list_, argument_value_list_);
 
            delete[] argument_name_list_;
            delete[] argument_value_list_;
        }
    }
    return 0;
}
