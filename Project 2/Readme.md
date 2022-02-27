# Project 2 – Fortnite Dance Royale <br> Assignment: Project 2 – Fortnite Dance Royale

**Overview**<br>
In this project, you will:<br>
- Practice basic C++ syntax including branching structures
- Write classes and instantiate those classes using a constructor
- Use vectors to hold objects
- Use simple file input
- Practice breaking projects into multiple files
- Use a makefile to compile a project


**Background**

Fortnite is an online video game that was released by Epic Games in 2017. With more than 125 million players in less than a year, Fortnite has redefined the free-to-play games everywhere. The more popular edition of the game called Battle Royale has been well documented as a distraction to a wide variety of students of all ages.
One interesting aspect of the game involves a variety of dance moves that can be done by various in-game players (after earning or buying those moves). For this project, we are going to create a game where you play a dance battler who trains and can enter dance tournaments competing against a variety of enemy dancers.<br>
**Assignment Description**<br>
Your assignment is to develop Fortnite Dance Royale which is a role-playing game where you are a novice dance battler. Initially, you will need to read in the list of available dances from a text file into a vector. Additionally, you will need to populate the long list of enemy dancers. After that, the game progresses with the player attempting to learn new dance moves and training on already known moves. After the player feels ready, he or she can enter a dance tournament where you compete against a variety of different enemy dancers each getting more and more experienced. Learn new dances, practice those dances, and defeat your competition on your way to tournament champion!
<br>**Requirements:**<br>
This is a list of the requirements of this application. For this project, you will be provided with header files to start you in the right direction. For you to earn all the points, however, you will need to meet all the defined requirements.
You must follow the coding standard as defined in the CMSC 202 coding standards (found on Blackboard under course materials). This includes comments as required.
The project must be completed in C++. You may not use any libraries or data structures that we have not learned in class. Libraries we have learned include <iostream>, <fstream>, <iomanip>, <vector>, <cmath>, <ctime>, <cstdlib>, and <string>. You should only use namespace std.
Using the provided files, Dance.h, Hero.h, Game.h, makefile and proj2.cpp, create Fortnite Dance Royale. You can copy the files from my directory in ~~/afs/umbc.edu/users/j/d/jdixon/pub/cs202/proj2~~. 
To copy them, navigate to your project 2 folder and type:
cp /afs/umbc.edu/users/j/d/jdixon/pub/cs202/proj2/*.* .
cp /afs/umbc.edu/users/j/d/jdixon/pub/cs202/proj2/makefile .
Makefiles must be copied separately as they are not transferred using the *.* wildcards.
You must use the provided header files (Dance.h, Hero.h and Game.h). You may only add HELPER functions and global constants to these files. Do not add member variables to any class.
All user input must be validated. For example, if a menu allows for 1, 2, or 3 to be entered and the user enters a 4, it will re-prompt the user. However, the user is expected to always enter the correct data type. i.e. If the user is asked to enter an integer, they will. If they are asked to enter a character, they will. You do not need to worry about checking for correct data types.
There are two input files for this project named, “proj2_dances.txt” and “proj2_heroes.txt”. The names can be stored as a constant. The files are already provided in Prof. Dixon’s course folder on GL. You can download it using instructions below.
You do not need to use pointers in this project, however, you will need to pass-by-reference
The player’s name can have a space (use getline).
Have a main menu that asks if the user wants to:
Display currently known dances (initially, the player’s hero should know the first dance “Dance Moves” at level 0). As the player learns more dances, they will be displayed here as well.
Train Dance Move
Asks which dance move you would like to train. You have a 50% chance of going up a level. You are limited to level 10 for any dance move.
Learn a New Dance
Asks how difficult of a move you would like to learn. Easy moves are learned 50% of the time. Difficult dances are learned 25% of the time. Epic dances are learned 10% of the time.
Enter a Dance Tournament
The dance tournament can have from 1-10 people. For each round, the player chooses a dance to execute. Each computer-controlled hero has 5 dances already loaded into each hero. Each round is governed by the dance battle description below.
Dance Battles
Enemy dancers are chosen randomly from all available dancers and automatically start with five dances known of random style and difficulty. The level of their dances should be increasingly higher as a tournament continues.
The player’s dance quality (difficulty*level) is compared to enemy dance quality (difficulty*level). Additionally, there is a 5% chance that the player will “bust-a-move” that will automatically defeat the enemy dancer.
The outcome of the fight will be one of the following:
The player dancer wins, it indicates that it won and it attempts to compete against the next dancer in the tournament (unless it is the end).
The enemy dancer wins, it indicates that it won and the player tournament ends.
There is a draw (both dancers have the same dance quality). If this occurs, the player continues to the next round.
If the player makes it to the last round, they must have won at least half of the rounds(rounding up!) in order to be crowned the tournament champion!
Exit
Recommendations
You must use the provided header files (Dance.h, Hero.h, and Game.h) additionally, we provided you with the makefile and the proj2.cpp. 
Here are some general implementation recommendations (do not follow these verbatim – these are GENERAL suggestions):
Read each of the header files in detail. Use paper to take notes. Each header file has tons of comments.
Design the solution (part is already designed, so make sure you understand how it works) on PAPER.
Start with the Hero.cpp file and code everything except DanceBattle(). Don’t forget the constructor! Test everything incrementally.
Start Game.cpp – start building the constructor. Incrementally build it as you are testing a function.
Once Hero.cpp is written, start on Game.cpp – start with loading in the dances from the proj2_dances.txt file. This will be tricky because you have dance names with spaces and a comma delimited data file. You can do this without using the atoi command (which converts a string to an integer). (If necessary, you are allowed to use atoi (in cstdlib) using syntax similar to this: int number = atoi(str.c_str()); Repeat this for loading in the m_heroes vector.
Once the vectors have been populated, write a temporary test function that displays both vectors. 
After the files are successfully loaded (and displayed) work on the main menu.
Save attack and Heroic dance functions to the end.
