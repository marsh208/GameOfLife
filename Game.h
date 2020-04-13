#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <thread>
#include <chrono>
#include <sstream>


using namespace std;

class Game
{
	public:
		Game();
		Game(int height, int width, double density, char outputMode); //randomly generates starting board
		Game(string fileName); //takes in starting board
		~Game();
		int playClassic(char outputMode);
		int playDonut(char outputMode);
		int playMirror(char outputMode);
		void printBoard(char mode);
		void setBoardsEqual();
		int checkSimDone();
		int numMiddleNeighbors(int x, int y);
		void fillNextGenBoard(int x, int y, int totNeighbors);
		void setOutFileName(string name);
		int height;
		int width;
		double popDensity;
		int genNumber;
		char ** gameBoard;
		char ** nextGenBoard;
		ifstream mapFile;
		ifstream outFile;
	
};