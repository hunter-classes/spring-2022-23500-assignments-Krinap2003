#pragma once
#include "OList.h"

class Dictionary{
    private:
        OList *arr[10];

    public: 
        Dictionary();
        ~Dictionary();
        void insert(Person p);
        Person retrivePerson(int id);
        std::string getAllPeopll();

};