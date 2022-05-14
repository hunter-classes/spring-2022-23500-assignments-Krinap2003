#pragma once
#include "OList.h"
#define Person_Not_Found 1

class Dictionary{
    private:
        OList *arr[10];

    public: 
        Dictionary();
        ~Dictionary();
        int hashKey(std::string s);
        void insert(Person *p);
        Person* retrivePerson(Person *p);
        std::string getAllKey();
};