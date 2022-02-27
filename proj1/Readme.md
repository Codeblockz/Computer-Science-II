# CMSC 202 Fall 2018 <br> Project 1 – State Internet Access <br> Assignment: Project 1 – State Internet Access

**1.	Overview**

In this project, you will:
- Practice basic C++ syntax including branching structures
-	Write a program that calls multiple functions
-	Manage a two-dimensional array
-	Use simple file input/output

**2.	Background**

Computer access and usage has grown considerably since the early 1980s. Only 8 percent of households in 1984 reported owning a computer according to a census of that year. Most adults were just learning to use computers then and they were focused on word processing, video games, and jobs. Just thirty years later, the percentage households with a computer had increased almost tenfold to 79 percent. By 2016, a new study found that 89 percent of households had a computer, making it a common feature of everyday life. Nowadays, people use computers for an even wider range of uses including online banking, entertainment, socializing, and accessing health care. <br>
As part of our US census report, a report titled “Computer and Internet Use in the United States: 2016” looks at access to computers and broadband internet subscriptions nationwide. Differences can be seen by demographic, social and geographic characteristics across the digital divide between those who have and those who lack access to computers and the internet. <br>
For this project, we are going to load data files with data about each of the states (including the District of Columbia) and display data related to that state. Additionally, we will then be using that data to create a simple bar graph displaying the percentages of those values.
The data from the source is included in Table 1. Internet Usage for Individuals 3 and older (2012). You do not need to use this table directly, a data file has been provided to you for the project.<br>

**3.	Assignment Description** <br>
Your assignment is to develop a system to load in two specific demographic data files. The first data file will be used to store the states. The second data file will hold the demographic data. Once those files have been loaded, the data can be displayed and ultimately graphed.
The provided grid of data will be 51 x 4 (you will be expected to calculate the percentages which are not provided).
We will be using a simple column chart to visual the data. The columns should be: Percent of State Population (should always be 100%), Percent of State Population with Individuals that Live in Household with Internet Use, Percent of State Population with Individuals that Access the Internet from Some Location, and Percent of State Population with Individuals that Access the Internet from Home. The data files provided give populations and the actual percentages will need to be calculated.
 
**4.	Requirements:**<br>
This is a list of the requirements of this application. For this project, it is up to you exactly how you want to implement it. For you to earn all the points, however, you will need to meet all the defined requirements.<br>
- You must follow the coding standard as defined in the CMSC 202 coding standards (found on Blackboard under course materials). This includes comments as required.
-	The project must be turned in on time by the deadline listed above.
-	The project must be completed in C++. You may not use any libraries or data structures that we have not learned in class. Libraries we have learned include ```<iostream>```, ```<fstream>```, ```<iomanip>```, ```<cmath>```, ```<cstlib>```, and ```<string>```. You should only use namespace std.
- You must use a variety of functions (at least 5) including passing parameters to those functions and returning information from those functions. At least one time, an array must be passed to a function (although you may do this more than once).
-	The menu must be implemented with a switch statement.
-	All user input must be validated. For example, if a menu allows for 1, 2, or 3 to be entered and the user enters a 4, it will re-prompt the user. However, the user is expected to always enter the correct data type. i.e. If the user is asked to enter an integer, they will. If they are asked to enter a character, they will. You do not need to worry about checking for correct data types.
-	The name of the input file is variable. As a hint, don’t forget that the “open” command requires a c-string. If you want to convert a string to a c-string, you can use the string.c_str() function.
-	The easiest way to implement this project is using two-dimensional arrays (of the same size but of different data types). 
-	Have a main menu that asks if the user wants to:
 - Read in the demographic data files and display them in a formatted way.
 - Display the data for a specific state in a simple bar graph (graph labels are not required).
 - Exit and include a thank you message for the user
- Specific coding requirements include:
 - Must use at least 5 different functions.
 - Must use at least two different arrays.
 - Must pass an array to a function.
 -	Must read in a file into a two-dimensional array.
 -	Must use at least one switch statement.
 -	Must use input validation (assume the data is the correct type).
 - Must use at least one do..while loop.
 - Must use constants as needed.
 - Must use setw to output the tables and graph.<br>
***6.	Sample Input and Output***<br>
For this project, input files are very simple. The first data file is called proj1_states.txt and just includes the state names. 
The second file is all of the demographic data by state. The data is numbered in alphabetical order with the exception of Alaska and Alabama (for some reason the demographic data for Alaska and Alabama is in reverse order). So, 0 is Alaska and 1 in Alabama.
