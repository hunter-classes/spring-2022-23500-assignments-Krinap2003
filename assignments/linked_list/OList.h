#pragma once
#include "ONode.h"

class OList{
    private:
        ONode *head;

    public:
        OList();
        ~OList();
        void insert(int data);
        void remove(int index);
        int get(int loc);
        bool contains(int data);
        void reverse();
        std::string toString(); // for testing and debugging

};
