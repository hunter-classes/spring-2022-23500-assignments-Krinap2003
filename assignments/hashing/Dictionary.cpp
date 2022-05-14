#include <iostream>
#include<algorithm>

#include "Dictionary.h"


Dictionary::Dictionary(){
    for(int i = 0; i < 10; i++){
        arr[i] = new OList();
    }
}

Dictionary::~Dictionary(){
    for(int i = 0; i < 10; i++){
        arr[i]->~OList();
    }
}


//Got from the online has function dictionary
int Dictionary::hashKey(std::string s){
    int sum = 0;
    for(int i = 0; i < s.length(); i++) {
        sum += (int) s[i];
    }
    return sum % 10;
}

void Dictionary::insert(Person *p){
    int key = hashKey(p->get_name());
    arr[key]->insert(p);

}

Person* Dictionary::retrivePerson(Person* p){
    int index = hashKey(p->get_name());
    // if(arr[index] == nullptr){
    
    //     return nullptr;
    // }
    return  arr[index]->get(p);
}


std::string Dictionary::getAllKey(){
     std::string result = "";
    for(int i = 0; i < 10; i++){
        result += arr[i]->toString()+"\n";
    }
    return result;
}


// std::string Dictionary::toString(){
//       std::string result = "";
//    for(int i = 0; i<10; i++){
//           if(arr[i]){
//               result+=arr[i]->toStringNew()+"\n";
//           }
//    }
//    return result;
// }