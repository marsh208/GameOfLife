Jayson Marshall
Student ID: 2268973
Email: marsh208@mail.chapman.edu
CPSC 350-01
Assignment 2 - Game of Life

Compile and Run with...
g++ *.cpp
./a.out

Source Files:
-main.cpp
-Game.h
-Game.cpp

KNOWN BUGS:
-The program was all running correctly in every combination of each mode. Then I realized that the user should be able to choose an output file name (previously called sim.txt) so I tried to add that functionality without saving the previous version.
This caused a bug:
	-When trying to send the output to a file with name of user's choice, it prints the initial generation to the screen and then does not make the file 
