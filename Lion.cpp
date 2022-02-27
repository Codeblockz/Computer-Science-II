/*****************************************
 ** File:    Lion.cpp
 ** Project: CMSC 202 Project 4, Fall 2018
 ** Author:  Ryan Ellis
 ** Date:    11/11/18
 ** Section: 08
 ** E-mail:  r59@umbc.edu
 **
 ** This file contains the cpp file for the Lion.h
 ** file
 **
 ***********************************************/
#include "Lion.h"
// Default Constructor
// Preconditions: None
// Postconditions: None
Lion::Lion(){}
// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Lion::Lion(Gender gender,int health,int age):Carnivore(gender, health, age){}

// breed() - if an animal successfully produces offspring it returns a poi\
nter to it
// - If female and age 3 or 4 there is a 50% chance
// - otherwise false
// Preconditions: all variables are set valid
// Postconditions: returns an pointer to a new animal or NULL
Animal* Lion::breed(){
  if(getGender()== FEMALE){
    if(getAge()>=3 && getAge()<= 4 && randomPercentBased(50)){
      Animal* kid = new Lion(Gender(rand()%2),MAX_HEALTH, 1);
      return kid;   
    }
    else{
      return NULL;
    }
  }
  else{
    return NULL;
  }
}
// toString() - a string representation of the animal
// Preconditions: all variables are set valid
// Postconditions: returns a string of the name of the animal
string Lion::toString(){
    string Name = "Lion";
  return  Name;
}


// hunt() - Tests if animal successfully hunted
// - if the age > 1 than chance is health*10%
// - otherwise false
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether animal successfully hunted
bool Lion::hunt(){
  if(getAge()>1 &&randomPercentBased((getHealth()*10))){
    return true;
  }
  else{
    return false;
  }
}
