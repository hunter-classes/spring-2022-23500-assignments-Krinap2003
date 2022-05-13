#include <iostream>
#include "Person.h"


Person::Person(){
  this->first = "";
  this->last = "";
  this->idnum = 0;
}

Person::Person(std::string first, std::string last, int num){
  this->first = first;
  this->last = last;
  this->idnum = num;
}

std::string Person::get_name(){
  return last+", "+first;
}

int Person::get_id(){
  return idnum;
  
}
