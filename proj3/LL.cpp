/*****************************************
** File:    LL.cpp
** Project: CMSC 202 Project 3, Fall 2018
** Author:  Ryan Ellis
** Date:    10/25/18
** Section: 08
** E-mail:  r59@umbc.edu 
**
** This file contains the definition for the LL.h file. It is a linked
** list deffinition file.
**
***********************************************/
#include "LL.h"
#include <iostream>
using namespace std;



// Name: LL() - Default Constructor
// Desc: Used to build a new linked list
// Preconditions: None
// Postconditions: Creates a new linked list where m_head and m_tail point to NULL
LL::LL(){
  m_head = NULL; //Sets the pointer to point at nothing
  m_tail = NULL; //Sets the pointer to point at nothing
  m_size = 0; //Sets the size of the linked list to 0
}

// Name: ~LL() - Destructor
// Desc: Used to destruct a new linked list
// Preconditions: There is an existing linked list with at least one node
// Postconditions: A linked list is deallocated (including all dynamically allocated nodes)
//                 to have no memory leaks!
LL::~LL(){
  Clear();
}
// Name: InsertEnd
// Preconditions: Takes in a char. Creates new node.
//                Requires a linked list
// Postconditions: Adds a new node to the end of the linked list.
void LL::InsertEnd(char data){
Node *temp = new Node(); //Builds a new node
 temp->m_data = data; //Sets the value of the first node
 temp->m_next = NULL; //Sets the first node in the linked list to point to nothing
 
  if(m_head == NULL){ //Checks to see if the linked list is empty
    m_head = temp; //Inserts the first node to the linked list
    m_tail = temp; //Inserts the first node to the linked list
    m_size = 1; //Updates the size
  }
  else{
    m_tail->m_next = temp;
    m_tail = temp; //Because this is inserting in the beginning, 
    m_size++;
  }
}

// Name: Display
// Preconditions: Outputs the linked list.
// Postconditions: Returns number of nodes displayed.
int LL::Display(){
if(m_head == NULL){
  cout << "The Linked List is empty" << endl;
 }
 else{
   Node *temp = m_head;
   for(int i = 0; i < m_size; i++){
     cout << temp->m_data << "->";
     temp = temp->m_next;
   }
   cout << "END" << endl; //Indicates the end of the linked list
 }
 return m_size;
}

// Name: IsEmpty
// Preconditions: Requires a linked list
// Postconditions: Returns if the linked list is empty.
bool LL::IsEmpty(){
  // if empty return true
  if(m_head == NULL){
    return true;
  }
  // else return false
  else{
    return false;
  }
}


// Name: SizeOf
// Preconditions: Requires a linked list
// Postconditions: Populates m_size with the total number of nodes and returns m_size;
int LL::SizeOf(){
  return m_size;
}

// Name: Clear
// Preconditions: Requires a linked list
// Postconditions: Removes all nodes in a linked list
void LL::Clear(){
Node* current = m_head;
 while( current != 0 ) {
   Node* m_next = current->m_next;
   delete current;
   current = m_next;
   m_size--;
 }
 m_head = NULL;
 m_tail = NULL;
}



// Name: ReplaceData (works like find and replace)
// Desc: Iterates over the linked list and replaces every *quantity* charFrom with charTo
//       For ReplaceData ('A','C', 3) then every third 'A' would be replaced with a 'C'
// Preconditions: Requires a linked list
// Postconditions: Updates a linked list by mutating data based on a frequency
int LL::ReplaceData(char charFrom, char charTo, int frequency){
  int tempNum = 0;
  int count = 0;
  
  for(Node *temp = m_head; temp!= NULL; temp = temp->m_next){

    if(temp->m_data == charFrom){
      tempNum++;
    }
    // Checks to see if the frequncy is met
    if(tempNum == frequency){
      tempNum = 0;
      temp->m_data = charTo;
      count++;
    }
  }
  // # of times data was replaced
  return count;
}    

// Name: GetData
// Preconditions: Requires a linked list
// Postconditions: Returns the data at a specific node
char LL::GetData(int nodeNum){
  int tempNum = 0;
  char tempChar = 'E';
  for(Node *temp = m_head; temp!= NULL; temp = temp->m_next){
    tempNum++;
    if(tempNum == nodeNum){
      tempChar = temp->m_data;
      return tempChar;
    }
  }
  return tempChar;
}

// Name: operator<< (Overloaded << operator)
// Preconditions: Requires a linked list
// Postconditions: Returns an ostream with the data from every node separated by ->
ostream  &operator<<(ostream &output, LL &myLL){
  Node *temp = myLL.m_head;
  for(int i = 0; i < myLL.m_size; i++){
    output << temp->m_data << "->";
    temp = temp->m_next;
  }
  output << "END" << endl; //Indicates the end of the linked list
  return output;
  //Note to self when calling do: cout << LL;
}
