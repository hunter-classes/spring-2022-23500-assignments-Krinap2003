#include "BSTree.h"
#include "Node.h"
#include <iostream>

BSTree::BSTree(){
    root = nullptr;
}

// void BSTree::insert(int d){

// }

std::string BSTree::Transverse(Node *l){
    std::string result = "";
    if(l == nullptr)
    {
        result += "";
    }
    else{
        result += (std::to_string(l->getData()))+"->"+Transverse(l->getRight()) + Transverse(l->getLeft());
     }
     return result;
}

std::string BSTree::get_debug_string(){

    // if(root == nullptr)
    // {
    //     return "";
    // }
    // else{
    //     return std::to_string(root->getData())+std::to_string(root->getLeft()->getData());
    //  }
    return Transverse(root);
}

void BSTree::setup(){
    Node *n = new Node(10);
    root = n;
    n  = new Node(20);
    root->setLeft(n);
    n  = new Node(30);
    root->setRight(n);
    n  = new Node(40);
    root->getLeft()->setLeft(n);
}

