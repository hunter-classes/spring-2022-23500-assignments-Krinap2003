#include <iostream>
#include "Dictionary.h"

int main(){

    Dictionary *d1 = new Dictionary();
    Person *p1 = new Person("Patel","Krina",1);
    Person *p2 = new Person("smith","Sam",2);
    Person *p3 = new Person("Ramirez","Dev",3);
    Person *p4 = new Person("Harris","Kevin",4);
    Person *p5 = new Person("Perez","Emily",5);
    Person *p6 = new Person("Collins","Sarah",6);
    Person *p7 = new Person("Ramirez","Lola",7);
    Person *p8 = new Person("Patel","Aditi",8);
    std::cout<<"\n-------------- No Insertion ----------\n";
    std::cout<<d1->getAllKey()<<"\n";
    d1->insert(p1);
    d1->insert(p2);
    d1->insert(p3);
    d1->insert(p4);
    d1->insert(p5);
    d1->insert(p6);
    d1->insert(p7);
    d1->insert(p8);
    std::cout<<"\n-------------- After Insertion ----------\n";
    std::cout<<d1->getAllKey()<<"\n";

    std::cout<<"\n-------------- Retrive Person ----------\n";
    Person *searchP = d1->retrivePerson(p2);
    std::cout<<"Person at index "<<d1->hashKey(searchP->get_name())<<": "<<searchP->get_name()<<"\n";
    searchP = d1->retrivePerson(p5);
    std::cout<<"Person at index "<<d1->hashKey(searchP->get_name())<<": "<<searchP->get_name()<<"\n";
    searchP = d1->retrivePerson(p8);
    std::cout<<"Person at index "<<d1->hashKey(searchP->get_name())<<": "<<searchP->get_name()<<"\n";

    std::cout<<"\n-------------- Destructor ----------\n";
    d1->~Dictionary();

    return 0;
}