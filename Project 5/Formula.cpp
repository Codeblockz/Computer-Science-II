/*****************************************
 ** File:    Formula.cpp
 ** Project: CMSC 202 Project 5, Fall 2018
 ** Author:  Ryan Ellis
 ** Date:    11/29/18
 ** Section: 08
 ** E-mail:  r59@umbc.edu
 **
 ** This file contains the cpp file for the Formula.h
 ** file
 **
 ***********************************************/
#include "Formula.h"
Formula::Formula(){}
ostream& operator<<(ostream& output, const Formula& racer){
  output<<racer.ToString()<<" "<< racer.GetName()<<" (#"<<racer.GetNumber()
        <<") going "<< racer.GetSpeed()<<" MPH";
  return output;
}
