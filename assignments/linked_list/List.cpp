#include <iostream>
#include "List.h"

List::List(){
    head = nullptr;
}

List::~List(){
    Node *walker = head;
    while(walker)
    {
         Node *free = walker;
         walker = walker->getNext();
         delete free;
         free = nullptr;
    }
}

void List::insert(std::string data)
{
    // create a new node
    Node *new_node = new Node(data);
    
    //insert the new node
    new_node->setNext(head);
    head = new_node;
}

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

void List::remove(int index)
{
    int i = 0;
    Node *walker = head;
    if(index == 0)
    {
        head = walker->getNext();
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






// void List::remove2(std::string data)
// {
//     Node *walker = head;
//     if(head->getData() == data)
//     {
//        head = walker->getNext();
//        return;
//     }
//     while(walker != nullptr)
//     {
//         if(walker->getNext()->getData() == data)
//         { 
//             walker->setNext(walker->getNext()->getNext());
//             // delete walker->getNext();
//             // walker->setNext(nullptr);
//             break;
//         }
//          walker = walker->getNext();
//      }
// }