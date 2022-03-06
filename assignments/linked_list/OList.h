#pragma once
#include "ONode.h"

class OList{
    private:
        ONode *head;

    public:
        OList();
        ~OList();
        void insert(int data);
        void insert(int loc, int data);
        void remove(int index);
        int get(int loc);
        bool contains(int data);
        void reverse();
        int length();
        std::string toString(); // for testing and debugging

        //void remove2(std::string data);
};
