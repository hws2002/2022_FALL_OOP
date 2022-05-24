#include "graph.h"
#include "operation_node.h"
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
    nodes_[node_name]->calc();
    float temp_value = nodes_[node_name]->value();
    cout << std::fixed << setprecision(2) << temp_value << endl;  
}

Graph::~Graph() {
}

