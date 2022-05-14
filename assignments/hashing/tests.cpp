#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Dictionary.h"
#include "Person.h"
#include <iostream>

Dictionary *d1 = new Dictionary();
Person *p1 = new Person("Patel","Krina",1);
Person *p2 = new Person("smith","Sam",2);
Person *p3 = new Person("Ramirez","Dev",3);
Person *p4 = new Person("Harris","Kevin",4);
Person *p5 = new Person("Perez","Emily",5);
Person *p6 = new Person("Collins","Sarah",6);
Person *p7 = new Person("Ramirez","Lola",7);
Person *p8 = new Person("Patel","Aditi",8);

Person *p9 = new Person("Unknow","Person",9);

TEST_CASE("Insert and Hash Key")
{
    d1->insert(p1);
    CHECK(d1->getAllKey() == "nullptr\nnullptr\nnullptr\nnullptr\nnullptr\nnullptr\nnullptr\nnullptr\nnullptr\nKrina, Patel->nullptr\n");
    d1->insert(p2);
    CHECK(d1->getAllKey() == "nullptr\nnullptr\nnullptr\nnullptr\nSam, smith->nullptr\nnullptr\nnullptr\nnullptr\nnullptr\nKrina, Patel->nullptr\n");
    d1->insert(p3);
    CHECK(d1->getAllKey() == "nullptr\nnullptr\nnullptr\nDev, Ramirez->nullptr\nSam, smith->nullptr\nnullptr\nnullptr\nnullptr\nnullptr\nKrina, Patel->nullptr\n");
    d1->insert(p4);
    CHECK(d1->getAllKey() == "nullptr\nnullptr\nKevin, Harris->nullptr\nDev, Ramirez->nullptr\nSam, smith->nullptr\nnullptr\nnullptr\nnullptr\nnullptr\nKrina, Patel->nullptr\n");
    d1->insert(p5);
    CHECK(d1->getAllKey() == "nullptr\nnullptr\nKevin, Harris->nullptr\nDev, Ramirez->nullptr\nSam, smith->nullptr\nnullptr\nEmily, Perez->nullptr\nnullptr\nnullptr\nKrina, Patel->nullptr\n");
    d1->insert(p6);
    CHECK(d1->getAllKey() == "nullptr\nnullptr\nKevin, Harris->nullptr\nDev, Ramirez->nullptr\nSam, smith->nullptr\nSarah, Collins->nullptr\nEmily, Perez->nullptr\nnullptr\nnullptr\nKrina, Patel->nullptr\n");
    d1->insert(p7);
    CHECK(d1->getAllKey() == "nullptr\nnullptr\nKevin, Harris->nullptr\nDev, Ramirez->nullptr\nSam, smith->nullptr\nSarah, Collins->nullptr\nEmily, Perez->nullptr\nnullptr\nLola, Ramirez->nullptr\nKrina, Patel->nullptr\n");
    d1->insert(p8);
    CHECK(d1->hashKey("Krina, Patel") == 9);
    CHECK(d1->hashKey("Harris, Kevin") == 2);
    CHECK(d1->hashKey("Aditi, Patel") == 9);
    CHECK(d1->getAllKey() == "nullptr\nnullptr\nKevin, Harris->nullptr\nDev, Ramirez->nullptr\nSam, smith->nullptr\nSarah, Collins->nullptr\nEmily, Perez->nullptr\nnullptr\nLola, Ramirez->nullptr\nAditi, Patel->Krina, Patel->nullptr\n");

}

TEST_CASE("Retrive Person")
{
    Person *searchP = d1->retrivePerson(p2);
    CHECK(searchP->get_name() == "Sam, smith");
    searchP = d1->retrivePerson(p3);
    CHECK(searchP->get_name() == "Dev, Ramirez");
    searchP = d1->retrivePerson(p8);
    CHECK(searchP->get_name() == "Aditi, Patel");
    searchP = d1->retrivePerson(p4);
    CHECK(searchP->get_name() == "Kevin, Harris");
    //  searchP = d1->retrivePerson(p9);
    // CHECK(d1->retrivePerson(p9) == nullptr);
}


