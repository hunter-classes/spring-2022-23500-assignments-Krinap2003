#include <iostream>
#include "OList.h"
#include <string>

/*
Constructor 
*/
OList::OList(){
    head = nullptr;
}

/*
Deconstructor
*/
OList::~OList(){
  ONode *trailer;
  std::cerr << "Destructing\n";
  while(head != nullptr){
    trailer = head;
    head = head->getNext();
    delete trailer;
  }
}


/*
Insert a new data at the head
*/
void OList::insert(int data)
{
    // create a new node
    ONode *new_node = new ONode(data);
    
    //insert the new node
    new_node->setNext(head);
    head = new_node;
}

/*
Insert data at a given lacation at as the parameter
*/
void OList::insert(int loc, int data)
{
  ONode *tmp = new ONode(data);

  ONode *walker = head;
  ONode *trailer=nullptr; // this one follows behind walker;
  
  while (walker != nullptr && loc > 0)
  {
    trailer = walker;
    walker = walker->getNext();
    loc = loc - 1;
  }
  // walker is at n, trailer is at the point before the insertion
  // point

  // check to see if we're trying to insert beyond the end
  // Note: we can insert a new last element.

  if (loc > 0)
  {
    throw std::out_of_range("Out of range");
  }

  // inserting at location 0 will have trailer = nullptr
  // so we have to deal with that special case
  if (trailer==nullptr)
  {
    tmp->setNext(head);
    head=tmp;
  } else
  {
    // and finally the normal insert code
    tmp->setNext(walker);
    trailer->setNext(tmp);
  
  }
}

/*
String representation of the entire linked list
*/
std::string OList::toString()
{
    ONode *walker = head;
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