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
        bool contains(Person *p);
        Person* get(std::string name);
        std::string toString(); // for testing and debugging

};
