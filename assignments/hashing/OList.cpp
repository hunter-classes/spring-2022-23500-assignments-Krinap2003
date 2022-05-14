#include <iostream>
#include "OList.h"
#include "Person.h"
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
  Node *trailer;
  //std::cerr << "Destructing\n";
  while(head != nullptr){
    trailer = head;
    head = head->getNext();
    delete trailer;
  }
}


/*
Insert a new data in increasing order
*/
void OList::insert(Person *p) {
    Node *temp = new Node(p);
    temp->setNext(head);
    this->head = temp;
}


/*
Insert data at a given lacation at as the parameter
*/
void OList::insert(int loc, Person *p)
{
  Node *tmp = new Node(p);

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
Remove the data at the given index of the list 
*/
void OList::remove(int index)
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
String representation of the entire linked list
*/
std::string OList::toString()
{
    Node *walker = head;
    std::string s = "";
    while(walker != nullptr)
    {
        s += walker->getPerson()->get_name() + "->";
        walker = walker->getNext();
    }
    s = s+"nullptr"; 

    return s;
}


Person* OList::get(std::string name){
    Node* traveler = head;
    while(traveler!=nullptr && traveler->getPerson()->get_name()!=name){
        traveler=traveler->getNext();
    }
    if (traveler==nullptr)
        return nullptr;
    return traveler->getPerson();
}