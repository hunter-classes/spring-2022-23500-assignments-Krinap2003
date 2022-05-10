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
    int countLeaves();
    int countLeavesHelper(Node *p);
    int getHeight();
    int heightHelper(Node *p);
    int sumAtLevel(int level);
    int sumAtLevelHelper(Node *p, int level, int k);
    void setup();

};