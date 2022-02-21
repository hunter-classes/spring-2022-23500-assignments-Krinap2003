#include <iostream>
#include "Node.h"
#include "List.h"

int main(int argc, char *argv[])
{
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

    List *l1 = new List();
    std::cout<<l1->toString()<<"\n";
    
    l1->insert("a");
    l1->insert("b");
    l1->insert("c");

    std::cout<<l1->toString()<<"\n";
    return 0;
}