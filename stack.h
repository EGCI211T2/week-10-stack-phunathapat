
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
};


void Stack::push(int x){
  NodePtr new_node=new NODE(x);
  if(new_node){
        new_node->set_next(top); 
        top = new_node;  
        size++;        
   }
 else cout<< "Not enough"<<endl;
        
    
}

int Stack::pop(){
        NodePtr t=top;
        if (top == NULL) return -1;
        else {
        int value;
        value=t->get_value();
        top = top->get_next(); // 
        --size;
        delete t;
        return value;
        }
        cout << "Emtpy stack"<<endl ;
	//be careful of the empty stack!!!
    }

Stack::Stack(){
    top=NULL;
    size=0;
    
}
Stack::~Stack(){
    cout << "Clear the stack"<< endl;
    //delete all remaning stack (i.e. pop all) 
    int n = size;
    while (n>0){
    pop();
n--;}
    
}


#endif
