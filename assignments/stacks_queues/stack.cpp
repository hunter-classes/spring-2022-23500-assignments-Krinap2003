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
  int val = stack->get(0);
  stack->remove(0);
  return val;
}

int Stack::top(){
  return stack->get(0);
}

bool Stack::is_empty(){
  return size == 0;
}
