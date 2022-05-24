#pragma once
#include "node.h"
#include "operation.h"

class Operation_Node : public OperationNodeTwo{
    public:
    int sign;
    Operation_Node(const string& _name, Node* ptr1,Node* ptr2,int _sign) : OperationNodeTwo(_name,ptr1,ptr2),sign(_sign){
    };
    void UpdateValue();
    ~Operation_Node(){};
};