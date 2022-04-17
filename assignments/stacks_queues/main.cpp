#include <iostream>
#include "stack.h"
#include <unistd.h>


int main()
{
  Stack *s = new Stack();
  std::cout << s->is_empty() << "\n";

  try{
    std::cout << s->top() << "\n";
  }
  catch (int e){
    std::cout << "Tried to get top when empty, code: " << e << "\n";
  }
  

  s->push(5);
  s->push(10);
  s->push(15);

  std::cout << s->is_empty() << "\n";
  std::cout << s->top() << "\n";

  int val = s->pop();
  std::cout << val << " " << s->top() << "\n";

  try{
    val = s->pop();
    std::cout << val << " " << s->top() << "\n";
  } catch (int e){
    std::cout << "Tried to pop when empty, code: " << e << "\n";
  }
  try{
    val = s->pop();
    std::cout << val << " " << s->top() << "\n";
  } catch (int e){
    std::cout << "Tried to pop when empty, code: " << e << "\n";
  }
  
  s->~Stack();
  std::cout << s->is_empty() << "\n";

  return 0;
}
