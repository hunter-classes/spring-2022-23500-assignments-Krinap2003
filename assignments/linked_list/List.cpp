#include <iostream>
#include "List.h"

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
Insert a new data at the head
*/
void List::insert(std::string data)
{
    // create a new node
    Node *new_node = new Node(data);
    
    //insert the new node
    new_node->setNext(head);
    head = new_node;
}


/*
Insert data at a given lacation at as the parameter
*/
void List::insert(int loc, std::string data)
{
  Node *tmp = new Node(data);

  Node *walker = head;
  Node *trailer=nullptr; // this one follows behind walker;
  
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
std::string List::get(int loc)
{
    std::string result = "";
    Node *walker = head;

    // using walker as a boolean is the sam as writing walker != nullptr
    while(walker != nullptr && loc > 0)
    {
        walker = walker-> getNext();
        loc--;
    }
    if(walker !=nullptr)
    return walker->getData();
    else
    return ""; 
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

/*
return the lenght of the linked list
*/
int List::length(){
  int l = 0;
  Node *walker = head;
  while (walker){
    l++;
    walker = walker->getNext();
  }
  return l;
}

/*
String representation of the entire linked list
*/
std::string List::toString()
{
    Node *walker = head;
    std::string s = "";
    while(walker != nullptr)
    {
        s = s +  walker->getData() + "->";
        walker = walker->getNext();
    }
    s = s+"nullptr"; 
    return s;
}