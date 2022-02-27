/*
Author: Ryan Ellis
Date: 10/6/2018
Description: this is the Hero class file for project 2

 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include "Hero.h"

using namespace std;

// Name: Hero() - Default Constructor (unused)
// Desc: Used to build a new hero
// Preconditions - Requires default values
// Postconditions - Creates a new hero
Hero::Hero(){
  srand(time(NULL));
}

// Name: Hero(name, isPlayer, isSeen, level) - Overloaded constructor
// Desc - Used to build a new hero (player or enemy)
// Preconditions - Requires name and isPlayer
// Postconditions - Creates a new hero
Hero::Hero(string name, bool isPlayer){
  SetName(name);
  srand(time(NULL));
  m_isPlayer = isPlayer;
}

// Name: GetName()
// Desc - Getter for Hero name
// Preconditions - Hero exists
// Postconditions - Returns the name of the hero
string Hero::GetName(){
  return m_name;
}

// Name: SetName(string)
// Desc - Allows the user to change the name of the hero
// Preconditions - Hero exists
// Postconditions - Sets name of hero
void Hero::SetName(string name){
  m_name = name;
}

// Name: GetIsPlayer()
// Desc - Getter for if hero is a player or a non-player character (computer)
// Preconditions - Hero Exists
// Postconditions - Returns true (is user) or false (is computer)
bool Hero::GetIsPlayer(){
  return m_isPlayer;
}


// Name: DisplayDances()
// Desc - Displays a numbered list of all dance moves known by the player
// Preconditions - Heros exist
// Postconditions - None
void Hero::DisplayDances(){
  int count = 0;
  string style;
  for(vector<Dance>::iterator it = m_dances.begin();it != m_dances.end(); it++){
    //counts which dance move
    count++;
    
    //Converts style to string name
    switch((*it).m_style){
    case 0:
      style = FREESTYLE;
      break;
    case 1:
      style = BREAKIN;
      break;
    case 2:
      style = SILLY ;
      break;
    }
    //prints the dance formated
    cout<<count<<"."<<setw(18)<<(*it).m_name<<setw(11)<<style<<setw(11)<<(*it).m_level<<setw(10)<<(*it).m_difficulty<<endl;

      
  }
  
}
// Name: GetDanceCount()
// Desc - Returns number of dances known by hero
// Preconditions - Heros exist
// Postconditions - None
int Hero::GetDanceCount(){
  return int(m_dances.size());
}

// Name: CheckDanceLevel()
// Desc - checks to see if dance is level 10
// Preconditions - m_dances exist (int is the index)
// Postconditions - returns true dance is not max
bool Hero::CheckDanceLevel(int dance){
  if( m_dances[dance].m_level >= 10){
    cout<<"That dance is maxed out!"<<endl;
    return false;
  }
  else{
    return true;
  }
}

// Name: DanceBattle(Hero&)
// Desc - Allows the user to dance attack an enemy hero
// Preconditions - Heros exist
// Postconditions - Returns if hero hero wins fight (true wins, false loses)
bool Hero::DanceBattle(Hero &enemy){
cout<<m_name<<" attacks "<<enemy.GetName()<<"!"<<endl;
 int userInput;
 int rdNum = rand()%5;
 do{
   cout<<setw(15)<<"Dance"<<setw(16)<<"Style"<<setw(13)<<"Level"<<setw(13)<< \
     "Difficulty"<<endl;
   DisplayDances();
   cin>>userInput;
 }
 while(userInput<GetDanceCount() or userInput> GetDanceCount());
 double HeroQ = m_dances[userInput-1].m_level *  (m_dances[userInput-1].m_difficulty + 1);
 double enemyQ =enemy.m_dances[rdNum].m_level *  (enemy.m_dances[rdNum].m_difficulty + 1);
 
 if(HeroQ > enemyQ){
   cout<<WON<<endl;
   return true;
 }
 else if(HeroQ < enemyQ){
   cout<<LOSE<<endl;
   return false;
 }
 else if (HeroQ == enemyQ){
   cout<<TIE<<endl;
   return true;
 }

 
}

// Name: HeroicDance(Hero&)
// Desc - Allows the user to attack an enemy hero using a special dance
//        Returns the string of the specific dance
// Preconditions - During normal attack, 5% chance a special dance attack called
// Postconditions -  Automatically wins fight
string Hero::HeroicDance(){
  
  string SuperDance = m_name+SUPPER;
  return SuperDance;
    
}


// Name: IncreaseDance(int)
// Desc - Increases level of a dance up to 10 (value passed is index of dance to increase)
// Preconditions - Hero has dances
// Postconditions - None
void Hero::IncreaseDance(int dance){
  if(m_dances[dance].m_level<MAX_LEVEL){
    m_dances[dance].m_level ++;
  }
}

// Name: CheckDance(string)
// Desc - Checks the player to see if they know a specifice dance by name
// Preconditions - Hero has dances
// Postconditions - Returns true if player already has dance, else false
bool Hero::CheckDance(string name){
  for (vector<Dance>::iterator it = m_dances.begin();it != m_dances.end(); it++){
    if( name == (*it).m_name){
      return true;
    }
  }
  return false;
}


// Name: AddDance(Dance)
// Desc - Adds a new dance to the player's dance list
// Preconditions - Hero does not already know this dance
// Postconditions - Dance is added (level 1)
void Hero::AddDance(Dance dance){
  int count = 0;
  int temp = 0;
  //Checks if dance is known by player
  for (vector<Dance>::iterator it = m_dances.begin();it != m_dances.end(); it++){
    if(dance.m_name == (*it).m_name){
      count ++;
    }
  }
  // Adds dance
  if(count==0 && int(m_dances.size())<NUM_DANCES){
    m_dances.push_back(dance);
    temp= int(m_dances.size())-1;
    m_dances[temp].m_level = MIN_LEVEL;
  }
}
