#pragma once
#include "Node.h"

class OList{
    private:
        Node *head;

    public:
        OList();
        ~OList();
        void insert(Person *p);
        void insert(int loc, Person *p);
        void remove(int index);
        Person get(Person *p);
        bool contains(Person *p);
        std::string toString(); // for testing and debugging
};
