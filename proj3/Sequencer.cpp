/*****************************************
 File:    Sequencer.cpp
 ** Project: CMSC 202 Project 3, Fall 2018
 ** Author:  Ryan Ellis
 ** Date:    10/26/18
 ** Section: 08
 ** E-mail:  r59@umbc.edu
 **
 ** This file contains the definition for the Sequencer.h file. It is the
 ** program file that calls the linked list.
 **
 ***********************************************/
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Sequencer.h"
using namespace std;
const string MAIN_MENU ="What would you like to do?: \n1. Display Strands\n2. Use Consensus Tool\n3. Mutate Strands\n4. Exit";


// Name: Sequencer (default constructor)
// Preconditions: A linked list (DNA) is available
// Postconditions: A linked list (DNA) where m_head and m_tail points to NULL
//                m_size is also populated with SizeOf
Sequencer::Sequencer(string fileName){
  // puts the name if the file in the member varable
  m_fileName =fileName; 
  readFile();
  m_consensus = new LL();
  mainMenu();
  
}

// Name:  Sequencer (destructor)
// Preconditions: There is an existing linked list (DNA)
// Postconditions: A linked list (DNA) is deallocated (including nucleotides) to have no memory leaks!
Sequencer::~Sequencer(){
  for(vector<LL*>::iterator it = m_dna.begin();it != m_dna.end(); it++){
    (*it)->Clear();
    delete *it;
  }
  delete  m_consensus;

}

// Name:  DisplayStrands
// Preconditions: At least one linked list is in m_dna
// Postconditions: Displays each linked list (DNA strand) in m_dna
void Sequencer::DisplayStrands(){
  
  if(int(m_dna.size())>=0){
    
    // Iterates through each node
    for(vector<LL*>::iterator it = m_dna.begin();it != m_dna.end(); it++){
      (*it)->Display();
      cout<<(*it)->SizeOf()<<endl;
    }
  }
}
// Name:  readFile
// Preconditions: Valid file name of characters (Either A, T, G, or C)
// Postconditions: Populates the LinkedList (DNA)
void Sequencer::readFile(){
  string fileName;
  
  // covert to c-string for fstream
  fileName= m_fileName.c_str();
  string tempString;
  ifstream FileIn(fileName);
  int Strand =1;
  int nucleotides = 0;
  int count=-1;
  
  if (FileIn.is_open()) {
    cout<<"Opened File\n"<<endl;
    
    while(getline(FileIn,tempString)){

      count++;

      // New link List
      m_dna.push_back(new LL);

      //resets nucleotide number
      nucleotides = 0;      

      // read in string and in a for loop seperate the charecters
      for(int i =0; i < int(tempString.size()); i++){

	// Make charecter for temp data
	char tempChar = tempString[i];
	
	if( tempChar == 'A' || tempChar == 'T' ||tempChar =='G' || tempChar =='C'){
	  // Add charecter into LL
	  m_dna.at(count)->InsertEnd(tempChar);
	  nucleotides++;
	}
	
      }
      //outputs which strand has been loaded
      cout<<"Strand "<<Strand++<<" loaded with "<<nucleotides<<" nucleotides."<<endl;
      cout<<*m_dna.at(count)<<endl;
      
    }
    // End of loading strands message
    cout<<--Strand<<" strands have loaded."<<endl;
  }
  
  FileIn.close();
} 

// Name:  mainMenu
// Preconditions: Populated LinkedList (DNA)
// Postconditions: None
void Sequencer::mainMenu(){
  int userInput;
  do{
    cout<<MAIN_MENU<<endl;
    cin>>userInput;
    switch(userInput){

    case 1:
      DisplayStrands();
      
      break;
      
    case 2:
      CalculateConsensus();
      break;
      
    case 3:
      MutateStrand();
      break;
    
    case 4:
      
      break;
    }
  }  
  while(userInput!=4);
}

// Name:  CalculateConsensus
// Preconditions: Populated m_dna vector populated with 3 or  more strands
// Postconditions: Creates a  new strand that represents the  most common nuceloti
// at each position
void Sequencer::CalculateConsensus(){
  m_consensus->Clear();
  // Intialize for length
  int StrandSize = m_dna.at(0)->SizeOf();

  // Temp Charecter
  char tempChar= ' ';

  // Index count 0:G, 1:C, 2:A, 3:T
  vector<int> StrandCounts(4);

  // iterate through each elemet
  for (int i = 0; i <StrandSize;i++){

    // Resets comparison vector for each loop
    for(vector<int>::iterator it = StrandCounts.begin();it != StrandCounts.end(); it++){
      *it = 0;
    }
    for(vector<LL*>::iterator it = m_dna.begin();it != m_dna.end(); it++){
      //Counting how many charecters in each strand
      if((*it)->GetData(i+1) == 'G'){
	StrandCounts[0]++;
      }
      else if((*it)->GetData(i+1) == 'C'){
        StrandCounts[1]++;
      }
      else if((*it)->GetData(i+1) == 'A'){
        StrandCounts[2]++;
      }
      else if((*it)->GetData(i+1) == 'T'){
        StrandCounts[3]++;
      }
    
    }
    // Finds most reocurring Character
    int placeCount = 0;
    int Max = 0;
    for(vector<int>::iterator it = StrandCounts.begin();it != StrandCounts.end(); it++){
      
      if((*it) > StrandCounts.at(Max)){
	Max= placeCount;
      }
      placeCount++;
    }
    //based on Max assign char data
    // Index count 0:G, 1:C, 2:A, 3:T
    switch(Max){
    case 0:
      tempChar = 'G';
      break;

    case 1:
      tempChar = 'C';
      break;

    case 2:
      tempChar = 'A';
      break;

    case 3:
      tempChar = 'T';
      break;

    }   
    // Insert character into list
    m_consensus->InsertEnd(tempChar);
  }
  // print out consensus
  cout<<*m_consensus<<endl;
}


// Name:  MutateStrand
// Preconditions: Populated LinkedList (DNA)
// Postconditions: DNA strand is mutated from a specific nucleotide (G,C,A,T) to another
//                 valid nucleotide (G,C,A,T) at a given interval.
void Sequencer::MutateStrand(){
  // Initialize variables
  bool choice = true;
  char charTo;
  char charFrom;
  int frequency;
  
  // Choice 1 validity check
  do{
    cout<<"Which nucleotide would you like to replace? (A,T,G,C)"<<endl;
    cin>>charFrom;
    if(charFrom == 'A' || charFrom == 'T' || charFrom == 'G' || charFrom == 'C'){
      choice=false;}
    else{
      choice =true;}
  }
  while(choice);

  // Choice 2 validity check
  do{
    cout<<"Which nucleotide would you like to change to? (A,T,G,C)"<<endl;
    cin>>charTo;
    if(charTo == 'A' || charTo == 'T' || charTo == 'G' || charTo == 'C'){
      choice=false;}
    else{
      choice =true;}
  }
  while(choice);
  
  // Choice 3 validity check
  do{
    cout<<"How frequently? (every other? every third? 1-5)"<<endl;
    cin>>frequency;
    if(frequency <= 5 && frequency > 0){  
      choice=false;}
    else{
      choice =true;}
  }
  while(choice);

  // Change data 
  for(vector<LL*>::iterator it = m_dna.begin();it != m_dna.end(); it++){
    (*it)->ReplaceData(charFrom,charTo,frequency);
  }
    

}
    
