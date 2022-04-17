#include <iostream>
#include "List.h"
#include <string>

/*
Constructor 
*/
List::List(){
    head = nullptr;
}

/*
Deconstructor
*/
List::~List(){
  Node *trailer;
  std::cerr << "Destructing\n";
  while(head != nullptr){
    trailer = head;
    head = head->getNext();
    delete trailer;
  }
}


/*
Insert a new data in increasing order
*/
void List::insert(int data)
{
    // create a new node
    Node *walker = head;
    Node *new_node = new Node(data);
    
    if(head == nullptr || head->getData() > data)
    {
      new_node->setNext(head);
      head = new_node;
    }
    else{
      while (walker != nullptr)
      {
        if(walker->getNext() == nullptr)
        {
          walker->setNext(new_node);
          new_node->setNext(nullptr);
        }
        else if(walker->getNext()->getData() > data)
        {
          new_node->setNext(walker->getNext());
          walker->setNext(new_node);
          break;
        }
        walker = walker->getNext();
      }
    }
    
}

void List::insert2(int i, int d){
    Node *node = new Node(d), *p = head;
    if(i == 0){
        node->setNext(head), head = node; return;
    }
    while(--i) p = p->getNext();
    node->setNext(p->getNext());
    p->setNext(node);
}

/*
Return the data at the given lacation as the parameter
*/
int List::get(int loc)
{
    int result = 0;
    Node *walker = head;

    // using walker as a boolean is the sam as writing walker != nullptr
    while(walker != nullptr && loc > 0)
    {
        walker = walker-> getNext();
        loc--;
    }
    if(walker !=nullptr)
    return walker->getData();
    else{
      return INT_MIN; 
    }
}

/*
Remove the data at the given index of the list 
*/
void List::remove(int index)
{
    int i = 0;
    Node *walker = head;
    if(index == 0)
    {
        head = walker->getNext();
        return;
    }
    if(walker == nullptr)
    {
        throw std::out_of_range("out of range");
        return;
    }
    while(i < index-1)
    {
        walker = walker->getNext();
        i++;
    }
    Node *free = walker->getNext();
    walker->setNext(walker->getNext()->getNext());
    delete free;
}

/**/
bool List::contains(int data)
{
    std::cout.setf(std::ios::boolalpha);
    bool result;
    Node *walker = head;

    // using walker as a boolean is the sam as writing walker != nullptr
    while(walker != nullptr)
    {
        if(walker->getData() == data)
        {
            result = true;
            return result;
            break;
        }
        walker = walker-> getNext();
    }
   return false; 
}

/*
This should “reverse” the list - that is reverse the pointers
*/
void List::reverse()
{
   Node *walker = head;
   Node *trailer=nullptr; // this one follows behind walker;
    while(walker)
    {
      Node *nextWalker = walker->getNext();
      walker->setNext(trailer);
      trailer=walker;
      walker=nextWalker;
    }
    head = trailer;
}


/*
String representation of the entire linked list
*/
std::string List::toString()
{
    Node *walker = head;
    std::string s = "head->";
    while(walker != nullptr)
    {
        std::string str = std::to_string(walker->getData());
        s = s + str + "->";
        walker = walker->getNext();
    }
    s = s+"nullptr"; 

    return s;
}