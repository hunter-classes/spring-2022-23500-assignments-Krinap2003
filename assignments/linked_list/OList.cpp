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
Insert a new data in increasing order
*/
void OList::insert(int data)
{
    // create a new node
    ONode *walker = head;
    ONode *new_node = new ONode(data);
    
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

/*
Return the data at the given lacation as the parameter
*/
int OList::get(int loc)
{
    int result = 0;
    ONode *walker = head;

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
void OList::remove(int index)
{
    int i = 0;
    ONode *walker = head;
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
    ONode *free = walker->getNext();
    walker->setNext(walker->getNext()->getNext());
    delete free;
}

/**/
bool OList::contains(int data)
{
    std::cout.setf(std::ios::boolalpha);
    bool result;
    ONode *walker = head;

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
void OList::reverse()
{
   ONode *walker = head;
   ONode *trailer=nullptr; // this one follows behind walker;
    while(walker)
    {
      ONode *nextWalker = walker->getNext();
      walker->setNext(trailer);
      trailer=walker;
      walker=nextWalker;
    }
    head = trailer;
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