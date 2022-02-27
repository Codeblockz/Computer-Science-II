/*****************************************
 ** File:    Herbivore.cpp
 ** Project: CMSC 202 Project 4, Fall 2018
 ** Author:  Ryan Ellis
 ** Date:    11/7/18
 ** Section: 08
 ** E-mail:  r59@umbc.edu
 **
 ** This file contains the cpp file for the Herbivore.h
 ** file
 **
 ***********************************************/
#include "Herbivore.h"


// Default Constructor
// Preconditions: None
// Postconditions: None
Herbivore::Herbivore(){}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Herbivore::Herbivore(Gender gender,int health,int age):Animal(gender, health, age){}

// eat() - Tests if animal successfully ate.
// - if the graze was a success or they are age 1 then true
// otherwise they don't eat
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether animal ate or did not
//                 in the course of the year
bool Herbivore::eat(){
if(getAge()==1){
  return true;
 }
 else{
   if(graze()){
     return true;
   }
   else{
     return false;
   }
 }
}
