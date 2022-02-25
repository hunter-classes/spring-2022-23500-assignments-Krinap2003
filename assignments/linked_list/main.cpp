#include <iostream>
#include "Node.h"
#include "List.h"

int main(int argc, char *argv[])
{
    //Tests
    List *l1 = new List();
    std::cout<<"\nOriginal new List \n"; 
    std::cout<<l1->toString()<<"\n\n";
    
    std::cout<<"\nInsert new Items in the List \n"; 
    l1->insert("a");
    l1->insert("b");
    l1->insert("c");
    l1->insert("d");
    std::cout<<l1->toString()<<"\n\n";

    std::cout<<"\nRemove Item at index 1\n"; 
    l1->remove(1);
    std::cout<<l1->toString()<<"\n\n";

    std::cout<<"\nRemove Item at index 0\n"; 
    l1->remove(0);
    std::cout<<l1->toString()<<"\n\n";


    std::cout<<"\nLocate Item at index 0\n";
    std::string result;
    int i = 0;
    result = l1->get(i);
    std::cout << "l["<<i<<"] = " << result << "\n";
    i = 1;
    result = l1->get(i);
    std::cout << "l["<<i<<"] = " << result << "\n";
    i = 2;
    result = l1->get(i);
    std::cout << "l["<<i<<"] = " << result << "\n\n";

    //l1->~List();
    //std::cout<<l1->toString()<<"\n\n";




    // Node *p1 = new Node();
    // p1->setData("hello");

    // Node *p2 = new Node("world");
    // p1->setNext(p2);
    
    // std::cout<< p1-> getData() << "\n";
    // std::cout<< p2-> getData() << "\n";
    // std::cout<< p1-> getNext() -> getData() << "\n";

    // p2 = new Node("!");
    // p1-> getNext()->setNext(p2);

    // std::cout<< p1-> getData() << "\n";
    // std::cout<< p1-> getNext() -> getData() << "\n";
    // std::cout<< p1-> getNext()-> getNext() -> getData() << "\n";

    // Node *walker = p1;
    // std::cout<< walker->getData() <<"\n";

    // walker = walker->getNext();//walker = p1->getNext();
    // std::cout<< walker->getData() <<"\n";

    // walker = walker->getNext();//walker = p1->getNext();
    // std::cout<< walker->getData() <<"\n";

    // walker = p1;
    // while(walker != nullptr)
    // {
    //     std::cout<<walker->getData()<<"\n";
    //     walker = walker->getNext();
    // }

    // // At this point walker points to (refers to) nullptr
    // // and if we try to dereference it, we get a segfault.
    // //std::cout<<walker->getData()<<"\n";

    //List *l = new List();
    // std::cout << l->toString() << "\n";
    // l->insert("Hello");
    // std::cout << l->toString() << "\n";
    // l->insert("world");
    // std::cout << l->toString() << "\n";
    // l->insert("!");
    // std::cout << l->toString() << "\n";

    // std::string result;
    // int i = 2;
    // result = l->get(i);
    // std::cout << "l["<<i<<"] = " << result << "\n";
    
    return 0;
}