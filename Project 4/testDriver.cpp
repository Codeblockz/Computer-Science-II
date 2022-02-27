#include "Animal.h"
#include "Carnivore.h"
#include "Herbivore.h"
#include "Gazelle.h"
#include "Elephant.h"
#include "Safari.h"
#include "Lion.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int main(){
  srand(time(NULL));
  cout<<"Gazelle"<<endl;
  Gazelle anim1 = Gazelle(FEMALE,10, 3);
  cout<<anim1<<endl;

  Animal* kid = anim1.breed();
  if(kid == NULL)
    cout<<"WOW"<<endl;
  else
    cout<<"nature was made"<<endl;
  
  return 0;
}
