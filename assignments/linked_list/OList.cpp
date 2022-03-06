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
    else
    return -1; 
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
     while(walker != nullptr )
    {
        if(walker->getNext() == nullptr)
        {
            head = walker;
            break;
        }

        walker = walker-> getNext();
    }

}

/*
return the lenght of the linked list
*/
int OList::length(){
  int l = 0;
  ONode *walker = head;
  while (walker){
    l++;
    walker = walker->getNext();
  }
  return l;
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