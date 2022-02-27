# Project 5 – Racer <br>Assignment: Project 5 – Racer <br>

**1. Overview**<br>
In this project, you will:<br>
- Practice basic C++ syntax including branching structures
- Write classes and instantiate those classes using a constructor
- Create a templated data structure (queue or stack)
- Use simple file input
- Use overloaded operators to access templated data structure

**2. Background**<br>
A motorsport is a global term used to encompass the group of competitive sporting events which primarily involve the use of motorized vehicles prominently used in racing. The top racers in the world earn more than $38M each year (and drive Formula One cars). For this project, we are going to create a racing simulator where the user can compete Racecars, Trucks, or Formula One in multi-lap races. You can picture the racers using a track like the track displayed below (which is used for a variety of styles of races).

This project requires a special data structure, an Lqueue, that we are going to build using a linked list. The Lqueue is a templated data structure that is designed to handle most types of data which is first-in, first-out (FIFO). This structure will be used to keep track of what order every racer is in.


**3. Assignment Description**<br>
**Class 1 – Lqueue** – This is a very important class. It is used to manage the racers. It uses a linked list to store the information about whatever it is designed to hold (in this case Racers – more specifically a subclass of either Racecar, Truck, or Formula). As a linked list, is uses templated nodes to store data. For this project, the data in every node must be private. You will need to implement normal queue functions such as Push (which inserts in the end), Pop (which removes from front), Display(which displays data in each node), Front(which returns the first element in the queue), Swap (which swaps two nodes), RemoveInsertEnd(which removes a node and moves it to the end), and Clear (which removes all nodes from the lqueue). Finally, you must implement the copy constructor and assignment operator in this class. There should be absolutely NO references to racer, racecar, truck, formula or race in this class. 

<br>You should implement this class by itself and then test it completely before using it. Do not forget how we must implement templated classes! 

<br>**Class 2: Racer** – This is a trivial parent class with little more than a very simple constructor, setters, getters, and an overloaded << function (which must be implemented in the three subclasses). The overloaded << operator and the toString function are very similar to project 4. They are used to be able to output a racer (or either subclass).

<br>**Classes 3, 4, and 5: Racecar/Truck/Formula** – These are the three subclasses to Racer. They are very similar to each other except that the overloaded << operator displays something different. The other function is an overridden toString that displays information about the Racer.

<br>**Class 5: Race** – This is the class that manages the race. It is templated as a race can be with any one of the three racers (Racecar, Truck, or Formula). It is called directly from driver.cpp. There are no data files for this project – everything is stored in two arrays included in Race.h. A race can have between 2 and 100 racers. Each race can have any number of laps between 1 and 1000. When the race starts, the Lqueue is populated with a static (no dynamically allocated racers) number of racers. The racers are displayed with their numbers. Racecars start at 200mph, Trucks start at 150mph, and Formula start at 220mph. Each lap, a car has a 1 in 200 chance of crashing. If a car crashes, it is moved to the end of the lqueue (indicating it is in last place), has a new speed of 0, and is updated to indicate that it has crashed. For all cars that haven’t crashed, a new current speed is calculated based on their current speed. Each lap, a racer’s current speed can increase or decrease 15% either direction (minimum 0 mph but no upper limit). (Yes, it can make cars go impossibly fast!) After the new speed is calculated, the current speed of a racer is compared to each racer directly before and after it. If a racer has a higher speed, the racers are swapped (indicating a new order).


**4. Requirements:**
This is a list of the requirements of this application. For you to earn all the points you will need to meet all the defined requirements.
- You must follow the coding standard as defined in the CMSC 202 coding standards (found on Blackboard under course materials). This includes comments as required.
- The project must be turned in on time by the deadline listed above.
- The project must be completed in C++. You may not use any libraries or data structures that we have not learned in class. Libraries we have learned include ```<iostream>```, ```<fstream>```, ```<iomanip>```, ```<vector>```, ```<cmath>```, ```<ctime>```, ```<cstdlib>```, ```<sstream>```, and ```<string>```. You should only use namespace std.
- Using the provided files, Lqueue.h, Racer.h, Racecar.h, Truck.h, Formula.h, Race.h, and the driver.cpp file write the program as described. (Finish Lqueue first though!) You must use an Lqueue for the race in Race.h.
- As a reminder, Lqueue.h is templated and all functions must exist in ONE file (Lqueue.h). Additionally, Race.h is templated for use with Lqueue. This would allow you to race practically anything as well.
- You can copy the files from my directory in ```/afs/users/j/d/Blah/pub/cs202/proj5```
- Class member variables must be private for project 5.
- Srand must be seeded with a constant in only the Race constructor using a constant value of 10 (RAND_SEED = 10).
- The Lqueue must be templated with all requested functions implemented (including the copy constructor and assignment operator). Please test your Lqueue before starting the Race aspects of this project!
- All user input must be validated. For example, if a menu allows for 1, 2, or 3 to be entered and the user enters a 4, it will re-prompt the user. However, the user is expected to always enter the correct data type. i.e. If the user is asked to enter an integer, they will. If they are asked to enter a character, they will. You do not need to worry about checking for correct data types.
- The code must not have memory leaks.
