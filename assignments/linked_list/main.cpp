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
    l1->insert("e");
    std::cout<<l1->toString()<<"\n\n";

    std::cout<<"\nInsert new Items in the List at a Index 1\n"; 
    l1->insert(1, "d");
    std::cout<<l1->toString()<<"\n\n";
    std::cout<<"\nInsert new Items in the List at a Index 0\n"; 
    l1->insert(0, "f");
    std::cout<<l1->toString()<<"\n\n";


    std::cout<<"\nRemove Item at index 1\n"; 
    l1->remove(1);
    std::cout<<l1->toString()<<"\n\n";

    std::cout<<"\nRemove Item at index 0\n"; 
    l1->remove(0);
    std::cout<<l1->toString()<<"\n\n";

     std::cout<<"\nGet lenght of the Linked List\n"; 
     std::cout<<"The Lenngth: "<<l1->length()<<"\n";


    std::cout<<"\nLocate Item at index 0\n";
    std::string result;
    int i = 0;
    result = l1->get(i);
    std::cout << "l["<<i<<"] = " << result << "\n";
    i = 1;
    result = l1->get(i);
    std::cout << "l["<<i<<"] = " << result << "\n";
    i = 4;
    result = l1->get(i);
    std::cout << "l["<<i<<"] = " << result << "\n\n";

    l1->~List();
    std::cout<<l1->toString()<<"\n\n";
    
    return 0;
}