/*****************************************
 ** File:    Carnivore.cpp
 ** Project: CMSC 202 Project 4, Fall 2018
 ** Author:  Ryan Ellis
 ** Date:    11/7/18
 ** Section: 08
 ** E-mail:  r59@umbc.edu
 **
 ** This file contains the cpp file for the Carnivore.h
 ** file
 **
 ***********************************************/

#include "Carnivore.h"

// Default Constructor
// Preconditions: None
// Postconditions: None
Carnivore::Carnivore(){}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Carnivore::Carnivore(Gender gender,int health,int age):Animal(gender, health,age){}

// eat() - Tests if animal successfully ate.
// - if the hunt was a success or they are age 1 then true
// otherwise they have a 50% chance
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether animal ate or did not
//                 in the course of the year
bool Carnivore::eat(){
  if (getAge() == 1 or hunt()){
    return true;
  }
  else{
    if( randomPercentBased(50)){
      return true;
    }
    else{
      return false;
    }
  }
}
