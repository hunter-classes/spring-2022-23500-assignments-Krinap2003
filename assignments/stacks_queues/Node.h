#pragma once 
#include <string>

class Node{
    private:
        int data;
        Node *next;

    public:
        Node();
        Node(int data);
        Node(int data, Node *next);

        void setData(int data);
        void setNext(Node *next);

        int getData();
        Node *getNext();
};