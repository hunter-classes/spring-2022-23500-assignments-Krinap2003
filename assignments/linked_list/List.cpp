#include <iostream>
#include "List.h"

List::List(){
    head = nullptr;
}

void List::insert(std::string data)
{
    // create a new node
    Node *new_node = new Node(data);

    //insert the new node
    new_node->setNext(head);
    head = new_node;
}

std::string List::toString()
{
    Node *walker = head;
    std::string s = "";
    while(walker != nullptr)
    {
        s = s + walker->getData() + "-->";
        walker = walker->getNext();
    }
    s = s+"nullptr"; 
    return s;
}

List::~List(){
    Node *walker = head;
    while(walker != nullptr)
    {
        delete walker;
        walker = nullptr;
    }
}

void List::remove(std::string data)
{
    Node *walker = head;
    // if(head->getData() == data)
    // {
    //    head = walker->getNext();
    // }
    while(walker != nullptr)
    {
        if(walker->getNext()->getData() == data)
        { 
            walker->setNext(walker->getNext()->getNext());
            // delete walker->getNext();
            // walker->setNext(nullptr);
            break;
        }
         walker = walker->getNext();
     }
}

// Node List::locate(std::string data)
// {
//     Node *walker = head;
//     while(walker != nullptr)
//     {
//         if(walker->getData() == data)
//         {
//             return *walker;
//             break;
//         }
//         walker = walker->getNext();
//      }
// }
