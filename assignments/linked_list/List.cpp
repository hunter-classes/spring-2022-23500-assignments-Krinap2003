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