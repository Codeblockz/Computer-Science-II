/*****************************************
 ** File:    Animal.cpp
 ** Project: CMSC 202 Project 4, Fall 2018
 ** Author:  Ryan Ellis
 ** Date:    11/7/18
 ** Section: 08
 ** E-mail:  r59@umbc.edu 
 **
 ** This file contains the cpp file for the Animal.h
 ** file 
 **
 ***********************************************/
#include "Animal.h"
#include <iomanip>
// Default Constructor
// Preconditions: None
// Postconditions: A simple object is created (like an animal was born)
Animal::Animal(){}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Animal::Animal (Gender gender,int health,int age){
  m_health = health;
  m_age = age;      
  m_gender = gender;
}


// getGender() - returns the gender of animal
// Preconditions: m_gender is set
// Postconditions: returns an enum Gender referring to which gender
Gender Animal::getGender(){
  return m_gender;

}

// getHealth() - returns the health of animal
// Preconditions: m_health is set
// Postconditions: returns an int referring to health 1 - MAX_health
int Animal::getHealth(){
  return m_health;
}

// getAge() - returns the age of animal
// Preconditions: m_age is set
// Postconditions: returns an int referring to age 1- MAX_AGE
int Animal::getAge(){
  return m_age;
}

// liveAYear() - changes parameters based on 1 year of life
// - 50% chance that health diminishes
// - if Eat() is false health diminishes
// - 50% chance of aging
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether animal lives
bool Animal::liveAYear(){
  // Health
  bool lived = false;
  if(randomPercentBased(50)){
    lived = diminishHealth();
  }

  // Eat
  if(!eat() && lived){
    lived = diminishHealth();
  }

  // Age
  if(randomPercentBased(50)){
    m_age++;
  }

  // Death Flag
  if (m_health <= 0 ){
    m_health = 0;

    // Checks Age
    if(m_age >MAX_AGE){
      m_age = MAX_AGE;
    }
    return false;
  }
  
  // If not dead from health, check age
  else if(m_age >5){
    m_age = MAX_AGE;
    return false;
  }
  else{
    return true;
  }
}

// diminishHealth() - take one from health
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether animal lives
bool Animal::diminishHealth(){
  m_health--;

  // If false animal is dead
  if(m_health <= 0){
    return false;
  }
  else{
    return true;
  }
}

// Overloaded << - Prints the credentials of an animal
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of animal
ostream& operator<<(ostream& output, Animal& animal){

  // Intialize variables
  Gender Gtemp = animal.getGender();
  int Htemp = animal.getHealth();
  int Atemp = animal.getAge();

  string gender;
  string age;
  string health;

  // Gender
  switch(Gtemp){
  case FEMALE:
    gender = "Female";
    break;
      
  case MALE:
    gender = "Male";
    break;
  }
  // Health
  switch(Htemp){
  case 0:
    health = "Dead";
    break;
    
  case 1:
    health = "Bad";
    break;

  case 2:
    health = "Diminishing";
    break;
    
  case 3:
    health = "Poor";
    break;

  case 4:
    health = "Ok";
    break;

  case 5:
    health = "Average";
    break;

  case 6:
    health = "Good";
    break;

  case 7:
    health = "Very Good";
    break;
    
  case 8:
    health ="Great";
    break;
    
  case 9 :
    health = "Excellent";
    break;
    
  case 10 :
    health = "Perfect";
    break;
  }


  // Age
  switch(Atemp){
  case 1:
    age = "Very Young";
    break;

  case 2:
    age = "Young";
    break;

  case 3:
    age = "Prime";
    break;

  case 4:
    age = "Middle";
    break;

  case 5:
    age = "Old";
    break;
  }
  
  output<<left;
  output<< setw(12) << animal.toString();
  output<<setw(12)<<gender;
  output<<setw(12)<<age;
  output<<setw(12)<<health<<endl;

  return output;
}




// randomPercentBased (Helper function)
// Precondition: Given int to "pass"
// Description: This function is used to see if a certain random event occurs
//              A random number 1-100 is compared to the int passed
//              If the random number is less than the passed value, return true
//              Else return false (30 = 30%, 70 = 70%)
// Postcondition: Returns boolean
bool Animal::randomPercentBased(int num){
  //  srand(time(NULL));
  int compare = rand()%100 +1;
  if(compare < num){
    return true;
  }
  else{
    return false;
  }



}
