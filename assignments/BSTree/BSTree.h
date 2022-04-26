#pragma once
#include "Node.h"
#include <iostream>

class BSTree{
    private:
    Node *root;

    public:
    BSTree();
    void insert(int d);
    std::string Transverse(Node *l);
    std::string get_debug_string();
    void setup();

};