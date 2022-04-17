#pragma once
#include "List.h"

class Stack{
private:
  List *stack;
  int size;

public:
  Stack();
  ~Stack();
  void push(int item); // add an item to the top
  int pop(); // remove and return an item from the top of the stack
  int top(); // returns but doesn't remove the value on top
  bool is_empty(); // returns true if stack is empty


};
