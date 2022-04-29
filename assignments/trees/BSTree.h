#pragma once
#include "Node.h"
#include <iostream>

class BSTree{
    private:
    Node *root;

    public:
    BSTree();
    void insert(int d);
    std::string traverse(Node *n);
    std::string get_debug_string();
    int search(int value);
    void setup();

};