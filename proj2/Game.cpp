#include <iostream>
#include "Game.h"
#include "Hero.h"
#include "Dance.h"
#include <vector>
#include <cmath>
using namespace std;

  /* Name: Game() Default Constructor
  // Desc - Builds a new game by:
  // 1. Seeding srand
  // 2. Ask user name (store in m_myHero as m_name)
  // 3. Loads NPC heroes into m_heroes
  // 4. Loads all dance moves into m_dances;
  // 5. Adds m_dance 0 (Dance Moves) into the player as level 0
  // Preconditions - None
  // Postconditions - m_heroes is populated and m_dances is populated and m_myHero has one dance
  */
Game::Game(){
  // 1. seed srand
  srand(time(NULL));

  // 2. Ask user name (store in m_myHero as m_name)
  cout<<WELCOME<<endl;
  getline(cin,m_name);
  m_myHero.SetName(m_name);
  
  // 4. Loads all dance moves into m_dances;
  LoadDances();

  //3. Load Hero
  LoadHeroes();
  
  //5. Adds m_dance 0 (Dance Moves) into the player as level 0
  m_myHero.AddDance(m_dances[0]);

  
}

// Name: LoadHeroes
// Desc - Loads each hero into m_hero from file and
//        adds 5 dances to each enemy dancer (random style, difficulty, level)
// Preconditions - Requires file with valid hero data
// Postconditions - m_heroes is populated with hero objects

void Game::LoadHeroes(){

  ifstream HeroNames(PROJ2_HEROES);
  string name;
  Hero enemy;

  if (HeroNames.is_open()){

    while(getline(HeroNames,name)){
      
      Hero enemy(name, false);
      m_heroes.push_back(enemy);

    }
  }
  HeroNames.close();
  //intiate dance num vector for 5 separt numbers
  vector <int> danceNum( NUM_DANCES);
  int DanceSize = int(m_dances.size());
  int rdNum = rand()%DanceSize;
  Dance dance = m_dances[rdNum];

  // Load 5 dances into each NPC
  for(vector<Hero>::iterator it = m_heroes.begin();it != m_heroes.end(); it++){
    for(int i = 0; i<NUM_DANCES; i++){
      rdNum = rand()%DanceSize;
      dance = m_dances[rdNum];
      // redundancy check
      while((*it).CheckDance(dance.m_name)){
	rdNum = rand()%DanceSize;
	dance = m_dances[rdNum];
      }
      // Adds the dance into the object
      (*it).AddDance(dance);
    }
    
  }
}
  
// Name: LoadDances
// Desc - Loads each dance into m_dances from file
// Preconditions - Requires file with valid dance data
// Postconditions - m_dances is populated with dance structs
void Game::LoadDances(){
  ifstream danceFile(PROJ2_DANCES);
  string danceName;
  string style;
  string difficulty;
  int Style;
  int Difficulty;
  Dance dance();
  if (danceFile.is_open()){
    
    while(getline(danceFile,danceName,',')){
      getline(danceFile,style,',');
      getline(danceFile, difficulty);
      Style = atoi(style.c_str());
      Difficulty = atoi(difficulty.c_str());
      Dance dance(danceName, Style, Difficulty, 0);
      m_dances.push_back(dance);
    }
  }
  danceFile.close();
}  
  // Name: StartGame()
  // Desc - Manages the game itself including win conditions continually
  //         calling the main menu
  // Preconditions - Player is placed in game
  // Postconditions - Continually checks to see if player has entered 5
void Game::StartGame(){
    int menu = 0;
    while(menu!= 5 ){
      menu = MainMenu();
      
      //menu choice
      switch(menu){

      // Display Dances
      case 1:
	DisplayDances();
	break;
      // Train dance
      case 2:
	TrainDance();
	break;

      //Learn New Dance
      case 3:
	LearnNewDance();
	break;
	
      //Enter dance tournament
      case 4:
	EnterTournament();
	break;

      // End of play
      case 5:
	cout<<THANKS<<endl;
	break;
      
      }
    }
}
// Name: DisplayMyDances()
// Desc - Displays the current dances (calls hero version of function)
// Preconditions - Player has dances
// Postconditions - Displays a numbered list of dances
void Game::DisplayDances(){
  // Formats for the dances displayed
  cout<<setw(15)<<"Dance"<<setw(16)<<"Style"<<setw(13)<<"Level"<<setw(13)<<"Difficulty"<<endl;
  m_myHero.DisplayDances(); 
}

// Name: MainMenu()
// Desc - Displays and manages menu
// Preconditions - Player has a hero
// Postconditions - Returns number including exit
int Game::MainMenu(){
  // Prompts menu
  cout<< MAIN_MENU<<endl;
  int menu;
  // Gets choice
  cin>>menu;
  return menu;
}

// Name: TrainDance()
// Desc - Allows player to train a dance (increases skill)
// Preconditions - Dances exist
// Postconditions - Increases level of specific dance 50% of the time
void Game:: TrainDance(){
  // Intialize variables
  int  danceCount= m_myHero.GetDanceCount();
  int choice;
  int chance = rand()%UPPER_LIMIT;
  do{
    // Prompts user
    cout<<TRAIN<<endl;
    
    // Displays dances
    m_myHero.DisplayDances();
    
    //Gets choice
    cin>>choice;
    choice--;
  }
  // User error check
  while(choice<0 or choice > (danceCount-1));

  // Checks if dance is at the max level
  if(m_myHero.CheckDanceLevel(choice)){
    // Checks to see if they leveled up
    if(chance > 50){
      m_myHero.IncreaseDance(choice);
      cout<<IMPROVEMENT<<endl;
    }
  }
  
}

 // Name: LearnNewDance()
  // Desc - Allows player to learn a new dance based on difficulty (1. easy, 2. difficult, 3. epic)
  //        1 easy occurs 50% of the time, 2. Difficult occurs 25% of the time,
  //        and 3. Epic occurs 10% of the time
  // Preconditions - Dances exist
  // Postconditions - Adds dance to the heroes list of dances
void Game::LearnNewDance(){
  // Intialize variables
  vector <Dance> easy;
  vector <Dance> difficult;
  vector <Dance> epic;
  int userChoice;
  int chance = rand()%UPPER_LIMIT;

  // redundancy check
  if(m_myHero.GetDanceCount()>NUM_DANCES){
    cout<<NO_MORE<<endl;
  }
  else{

    for (vector<Dance>::iterator it = m_dances.begin();it != m_dances.end(); it++){
      // Filter dances for ease of selection
      switch((*it).m_difficulty ){
	// Easy
      case 0:
	easy.push_back(*it);
	break;

	// Difficult
      case 1:
	difficult.push_back(*it);
	break;

	// Epic
      case 2:
	epic.push_back(*it);
	break;
      }
    }
    // Ask what difficulty of dance they want to learn
    do{
      cout<< LEARN_MENU <<endl;
      cin>>userChoice;
    }
    while(userChoice > 3 or userChoice <1);
    int easyNum= int(easy.size());
    easyNum = rand()%easyNum;
    int difficultNum = int(difficult.size());
    difficultNum = rand()%difficultNum;
    int epicNum = int(epic.size());
    epicNum =rand()%epicNum;
  
    // Determines if new dance is learned
      switch(userChoice){
	// Easy
      case 1:
	if(chance <= 49){
	  m_myHero.AddDance(easy[easyNum]);
	  cout<<LEARNED<<easy[easyNum].m_name<<"!"<<endl;
	}		  
	break;

	// Difficult
      case 2:
	if(chance >= 50 and chance <= 74){
	  m_myHero.AddDance(difficult[difficultNum]);
	  cout<<LEARNED<<difficult[difficultNum].m_name<<"!"<<endl;
	}
	break;

	// Epic
      case 3:
	if(chance >= 76 and chance <= 85){
	  m_myHero.AddDance(epic[epicNum]);
	  cout<<LEARNED<< epic[epicNum].m_name<<"!"<<endl;
	}
	break;
      }
      
  }
}
// Name: EnterTournament()
// Desc - Creates a tournament (winner stay on) for 1-10 enemy dancers
// Randomly chooses defined number of enemy dancers for tournament
// Player chooses a dance from their list. Player quality is level * difficulty
// Enemy dancer randomly chooses a dance and quality is level * difficulty
// Preconditions - Player has at least one dance
// Postconditions - Player wins or loses a dance tournament
void Game::EnterTournament(){
  cout<<TOURNAMENT_PROMPT<<endl;
  double enemyNum;
  cin>>enemyNum;

  // Dummy check
  while(enemyNum < 1 or enemyNum >MAX_LEVEL){
    cout<<TOURNAMENT_PROMPT<<endl;
    cin>>enemyNum;
  }
  // Intialize values for enemy NPCs
  vector <int> TempNums(enemyNum);
  vector <Hero> enemies(enemyNum);
  int heroSize = int(m_heroes.size());
  int rdNum = rand()%heroSize;
  int rdDance = rand()%NUM_DANCES;
  int rdChance = rand()%UPPER_LIMIT;
  string  enemyName ;
  
  // Generates enemy NPC
  for(vector<Hero>::iterator it = enemies.begin();it != enemies.end(); it++){
    rdNum = rand()%heroSize;
    enemyName = m_heroes[rdNum].GetName();
    while(CheckName(enemies,enemyName)){
      rdNum = rand()%heroSize;
      enemyName = m_heroes[rdNum].GetName();
    }
    *it= m_heroes[rdNum];
  }
  //for each enemy
  for(int i = 0; i<enemyNum; i++){
    
    //Increase levels of dance for each enemy
    for (int j = 0; j <NUM_DANCES ;j++){
      //Increases level i times
      for(int k = 0; k<i;k++){
	enemies[i].IncreaseDance(j);
      }
    }
  }
  int count=0;
  
  // FIGHT!
  for (int i = 0; i<enemyNum;i++){
    rdChance = rand()%UPPER_LIMIT;
    
    // FINISH THEM!
    if(rdChance<NUM_DANCES){
      cout<<m_myHero.HeroicDance()<<endl;
      count++;
    }
    
    else if(rdChance>= NUM_DANCES  and rdChance<MAX_LEVEL){
      cout<<enemies[i].GetName()+ SUPPER_ENEMY<<endl;
      i = enemyNum;
    }
    else{
      bool win = m_myHero.DanceBattle(enemies[i]);
      if (win){
	count++;
      }
      else{
	i = enemyNum;
      }
    
    }
  }
  
  if(round(count/enemyNum)==1){
    
    cout<<WON_TOURNAMENT<<endl;
  }
  else{
    cout<<LOSE_TOURNAMENT<<endl;

  }
  
}
// Name: CheckName(vector<Hero>, string)
// Desc - Checks the vector to see if the name is in the vector
// Preconditions - vector exist
// Postconditions - Returns true if name in lis and false if not
bool Game::CheckName( vector <Hero> enemies , string name){
  for (vector<Hero>::iterator it = enemies.begin();it != enemies.end(); it++){
    // if name in vector return true
    if( name == (*it).GetName()){
      return true;
    }
  }
  return false;
}
