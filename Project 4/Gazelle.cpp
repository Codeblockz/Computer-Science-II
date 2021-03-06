/*****************************************
 ** File:    Gazelle.cpp
 ** Project: CMSC 202 Project 4, Fall 2018
 ** Author:  Ryan Ellis
 ** Date:    11/11/18
 ** Section: 08
 ** E-mail:  r59@umbc.edu
 **
 ** This file contains the cpp file for the Gazelle.h
 ** file
 **
 ***********************************************/ 

#include "Gazelle.h"





// Default Constructor
// Preconditions: None
// Postconditions: None
Gazelle::Gazelle(){}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Gazelle::Gazelle(Gender gender,int health,int age):Herbivore(gender, health, age){}

// breed() - if an animal successfully produces offspring it returns a pointer to it
// - If female and age > 1 there is a 30% chance
// - otherwise false
// Preconditions: all variables are set valid
// Postconditions: returns an pointer to a new animal or NULL
Animal* Gazelle::breed(){
  if(getGender()==0 && getAge()>1 && randomPercentBased(35)){
    Animal *kid = new Gazelle(Gender(rand()%2),MAX_HEALTH, 1);
    return kid;
  }
  else{
    return NULL;
  }
}

  
// toString() - a string representation of the animal
// Preconditions: all variables are set valid
// Postconditions: returns a string of the name of the animal
string Gazelle::toString(){
  string Name = "Gazelle";
  return  Name;
}

// graze() - Tests if animal successfully graze
// - if the age is not 5 than chance is health*15%
// - otherwise it is false
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether animal successfully graze
bool Gazelle::graze(){
  if(getAge()<5){
    bool chance = randomPercentBased((getHealth()*15));
    return chance;
  }
  else{
    return false;
  }
}
