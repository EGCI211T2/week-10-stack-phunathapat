#ifndef stack_h
#define stack_h
#include "node.h"

class Stack {
    NodePtr top;
    int size;
public:
    void push(int);
    int pop();
    Stack();
    ~Stack();
    int getSize(); 
};

Stack::Stack(){
    top=NULL;
    size=0;
}

void Stack::push(int x){
    NodePtr new_node = new NODE(x);
    if(new_node){
        new_node->set_next(top);
        top = new_node;
        size++;
    }
}

int Stack::pop(){
    NodePtr t = top;
    if (top == NULL) return -1; 
    
    int value = t->get_value();
    top = top->get_next();
    delete t;
    size--;
    return value;
}

int Stack::getSize(){
    return size;
}

Stack::~Stack(){
    while (size > 0){
        pop();
    }
}

#endif