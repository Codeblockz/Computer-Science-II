//Title: Game.h
//Author: Jeremy Dixon
//Date: 10/4/2018
//Description: This is part of the Fortnite Dance Royale Project in CMSC 202 @ UMBC

#ifndef GAME_H //Header Guard
#define GAME_H //Header Guard

#include "Hero.h"
#include "Dance.h"
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

const string PROJ2_HEROES = "proj2_heroes.txt"; //File constant
const string PROJ2_DANCES = "proj2_dances.txt"; //File constant
const string WELCOME = "Welcome to Fortnite Dance Royale\nWhat do you want your dance battler to be called?";//Welcome statement
const string THANKS = "Thanks for Playing"; // Thanks user for playing
const string MAIN_MENU ="What would you like to do?\n1. Display Dance\n2. Train Dance Move\n3. Learn New Dance\n4. Enter Dance Tournament\n5. Quit";// Main Menu
const string TRAIN = "Which dance would you like to train?"; // Would you like to train a dance?
const string IMPROVEMENT = "You have improved your dance"; // Improvement string
const string NO_MORE = "You can't learn more than 5 dances!"; // no more dances can be learned
const string LEARN_MENU = "What difficulty of dance would you like to learn?\n1. Easy\n2. Difficult\n3. Epic"; // Learning menu
const string LEARNED = "Congrats you just learned the "; // congratory statement for learning move
const string TOURNAMENT_PROMPT ="How many people would you like in your dance battle royale? (1-10)"; // prompt for enter tournament
const string SUPPER_ENEMY = " have busted out some righteous  moves and you LOST the battle!"; // enemy supper
const string WON_TOURNAMENT = "You have won the tournament"; //win statement 
const string LOSE_TOURNAMENT = "You have lost the tournament"; //lose statement 



const int UPPER_LIMIT = 100; // max for rand()

//Additional HELPER functions allowed to be added as needed

class Game{
public:
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
  Game(); //Default Constructor
  // Name: LoadHeroes
  // Desc - Loads each hero into m_hero from file and 
  //        adds 5 dances to each enemy dancer (random style, difficulty, level)
  // Preconditions - Requires file with valid hero data
  // Postconditions - m_heroes is populated with hero objects
  void LoadHeroes();
  // Name: LoadDances
  // Desc - Loads each dance into m_dances from file
  // Preconditions - Requires file with valid dance data
  // Postconditions - m_dances is populated with dance structs
  void LoadDances();
  // Name: StartGame()
  // Desc - Manages the game itself including win conditions continually
  //         calling the main menu 
  // Preconditions - Player is placed in game
  // Postconditions - Continually checks to see if player has entered 5
  void StartGame();
  // Name: DisplayMyDances()
  // Desc - Displays the current dances (calls hero version of function)
  // Preconditions - Player has dances
  // Postconditions - Displays a numbered list of dances
  void DisplayDances();
  // Name: MainMenu()
  // Desc - Displays and manages menu
  // Preconditions - Player has a hero
  // Postconditions - Returns number including exit
  int MainMenu();
  // Name: TrainDance()
  // Desc - Allows player to train a dance (increases skill)
  // Preconditions - Dances exist
  // Postconditions - Increases level of specific dance 50% of the time
  void TrainDance();
  // Name: LearnNewDance()
  // Desc - Allows player to learn a new dance based on difficulty (1. easy, 2. difficult, 3. epic)
  //        1 easy occurs 50% of the time, 2. Difficult occurs 25% of the time, 
  //        and 3. Epic occurs 10% of the time
  // Preconditions - Dances exist
  // Postconditions - Adds dance to the heroes list of dances
  void LearnNewDance();
  // Name: EnterTournament()
  // Desc - Creates a tournament (winner stay on) for 1-10 enemy dancers
  // Randomly chooses defined number of enemy dancers for tournament
  // Player chooses a dance from their list. Player quality is level * difficulty
  // Enemy dancer randomly chooses a dance and quality is level * difficulty
  // Preconditions - Player has at least one dance
  // Postconditions - Player wins or loses a dance tournament
  void EnterTournament();

  // Name: CheckName(vector<Hero>, string)
  // Desc - Checks the vector to see if the name is in the vector
  // Preconditions - vector exist
  // Postconditions - Returns true if name in lis and false if not
  bool CheckName(vector<Hero> , string );

private:
  vector <Hero> m_heroes; //All enemy heroes in game (loaded from file)
  vector <Dance> m_dances; //All dances in the game (loaded from file)
  Hero m_myHero; //Player's hero
  string m_name; //Player's name
};

#endif //Exit Header Guard
