/*****************************************
 ** File:    Elephant.cpp
 ** Project: CMSC 202 Project 4, Fall 2018
 ** Author:  Ryan Ellis
 ** Date:    11/11/18
 ** Section: 08
 ** E-mail:  r59@umbc.edu
 **
 ** This file contains the cpp file for the Elephant.h
 ** file
 **
 ***********************************************/
#include "Elephant.h"

// Default Constructor
// Preconditions: None
// Postconditions: None
Elephant::Elephant(){}
// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Elephant::Elephant(Gender gender,int health,int age):Herbivore(gender, health, age){}


// breed() - if an animal successfully produces offspring it returns a poi\
nter to it
// - If female and age > 2 there is a 40% chance
// - otherwise false
// Preconditions: all variables are set valid
// Postconditions: returns an pointer to a new animal or NULL
Animal* Elephant::breed(){
  if(getGender()==0 && getAge() >2 && randomPercentBased(45)){
    Animal *kid = new Elephant(Gender(rand()%2),MAX_HEALTH, 1);
    return kid;
  }
  else{
    return NULL;
  }
}
// toString() - a string representation of the animal
// Preconditions: all variables are set valid
// Postconditions: returns a string of the name of the animal
string Elephant::toString(){
  string Name = "Elephant";
  return Name;
}

// graze() - Tests if animal successfully graze
// - 95% chance of success
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether animal successfully graze
bool Elephant:: graze(){
  if(randomPercentBased(95)){
    return true;
  }
  else{
    return false;
  }
}
 
