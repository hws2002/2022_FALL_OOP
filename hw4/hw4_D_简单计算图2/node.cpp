#include "node.h"

Node::~Node(){};

void PlaceholderNode::calc() {};

void PlaceholderNode::set_val(float val){
    value_ = val;
};