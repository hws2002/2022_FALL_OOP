#include "operation_node.h"
#include "operation.h"
void Operation_Node::UpdateValue(){
    float value1 = this->input1->value();
    float value2 = this->input2->value();
    value_ = value1 + sign*value2;
};