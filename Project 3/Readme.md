# Project 3 – DNA Consensus Tool<br>Assignment: Project 3 – DNA Consensus Tool

**1. Overview**<br>
In this project you will:<br>
- Implement a linked-list data structure,
- Use dynamic memory allocation to create new objects,
- Practice using C++ class syntax, 
- Practice dynamically allocated arrays, 
- Practice object-oriented thinking. 

**2. Background**<br>
Deoxyribonucleic acid (DNA) is a molecule that carries the genetic instructions used in the growth, development, functioning and reproduction of all known living organisms. Most DNA molecules consist of two strands coiled around each other to form a double helix. The two DNA strands are termed polynucleotides since they are composed of simpler monomer units called nucleotides. The nucleotides for DNA are made up of four bases - adenine (A), guanine (G), cytosine (C), and thymine (T).<br>
DNA sequencing is the process of determining the precise order of nucleotides within a DNA molecule. The four nucleotides (G, C, A, T) are paired. This means that if one strand of the DNA has a G, the other strand will have a C. If one strand has an A, the other strand will have a T (and vice-versa). If you have just one of the strands, you have the leading strand. If you have both strands, each pair of nucleotides is called a base pair. Base pairs will always be (A+T, T+A, G+C, or C+G). We will be using several leading strands (without the pair) for this project.<br>

A consensus sequence is determined by aligning many nucleotide sequences that share a common function, then determining the most commonly expressed nucleotide at each position. Often conserved sequences reflect a common function or binding domain. In this project, we are going to compare several nucleotide sequences (DNA strands) to evaluate consensus sequences.<br>
In the example below, you can see three individual DNA strands. Each strand is made up of a sequence of A, T, G, or C. To create a consensus sequence, you need to look at three or more strands and see which nucleotide exists the most commonly in the same position.

Below is another example (T is U in this case):

Assignment Description
Your assignment is to build an application that can read a file of nucleotides into three or more linked lists. 
The file contains more than one sequence of nucleotides (G, C, A, T).
Each strand needs to be imported into a user made linked list. 
There is no defined number of strands or number of nucleotides in a strand. (Do not use constants for this!)
The file is loaded via command line argument (included in the provided makefile and driver.cpp). 
All user inputs will be assumed to be the correct data type. For example, if you ask the user for an integer, they will provide an integer.
Regardless of the sample output below, all user input must be validated. If you ask for a number between 1 and 5 with the user entering an 8, the user should be re-prompted.
Have a main menu that asks the user if they want to:
What would you like to do?:
Display Strands
Use Consensus Tool
Mutate Strands
Exit
Upon exit, nothing is saved
Requirements:
Initially, you will have to use the following files LL.h, Sequencer.h, makefile, driver.cpp, and a variety of test input for the project. You can copy the files from Prof. Dixon’s folder at:
/afs/umbc.edu/users/j/d/jdixon/pub/cs202/proj3
To copy it into your project folder, just navigate to your project 3 folder in your home folder and use the command:
cp /afs/umbc.edu/users/j/d/jdixon/pub/cs202/proj3/*.* .
cp /afs/umbc.edu/users/j/d/jdixon/pub/cs202/proj3/makefile .
Notice the trailing period is required (it says copy it into this folder) and you need a second command to copy the makefile (*.* does not copy the makefile).
The project must be completed in C++. You may not use any libraries or data structures that we have not learned in class. Libraries we have learned include <iostream>, <fstream>, <iomanip>, <vector>, <cstdlib>, <time.h>, <cmath> and <string>. You should only use namespace std.
You must use the function prototypes as outlined in the DNA.h and Sequencer.h header file. Do not edit the header files.
There are three test files available. They are proj3_test1.txt, proj3_test2.txt, and proj3_test3.txt. For example, proj3_test1.txt has four strands, each with 6 nucleotides. We should be able to test a file of any size (within reason). We provided test files with 4 strands x 6 nucleotides, 6 strands x 25 nucleotides, and 12 strands x 150 nucleotides.
You need to write the functions for the class (LL.cpp) based on the header file (LL.h). The Nodes for the linked list that you are implementing are structs that hold two pieces of information – a char and a pointer to the next node. This linked list should work for anything that has just a single char as the data (it is not specific to this purpose). Do not use the STL for this project.
LL() – The constructor creates a new empty linked list. m_head and m_tail are always NULL and m_size is zero.
~LL() – The destructor de-allocates any dynamically allocated memory. (May call clear)
Clear() – Clears the linked list.
InsertEnd() – Always inserts new nodes at the end of the linked list.
Display() – Displays each strand in the linked list separated with a -> and terminating with END.
IsEmpty() – Returns if the linked list is empty.
SizeOf() – Populates m_size of the linked list with how many nodes are in the linked list returns m_size
ReplaceData() – Iterates over the linked list and replaces every *quantity* charFrom with charTo For ReplaceData ('A','C', 3) then every third 'A' would be replaced with a 'C'. Limited to 1 to 5.
Overloaded <<() – Returns an ostream with the data from each node separated with a -> and terminating with END.
You need to code up the various functions that are called in the Sequencer.cpp file that are prototyped in Sequencer.h.
Sequencer() – The constructor calls readFile, and calls mainMenu.
~Sequencer() – The destructor de-allocates any dynamically allocated memory. 
ReadFile()– The ReadFile function loads a file of strands of nucleotides into the m_dna vector. Each strand of nucleotides is stored in its own linked list. The file itself is passed to the ReadFile function from the command line (in driver.cpp which is provided). Also, calls SizeOf to populate m_size.
DisplayStrands – Iterates through each strand in m_dna and displays the entire strand with -> between each nucleotide and ending with END
CalculateConsensus – Iterates through each strand to identify the most common nucleotide in that position. One nucleotide will always have a majority. See the example in the project description above for examples.
MutateStrands – Iterates through each strand in m_dna and replaces specific nucleotides (G,C,A,T) at a given interval. For example, asks the user what nucleotide to change from, what nucleotide to change to, and how frequently. So, if the user chose change ‘A’ to ‘C’ every other instance, the strand would replace every other ‘A’ with a ‘C’. The consensus could then change.
MainMenu() – Calls the various functions in the DNA (linked list).
Choices 1 – Calls DisplayStrands
Choice 2 – calls CalculateConsensus
Choice 3 - calls MutateStrand 
Choice 4 - Exits.
