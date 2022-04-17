#include <iostream>
#include "stack.h"



Stack::Stack(){
  stack = new List();
  size = 0;
}

Stack::~Stack(){
  delete stack;
  size = 0;
}

void Stack::push(int item){
  stack->insert2(0, item);
  size++;
}

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

int Stack::top(){
  if(size<=0)
  {
    throw STACK_ERR_EMPTY;
  }
  return stack->get(0);
}

bool Stack::is_empty(){
  return size == 0;
}
