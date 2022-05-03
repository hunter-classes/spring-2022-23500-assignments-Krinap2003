#pragma once
#include "Node.h"
#include <iostream>

class BSTree{
    private:
    Node *root;

    public:
    BSTree();
    void insert(int d);
    // void rinsert(int d);
    // void rinsert(int d, Node *p);
    std::string traverse(Node *n);
    std::string get_debug_string();
    int search(int value);
    int rsearch(int value);
    int rsearch(int value, Node *p);
    void deleteNum(int d);
    void setup();

};