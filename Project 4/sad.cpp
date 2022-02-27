/*****************************************
 ** File:    Safari.cpp
 ** Project: CMSC 202 Project 4, Fall 2018
 ** Author:  Ryan Ellis
 ** Date:    11/11/18
 ** Section: 08
 ** E-mail:  r59@umbc.edu
 **
 ** This file contains the cpp file for the Safari.h
 ** file
 **
 ***********************************************/
#include "Safari.h"
#include <iomanip>
const string MAIN_MENU = "What would you like to do?\n\n1. Display Animals\n2. Simulate\n3. Quit";


// Default Constructor
// Preconditions: None
// Postconditions: None
Safari::Safari(){}
// Destructor
// Preconditions: m_animals is populated
// Postconditions: Deallocates animal object in memory
Safari::~Safari(){
  for (unsigned int i=0; i<m_animals.size();i++){
    delete m_animals.at(i);
  }
    //for(vector<Animal*>::iterator it = m_animals.begin();it != m_animals.end(); it++){
    // delete it;
    //}
 
}
// Name: loadAnimals
// Desc - Loads each animals into m_animals from file
// Preconditions - Requires file with valid dance data
// Postconditions - m_animals is populated with animal pointers
void Safari::loadAnimals(char* fileName){
  ifstream FileIn(fileName);
  int type;
  Gender gender;
  int tempGender;
  int health;
  int age;
  Animal* kid;
  if(FileIn.is_open()){
    while(FileIn>>type){
      FileIn>>tempGender;
      FileIn>>health;
      FileIn>>age;
      switch(tempGender){
      case 0:
	gender = FEMALE;
	break;
      case 1 :
	gender = MALE;
	break;
      }
      switch(type){
	// Lion
      case 0:
	kid = new Lion(gender, health, age);
	break;
	
	// Gazelle
      case 1:
	kid = new Gazelle(gender, health, age);
	break;
	
	// Elephant
      case 2:
	kid = new Elephant(gender, health, age);
	break;
      }
      m_animals.push_back(kid);
      
    }
    
  }
}

// Name: simulateYear()
// Desc - simulates a year in the safari for all the animals
// Preconditions - Requires a populated m_animals
// Postconditions - simulates a year in time each animal:
// 1. has a chance to breed. If they are successful their offspring
//    is added to m_animals
// 2. lives a year
void Safari::simulateYear(){
  Animal* child;
  vector <Animal*> spare;
  vector <Animal*> dead;
  bool live;
  int count = 0;
  //  vector <int> dead;
  for(vector<Animal*>::iterator it = m_animals.begin();it != m_animals.end(); it++){
    if(*it != NULL){
      //sees if animal lived 
      live = (*it)->liveAYear();
      child = (*it)->breed(); // test
      if(child != NULL){
	
	spare.push_back(child);
	cout<<setw(12)<<"Born:"<<*child<<endl;
	spare.push_back(*it);
      }//test
      
      
      
      if(live){
	cout<<left;
	cout<<setw(12)<<"Survived:"<<(*(*it))<<endl;
	spare.push_back(*it);
	
      }
      else{
	cout<<setw(12)<<"Died:"<<(*(*it))<<endl;
	// adds dead animals to dead vector
	dead.push_back(*it);
	//	m_animals.erase(m_animals.begin()+count);
	
      }
    }
    count++;
  }
  
  
  m_animals = spare;
  for(vector<Animal*>::iterator it = dead.begin();it != dead.end(); it++){
    delete *it;
    //m_animals.erase(m_animals.begin()+count);

  }
}





// Name: MainMenu()
// Desc - Displays and manages menu
// Preconditions - m_animal has been populated
// Postconditions - exits if user entered 3
void Safari::mainMenu(){
  int userInput;
  do{
    cout<<MAIN_MENU<<endl;
    cin>>userInput;
    switch(userInput){

    case 1:
      displayAnimals();
      break;

    case 2:
      // simulate();
      simulateYear();
      break;

    case 3:
      break;
    }
  }
  while(userInput!=3);


}



// Name: simulate()
// Desc - gets number of years to simulate and simulates for that number
// Preconditions - m_animals is populated
// Postconditions - Has simulated that number years and m_animals reflects changes
void Safari::simulate(){}

// Name: displayAnimals()
// Desc - Displays all animals in m_animals ina formated fashion
// Preconditions - m_animals is populated
// Postconditions - N/A
void Safari::displayAnimals(){}
