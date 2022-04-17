#pragma once
#include "Node.h"

class List{
    private:
        Node *head;

    public:
        List();
        ~List();
        void insert(int data);
        void insert2(int i, int d);
        void remove(int index);
        int get(int loc);
        bool contains(int data);
        void reverse();
        std::string toString(); // for testing and debugging

};
