#include <iostream>
#include "Dictionary.h"


Dictionary::Dictionary(){
    for(int i = 0; i < 10; i++){
        arr[i] = new OList();
    }
}

Dictionary::~Dictionary(){

}
void Dictionary::insert(Person *p){
    std::string name = p->get_name();
    int hashKey = name.length()%10;
    arr[hashKey]->insert(p);

}

Person* Dictionary::retrivePerson(int id){
    return nullptr;
}

std::string Dictionary::getAllPeople(){
    std::string result = "";
    for(int i = 0; i < 10; i++){
        result += arr[i]->toString()+"\n";
    }
    return result;
}