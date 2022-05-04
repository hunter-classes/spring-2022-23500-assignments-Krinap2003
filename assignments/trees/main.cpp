#include <iostream>
#include "Node.h"
#include "BSTree.h"

int main()
{

    // Node * n = new Node(20);
    // std::cout<<n->getData()<<"\n";


    // Node * n2 = new Node(30);
    // n->setLeft(n2);
    // n2 = new Node(40);
    // n->setRight(n2);

    // std::cout<<n->getLeft()->getData()<<"\n";
    // std::cout<<n->getRight()->getData()<<"\n";


    // BSTree *t = new BSTree();
    // t->setup();
    // std::cout<<t->get_debug_string()<<"\n";

    BSTree *t = new BSTree();
    t->setup();

    std::cout <<  t->get_debug_string() << "\n";
    int v = 15;

    
    try {
        int x  = t->search(v);
        std::cout << "Found: " << x << "\n";
    } catch (int e){
        std::cout << v << " not found\n";
        
    }
    try {
        int x  = t->rsearch(v);
        std::cout << "Found: " << x << "\n";
    } catch (int e){
        std::cout << v << " not found\n";
        
    }
    try {
        int x  = t->rsearch(22);
        std::cout << "Found: " << x << "\n";
    } catch (int e){
        std::cout << 22 << " not found\n";
        
    }

    t->insert(21);
    std::cout << "Insert 21:  "<< t->get_debug_string() << "\n";
    t->deleteNum(21);
    std::cout << "Delete 21:  "<< t->get_debug_string() << "\n";
    t->insert(22);
    std::cout <<  t->get_debug_string() << "\n";
    // t->insert(55);
    // std::cout <<  t->get_debug_string() << "\n";

    v=22;
    try {
        int x  = t->search(v);
        std::cout << "Found: " << x << "\n";
    } catch (int e){
        std::cout << v << " not found\n";
        
    }
    try {
        int x  = t->rsearch(v);
        std::cout << "Found: " << x << "\n";
    } catch (int e){
        std::cout << v << " not found\n";
        
    }

    t->deleteNum(22);
    std::cout << "Delete 22:  "<< t->get_debug_string() << "\n";
    t->insert(22);
    std::cout << "Insert 22:  "<< t->get_debug_string() << "\n";
    t->deleteNum(30);
    std::cout << "Delete 30:  "<< t->get_debug_string() << "\n";
    t->insert(9);
    std::cout <<"Insert 9:  " << t->get_debug_string() << "\n";
    t->deleteNum(8);
    std::cout << "Delete 8:  "<< t->get_debug_string() << "\n";
    t->insert(21);
    std::cout <<"Insert 21:  " << t->get_debug_string() << "\n";
    t->insert(23);
    std::cout <<"Insert 23:  " << t->get_debug_string() << "\n";
    t->insert(14);
    std::cout <<"Insert 14:  " << t->get_debug_string() << "\n";
    t->insert(17);
    std::cout <<"Insert 17:  " << t->get_debug_string() << "\n";
    t->deleteNum(5);
    std::cout << "Delete 5:  "<< t->get_debug_string() << "\n";
    t->deleteNum(20);
    std::cout << "Delete 20:  "<< t->get_debug_string() << "\n";
    


    return 0;
}