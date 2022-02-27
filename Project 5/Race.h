#ifndef RACE_H
#define RACE_H

#include "Racer.h"
#include "Racecar.h"
#include "Truck.h"
#include "Formula.h"
#include "Lqueue.h"

#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

//Constant array for Racer names (regardless of type of racer)
const string RACERS [] = {"Mcdowell","Abdel","Wheeler","Romero","Barton","Wood","Azam","Munoz","Baird","Moon","Cantrell","Kent","Hunter","Reilly","Rivas","Copeland","Sharp","York","Henson","Sweet","Horne","Cook","Vincent","Pearson","Sabir","Palmer","Sanders","Lynn","Merrill","King","Holt","Preston","Zhang","Dominguez","Workman","Roach","Franklin","Walker","Maynard","Burris","Scott","Li","Barrett","Carson","Hutchinson","Sargent","Woodward","Leblanc","Lopez","Chen","Soto","Contreras","Sellers","Espinoza","Pierce","Masood","Giles","Garrison","Garner","Garza","Spencer","Hill","Spence","Maldonado","Hassan","Garrett","Harris","Petersen","Rogers","Hester","Molla","Murphy","Conner","Yassin","Sloan","Long","Terrell","Matthews","Whitley","Kim","Branch","Crane","Browning","Gentry","English","Mayo","Barnes","Molina","Dodson","Mccray","Hines","Malone","Whitehead","Mccarty","Marsh","Fletcher","Fuller","Aguirre","Pacheco","Ozer"};
			  
//Constant array for Racer numbers (regardless of type)
const int RACE_NUMS [] = {73,62,86,78,75,8,65,17,58,17,71,21,64,33,62,95,11,98,34,8,83,37,61,33,86,79,12,17,36,41,84,34,22,5,62,80,46,33,45,45,65,64,50,11,96,27,68,71,25,11,41,2,37,43,75,4,34,86,62,59,92,49,87,27,42,64,5,20,97,11,68,97,32,45,96,43,94,81,17,71,84,99,6,91,68,46,50,44,18,8,67,28,12,10,44,6,92,35,17,58};

const int MAX_RACERS = 100; //Max number of racers in race
const int MIN_RACERS = 2; //Min number of racers in race
const int RAND_SEED = 10; //Constant seed for program (srand(RAND_SEED) in Race const.
const int SPEED_MOD = 15; //Percentage change for each lap (15%)

template <class T>
class Race{
public:
  // Name: Race (Default Constructor)
  // Preconditions: Creates a new race using a specific type of
  //                racer (racecar, truck, or formula 1
  // Postconditions: Asks how many cars in the race, inserts specific racer in race
  //                 and starts race. Also, srand(RAND_SEED) in constructor.
  Race();
  // Name: EnterRace
  // Preconditions: Has a race
  // Postconditions: Pushes the specific racer into the race
  void EnterRace(T newEntrant);
  // Name: StartRace
  // Preconditions: Has a race
  // Postconditions: Manages a race
  // Requests number of laps.
  // For each lap, checks to see if they crash (calls CheckCrash)
  // Then compares speed of each racer, if one racer is faster, swaps racers
  // At the end of chosen number of laps, the winner is who is in front
  void StartRace();
  // Name: GetRandomRacer
  // Preconditions: Has an array of names and numbers
  // Postconditions: Returns a random number from array of names/numbers
  int GetRandomRacer();
  // Name: CheckCrash
  // Preconditions: Has a race
  // Postconditions: Checks if a racer crashes (1/200 chance), if they crash speed = 0
  //          SetIsCrashed changes, Indicates crash, moves crashed racer to end of race
  void CheckCrash(int);
  // Name: RacerSpeed
  // Preconditions: Has a race and racers left in race
  // Postconditions: Calculates updated speed for a specific racer each lap
  void RacerSpeed(int);
  // Name: DisplayRacers
  // Preconditions: Has a race and racers left in race
  // Postconditions: Displays each racer in race (including if they crashed)
  void DisplayRacers();
private:
  Lqueue<T> race;
};

#endif

//***************************************************************************
//***********************Implement Race Here*********************************

// Name: Race (Default Constructor)
// Preconditions: Creates a new race using a specific type of
//                racer (racecar, truck, or formula 1
// Postconditions: Asks how many cars in the race, inserts specific racer in race
//                 and starts race. Also, srand(RAND_SEED) in constructor.
template <class T>
Race<T>::Race(){
  srand(RAND_SEED);
  int tempNumRacers;
  // Dummy check
  do{
    cout<<"How many racers would you like in the race?"<<endl;
    cin>>tempNumRacers;
  }
  while(tempNumRacers< MIN_RACERS && tempNumRacers< MAX_RACERS);

  // Push racers into race
  for(int i = 0; i<tempNumRacers; i++){
    int racer = GetRandomRacer();
    EnterRace(T(RACERS[racer], RACE_NUMS[racer]));
    //EnterRace(T(RACERS[GetRandomRacer()], RACE_NUMS[GetRandomRacer()]));
  }
  //Display racers and start race
  cout<<"Pole Positions"<<endl;
  DisplayRacers();
  StartRace();
}

// Name: EnterRace
// Preconditions: Has a race
// Postconditions: Pushes the specific racer into the race
template <class T>
void Race<T>::EnterRace(T newEntrant){
  newEntrant.SetIsCrashed(false);
  race.Push(newEntrant);
}

// Name: StartRace
// Preconditions: Has a race
// Postconditions: Manages a race
// Requests number of laps.
// For each lap, checks to see if they crash (calls CheckCrash)
// Then compares speed of each racer, if one racer is faster, swaps racers
// At the end of chosen number of laps, the winner is who is in front
template <class T>
void Race<T>::StartRace(){
  // Initialize Values
  int Laps;
  int speed1 = race[0].GetSpeed();
  int speed2 =  race[0].GetSpeed();
  int RaceSize = race.GetSize();
  // Dummy check
  do{
    cout<<"How many laps would you like to do??"<<endl;
    cin>>Laps;
  }
  while(Laps < 1 || Laps >1000);
  
  // checks each car for each Lap
  for(int i = 0; i<Laps; i++){
    for(int j = 0; j <RaceSize; j++){
      CheckCrash(j);
      RacerSpeed(j);
      speed2 =  race[j].GetSpeed();
      
      // Swaps faster racer
      if(speed1 < speed2 && !race[j].GetIsCrashed()){
	race.Swap(j);
      }
      speed1 =race[j].GetSpeed();
    }
    
    // Displays racers every lap
    cout<<"Lap "<< i+1<<endl;
    DisplayRacers();
  }
  T winner = race.Front();
  cout<<"The winner of the race is "<<winner<<endl;
}
// Name: GetRandomRacer
// Preconditions: Has an array of names and numbers
// Postconditions: Returns a random number from array of names/numbers
template <class T>
int Race<T>::GetRandomRacer(){
  return rand()% MAX_RACERS;
}

// Name: CheckCrash
// Preconditions: Has a race
// Postconditions: Checks if a racer crashes (1/200 chance), if they crash speed = 0
//          SetIsCrashed changes, Indicates crash, moves crashed racer to end of race
template <class T>
void Race<T>::CheckCrash(int index){
  // Initialize values
  T car = race[index];
  int chance = rand()%200 +1;
  bool isCrash= car.GetIsCrashed() ;

  //Checks if crashed then sets correct values
  if(chance == 1 && !isCrash){
    race[index].SetIsCrashed(true);
    cout<<"CRASH!!! "<<car.GetName()<<" crashed and is out of the race"<<endl;
    race[index].SetSpeed(0);
    race.RemoveInsertEnd(index);
  }
  else if(!isCrash){
    race[index].SetIsCrashed(false);
  }
  
}

// Name: RacerSpeed
// Preconditions: Has a race and racers left in race
// Postconditions: Calculates updated speed for a specific racer each lap
template <class T>
void Race<T>::RacerSpeed(int index){
  // Initialize Values
  int speed =race[index].GetSpeed();
  double change = rand()%(SPEED_MOD+1);
  change = double(speed)*(change/100.0);
  // Chance is up to 100 for 50/50 chance of increase or decrease
  int chance = rand()%100;
  
  // Checks to see if the racer is crashed and either increases or decrease speed
  if(!race[index].GetIsCrashed()){
    // Increase
    if(chance <=50 ){ 
      race[index].SetSpeed(int(speed+change));
    }
    // Decrease
    else{
      race[index].SetSpeed(int(speed- change));
    }
  }
  // Sets any car with negetive values to 0
  if(race[index].GetSpeed()< 0){
    race[index].SetSpeed(0);
  }
  
}

// Name: DisplayRacers
// Preconditions: Has a race and racers left in race
// Postconditions: Displays each racer in race (including if they crashed)
template <class T>
void Race<T>::DisplayRacers(){
  int raceSize = race.GetSize();

  // Iterates through the racers
  for(int i = 0; i < raceSize; i++){
    // If racer is crashed
    if(race[i].GetIsCrashed()){
      cout<<race[i].GetName()<<" crashed and is out of the race."<<endl;
    }
    else{
      cout<<race[i]<<endl;
    }
  }
}

//Don't forget to seed srand with 10 srand(RAND_SEED)

