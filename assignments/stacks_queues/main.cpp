#include <iostream>
#include "stack.h"
#include "queue.h"
#include <unistd.h>


int main()
{

  //Testing Stack
  std::cout<<"\n-------------- Testing Stack ----------------\n\n";
  Stack *s = new Stack();
  std::cout <<"Is Stack Empty: "<< s->is_empty() << "\n\n";

  try{
    std::cout << s->top() << "\n\n";
  }
  catch (int e){
    std::cout << "Tried to get top when empty, code: " << e << "\n\n";
  }
  

  s->push(5);
  s->push(10);
  s->push(15);

  std::cout <<"Is Stack Empty: "<< s->is_empty() << "\n\n";
  std::cout <<"Top element of the Stack: "<< s->top() << "\n\n";

  int val = s->pop();
  std::cout <<"Tried to pop this value: "<< val << "\nNew top " << s->top() << "\n";

  try{
    val = s->pop();
  std::cout <<"Tried to pop this value: "<< val << "\nNew top " << s->top() << "\n\n";
  } catch (int e){
    std::cout << "Tried to pop when empty, code: " << e << "\n";
  }

  try{
    val = s->pop();
    std::cout << val << " " << s->top() << "\n";
  } catch (int e){
    std::cout << "Tried to pop when empty, code: " << e << "\n\n";
  }


  s->~Stack();
  std::cout <<"Is stack empty after destructing: "<< s->is_empty() << "\n\n";



  //Testing Queue
  std::cout<<"-------------- Testing Queue ----------------\n\n";

  Queue *q = new Queue();
  std::cout<<"Is the queue full: "<<q->is_full()<<"\n\n";
  std::cout<<"Is the queue empty: "<<q->is_empty()<<"\n\n";
  

  q->enqueue(10);
  std::cout<<q->printQueue()<<"\n";
  std::cout<<"Front: "<<q->front()<<"\n\n";

  std::cout<<"sequeue: "<<q->sequeue()<<"\n\n";
  std::cout<<"Is the queue empty: "<<q->is_empty()<<"\n\n";

  try{
    std::cout<<q->front()<<"\n";
  }
  catch(int e){
    std::cout<< "Queue is empty Error Code: "<< e <<std::endl;
  }

  q->enqueue(10);
  q->enqueue(20);
  q->enqueue(30);
  std::cout<<"\nAdded new elements to the queue \n"<<q->printQueue()<<"\n";
  std::cout<<"Front: "<<q->front()<<"\n";
  q->enqueue(40);
  q->enqueue(50);
  std::cout<<q->printQueue()<<"\n";
  std::cout<<"Front: "<<q->front()<<"\n\n";

  std::cout<<"Is the queue full: "<<q->is_full()<<"\n";
  try{
      q->enqueue(60);
  }
  catch(int e){
    std::cout<< "Queue is full Error Code: "<< e <<"\n"<<std::endl;
  }
    std::cout<<q->printQueue()<<"\n";

  
  q->sequeue();
  q->sequeue();
  q->sequeue();

  // q->~Queue();
  // std::cout<<"Destructing\n";
  // std::cout<<"Is the queue full: "<<q->is_full()<<"\n";

  return 0;
}
