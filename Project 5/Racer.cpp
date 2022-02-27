/*****************************************
 ** File:    Racer.cpp
 ** Project: CMSC 202 Project 5, Fall 2018
 ** Author:  Ryan Ellis
 ** Date:    11/29/18
 ** Section: 08
 ** E-mail:  r59@umbc.edu
 **
 ** This file contains the cpp file for the Racer.h
 ** file
 **
 ***********************************************/
#include "Racer.h"

//Default constructor
Racer::Racer(){
}
//Overloaded constructor
Racer::Racer(string name, int number, int speed){
  m_name = name;
  m_number= number;
  m_speed = speed;
}

//Getters and setters for each Racer
void Racer::SetValues(string name, int number, int speed){
  m_name = name;
  m_number= number;
  m_speed = speed;
}
string Racer::GetName() const{
  return m_name;
}
void Racer::SetName(string name){
  m_name = name;
}
int Racer::GetNumber() const{
  return m_number;
}
void Racer::SetNumber(int number){
  m_number = number;
}
int Racer::GetSpeed() const{
  return m_speed;
}
void Racer::SetSpeed(int speed){
  m_speed = speed;
}
void Racer::SetIsCrashed(bool crash){
  m_isCrashed = crash;
}
bool Racer::GetIsCrashed() const{
  return m_isCrashed;
}
//Racer overloaded << operator

ostream& operator<<(ostream& output, Racer& racer){
  output<< racer.ToString()<<" "<<racer.GetName()<<" (#"<<racer.GetNumber()
	<<") going "<< racer.GetSpeed();
  return output;
}
