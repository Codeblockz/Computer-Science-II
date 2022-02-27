# Project 4 – Safari Simulation <br> Assignment: Project 4 – Safari Simulation 

**1. Overview**<br>
In this project, you will:<br>
- Practice creating classes with inheritance 
- Working with pointers as they pertain to classes
- Using polymorphism
- Working with a large number of classes

**2. Background**<br>

Animals live in a very complex ecosystem where lots of actions and inactions change their ability to survive. One of these such ecosystem is a savannah, where carnivores and herbivores alike can interact and coexist. A safari is a zoo which people can pass through and experience such an ecosystem. The fascinating things about this kind of environment is that the animals aren’t really in captivity but in their natural habitat. Tourists typically take a jeep or a bus through the safari and observe the wildlife from a safe distance and can see more realistic interaction then they would in a conventional zoo.
For this project, we are going to create a simulated safari, where you the tourist or researcher can come back year after and see how populations of animals has changed based on random factors.
<br>**3. Assignment Description**<br>
Your assignment is to develop a simulated safari where you can observe the population shifts of animals in your park. Initially, you will need to read in the list of initial animals observed in the park from a text file into a vector.
1. There is no defined number of animals which the park starts with. (Do not use constants for this!)
2. The file is loaded via command line argument (included in the provided proj4.cpp). 
3. All user inputs will be assumed to be the correct data type. For example, if you ask the user for an integer, they will provide an integer.
4. Regardless of the sample output below, all user input must be validated. If you ask for a number between 1 and 3 with the user entering an 8, the user should be re-prompted.
5. Have a main menu that asks the user if they want to:
   - What would you like to do?:
     - Display Animals
     - Simulate
     - Exit
       - Upon exit, nothing is saved<br>
 Based on these initial animals you will be able to choose how many years forward you would like to simulate your park. The simulation will inform you every year about which animals died and were born and survived. You will also after a simulation is complete be able to display all the current residents of your park as well as some statistics about them like what age they are and what kind of health they are in. 
There will be 3 animals which will be simulated a lion a Gazelle and an elephant. Below is a hierarchy of the classes to be made.  


These are the classes that you will be required to create. An arrow represents that class is inheriting from the one above it. An additional class Safari is created which is where the simulation will be taking place and the programs main control functionality will occur.
<br>**4. Requirements:**<br>
This is a list of the requirements of this application. For this project, you will be provided with header files to start you in the right direction. For you to earn all the points, however, you will need to meet all the defined requirements.
- You must follow the coding standard as defined in the CMSC 202 coding standards (found on Blackboard under course materials). This includes comments as required.
- The project must be turned in on time by the deadline listed above.
- The project must be completed in C++. You may not use any libraries or data structures that we have not learned in class. Libraries we have learned include ```<iostream>```, ```<fstream>```, ```<iomanip>```, ```<vector>```, ```<cmath>```, ```<ctime>```, ```<cstdlib>```, and ```<string>```. You should only use namespace std.
- Using the provided files, Animal.h, Safari.h, Carnivore.h, Herbivore.h, Lion.h, Gazelle.h, Elephant.h and driver.cpp, to create the Safari Simulation. You can copy the files from my directory in /afs/umbc.edu/users/j/d/jdixon/pub/cs202/proj4. You can add helper functions but all given functions must be implemented.
- There are three test input files for this project named, “proj4_t1.txt”, “proj4_t2.txt” and “proj4_t3.txt”. The names are inputted as command line arguments. The files are already provided in Prof. Dixon’s course folder on GL. You can download them using instructions above.
- To copy them, navigate to your project 4 folder and type:<br>
```cp /afs/users/j/d/Blah/pub/cs202/proj4/*.* ``` <br>
Makefile is not provided with this project and you will have to create your own. <br>
- The format of the input file is:
  - Type Gender health age
  - Type is 0-2 inclusively 0 is Lion, 1 is Gazelle, 2 is Elephant
  - Gender is an enum in which {FEMALE, MALE}
  - Health is a value between 1-10. If health gets to 0 the animal dies.
    - Health descriptors are as follows: 10 = Perfect, 9 = Excellent, 8 = Great, 7 = Very Good, 6 = Good, 5 = Average, 4 = Ok, 3 = Poor, 2 = Diminishing, 1 = Bad, and 0 = Dead.
  - Age is a value from 1-5. 1 is the youngest, 5 is the oldest
    - Age descriptors are as follows: 5 = Old, 4 = Middle, 3 = Prime, 2 = Young, 1 = Very Young.
- Have a main menu that asks if the user wants to:
  - Display Animals which displays all the current animals in the simulation. It displays Which animal they are, its gender, its health and its age.
  - Simulate
    - Asks how many years of simulation you would like to do and the run a simulation for that many years and output what happens to the animals in your vector.
  - Exit
- In a year of simulations, the following happens to all the animals:
  - The animal has a 50% chance of their health diminishing by 1 this hypothetically can be from injury or sickness.
  - The animals health diminishes by 1 is they did not eat based on the eat() function in the animal class (this is unrelated to the previous bullet and one doesn’t affect the other. An animal’s health could potentially diminish by 2 in total in a year)
  - The animal has a chance to breed and add an offspring to the animal vector.
- Each class has the following restrictions on when it can eat or breed (which were heavily scientifically researched for the sake of this project)
  - Carnivore
    - Eat – if they hunt and succeed or are of age 1, they have eaten successfully. If that was not the case Eat will return true 50% of the time  
  - Herbivore
    - Eat – if they graze and succeed or are of age 1, they have eaten successfully. Otherwise, they have not eaten successfully
  - Lion
    - Hunt – They are successful their health * 10% of the time. Weaker lions are less successful at finding prey
    - Breed – Only female Lions age 3 or 4 can breed. They have a 50% chance of being successful
  - Gazelle
    - Graze – They stop grazing at age 5 and prior have a health*15% chance of grazing successfully (after health of 7 they graze 100% of the time).
    - Breed – Only females over the age one can breed and they have a 30% chance of producing offspring
  - Elephant
    - Graze – They have a flat 95% chance of grazing successfully
    - Breed – Only females over the age two can breed and they have a 40% chance of producing offspring 
    
**5. Recommendations**<br>
Here are some general implementation recommendations (do not follow these verbatim – these are GENERAL suggestions):<br>
- Read each of the header files in detail. Use paper to take notes. Each header file has tons of comments.
- Design the solution (part is already designed, so make sure you understand how it works) on PAPER.
- Start with the Animal.cpp file and code down the hierarchy (doing Carnivore.cpp and Herbivore.cpp next and then the final child classes). Test everything incrementally.
- Code Safari.cpp last after you know all your classes work.
- Once the vectors have been populated, write a temporary test function that displays all the animals. 
- Comment out the main parts of the driver and use is to run tests
- Test parts of Safari.cpp before running the code through using just the mainMenu.
- In general, the overloaded << operator will be tricky and the simulateYear function will be difficult.
