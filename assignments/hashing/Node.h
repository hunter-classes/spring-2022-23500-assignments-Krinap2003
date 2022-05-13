#pragma once 
#include <string>
#include "Person.h"

class Node{
    private:
        Person *data;
        Node *next;

    public:
        Node();
        Node(Person *data);
        Node(Person *data, Node *next);

        void setPerson(Person *data);
        void setNext(Node *next);

        Person getPerson();
        Node *getNext();
};