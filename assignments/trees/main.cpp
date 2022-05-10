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


    std::cout<<"\n----------------------------------------------";
    std::cout<<"\nDelete Leaf \n\n";
    std::cout << "Tree:  "<< t->get_debug_string() << "\n";
    t->deleteNum(22);
    std::cout << "Delete 22:  "<< t->get_debug_string() << "\n\n";

    t->insert(22);
    std::cout << "Insert 22:  "<< t->get_debug_string() << "\n";
    t->deleteNum(30);
    std::cout << "Delete 30:  "<< t->get_debug_string() << "\n\n";

    std::cout<<"\n----------------------------------------------";
    std::cout<<"\nDelete Node with one child \n\n";
    t->insert(9);
    std::cout <<"Insert 9:  " << t->get_debug_string() << "\n";
    t->deleteNum(8);
    std::cout << "Delete 8:  "<< t->get_debug_string() << "\n\n";

    t->insert(21);
    std::cout <<"Insert 21:  " << t->get_debug_string() << "\n";
    t->insert(23);
    std::cout <<"Insert 23:  " << t->get_debug_string() << "\n";
    t->insert(14);
    std::cout <<"Insert 14:  " << t->get_debug_string() << "\n";
    t->deleteNum(15);
    std::cout << "Delete 15:  "<< t->get_debug_string() << "\n\n";


    std::cout<<"\n----------------------------------------------";
    std::cout<<"\nDelete Node with Two children \n\n";
    t->insert(15);
    std::cout <<"Insert 15:  " << t->get_debug_string() << "\n";
    t->insert(17);
    std::cout <<"Insert 17:  " << t->get_debug_string() << "\n";
    t->deleteNum(5);
    std::cout << "Delete 5:  "<< t->get_debug_string() << "\n\n";
    t->deleteNum(10);
    std::cout << "Delete 10:  "<< t->get_debug_string() << "\n";
    t->deleteNum(23);
    std::cout << "Delete 23:  "<< t->get_debug_string() << "\n";
    int height = t->getHeight();
    std::cout<<"Height of the tree: "<<height<<"\n";


    std::cout<<"\n----------------------------------------------";
    std::cout<<"\nCount Leaves \n\n";
    BSTree *t2 = new BSTree();
    std::cout<<"Three: "<<t2->get_debug_string()<<"\n";
    int count = t2->countLeaves();
    std::cout<<"Leaves on the tree: "<<count<<"\n";
    t2->setup();
    std::cout<<"Three: "<<t2->get_debug_string()<<"\n";
    count = t2->countLeaves();
    std::cout<<"Leaves on the tree: "<<count<<"\n";
    height = t2->getHeight();
    std::cout<<"Height of the tree: "<<height<<"\n";
    int sum = t2->sumAtLevel(1);
    std::cout<<"Sum at level 1: "<<sum<<"\n\n";
    t2->insert(7);
    std::cout<<"Insert 7: "<<t2->get_debug_string()<<"\n";
    sum = t2->sumAtLevel(2);
    std::cout<<"Sum at level 4: "<<sum<<"\n";
    sum = t2->sumAtLevel(4);
    std::cout<<"Sum at level 4: "<<sum<<"\n";
    height = t2->getHeight();
    std::cout<<"Height of the tree: "<<height<<"\n";



    return 0;
}