#pragma once
#include "Node.h"

class List{
    private:
        Node *head;

    public:
        List();
        void insert(std::string data);
        void remove(std::string data);
        //Node List::locate(std::string data);
        ~List();
        std::string toString();
};