#include <iostream>
#include "Node.h"

Node::Node() : next(nullptr) //construtor that set it to default values.
{
}

Node::Node(Person *data){
    this->data = data;
    this->next = nullptr;
}

Node::Node(Person *data,Node *next){
    this->data = data;
    this->next = next;
}

void Node::setPerson(Person *data){
    this->data = data;
}

void Node::setNext (Node *next){
    this->next = next;
}

Person* Node::getPerson(){
    return this->data;
}

Node *Node::getNext()
{
    return this->next;
}