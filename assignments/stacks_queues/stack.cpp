#include <iostream>
#include "stack.h"


//Constructor
Stack::Stack(){
  stack = new List();
  size = 0;
}

//Destructor
Stack::~Stack(){
  delete stack;
  size = 0;
}

//Push the item in front of the stack
void Stack::push(int item){
  stack->insert2(0, item);
  size++;
}

//Removes and return the value at the top of the stack
int Stack::pop(){
  if(size<=0)
  {
    throw STACK_ERR_EMPTY;
  }
  int val = stack->get(0);
  size--;
  stack->remove(0);
  return val;
}


//Return the values at the top of the stack
int Stack::top(){
  if(size<=0)
  {
    throw STACK_ERR_EMPTY;
  }
  return stack->get(0);
}


//Return True if the stack is empty
bool Stack::is_empty(){
  std::cout.setf(std::ios::boolalpha);
  return size == 0;
}
