#include <iostream>
#include "stack.h"


int main()
{
  Stack *s = new Stack();
  std::cout << s->is_empty() << "\n";

  s->push(5);
  s->push(10);
  s->push(15);

  std::cout << s->is_empty() << "\n";
  std::cout << s->top() << "\n";

  int val = s->pop();
  std::cout << val << " " << s->top() << "\n";

  s->~Stack();
  std::cout << s->is_empty() << "\n";

  return 0;
}
