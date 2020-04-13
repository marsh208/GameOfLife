#include "Game.h"


int height;
int width;
char ** gameBoard;
char ** nextGenBoard;
string outFileName;
ofstream outputFile(outFileName);



Game::Game()
{
	height = 0;
	width = 0;
	popDensity = 0;
	genNumber = 0;
}

//initializes board and nextGenBoard based on given height, length, and density
Game::Game(int tall, int wide, double density, char outputMode)
{
	height = tall;
	width = wide;
	popDensity = density;
	double r;
	genNumber = 0;
	srand(time(NULL));


	gameBoard = new char*[height];
	nextGenBoard = new char*[height];

  	for(int i = 0; i < width; ++i)
  	{
  		gameBoard[i] = new char[width];
  		nextGenBoard[i] = new char[width];
  	}

	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			r = ((double) rand() / (RAND_MAX));
			if(r < density)
			{
				gameBoard[i][j] = 'X';
				nextGenBoard[i][j] = 'X';
			}
			else
			{
				gameBoard[i][j] = '-';
				nextGenBoard[i][j] = '-';

			}

		}
	}



	if(outputMode == 'f')
	{
		printBoard('f');
	}
	else if(outputMode == 'p')
	{
		printBoard('p');
	}
	else
	{
		if(cin.get() == '\n')
			{
				printBoard('e');
			}
			else
			{
				printBoard('e');
			}
	}

}

//initializes board and nextGenBoard based on file input
Game::Game(string fileName)
{

	string line;
	int counter = 0;
	ifstream mapFile(fileName);


	cout << 0 << endl;
	getline(mapFile, line);
	stringstream geek(line);
	geek >> height;

	getline(mapFile, line);
	stringstream geek1(line);
	geek1 >> width;

	gameBoard = new char*[height];
	nextGenBoard = new char*[width];

	for(int i = 0; i < width; ++i)
  	{
  		gameBoard[i] = new char[width];
  		nextGenBoard[i] = new char[width];
  	}

  	for(int i = 0; i < height; ++i)
  	{
  		getline(mapFile, line);
  		cout << line << endl;
  		for(int j = 0; j < width; ++j)
  		{
  			gameBoard[i][j] = ((char)line[j]);
  			nextGenBoard[i][j] = ((char)line[j]);
  		}
  	}


}




Game::~Game()
{
	cout << "Object Deleted";
}

int Game::playClassic(char outputMode)
{
	int numNeighbors = 0;

	while(true)
	{

		for(int i = 0; i < height; ++i)
		{

			for(int j = 0; j < width; ++j)
			{
				numNeighbors = 0;


				//check corner spaces
				if(i == 0 && j == 0) //top left corner
				{
					if(gameBoard[0][1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[1][0] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[1][1] == 'X')
					{
						numNeighbors++;
					}
				}
				else if(i == (height-1) && j == 0) //bottom left corner
				{
					if(gameBoard[i-1][0] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j+1] == 'X')
					{
						numNeighbors++;
					}
				}
				else if(i == 0 && j == (width - 1)) //top right corner
				{
					if(gameBoard[i][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j] == 'X')
					{
						numNeighbors++;
					}
				}
				else if(i == (height-1) && j == (width - 1)) //bottom right corner
				{
					if(gameBoard[i-1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j-1] == 'X')
					{
						numNeighbors++;
					}
				}

				//check left column, not including corners
				else if((i > 0 && i < height - 1) && j == 0)
				{
					if(gameBoard[i-1][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j] == 'X')
					{
						numNeighbors++;
					}
				}
				//check right column, not including corners
				else if((i > 0 && i < height - 1) && j == width - 1)
				{
					if(gameBoard[i-1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j] == 'X')
					{
						numNeighbors++;
					}
				}

				//check top row, not including corners
				else if((j > 0 && j < width - 1) && i == 0)
				{
					if(gameBoard[i][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j+1] == 'X')
					{
						numNeighbors++;
					}
				}

				//check bottom row, not including corners
				else if((j > 0 && j < width - 1) && i == (height-1))
				{
					if(gameBoard[i-1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j+1] == 'X')
					{
						numNeighbors++;
					}
				}


				//check all spaces not on the border of the board
				else if(i > 0 && i < (height - 1) && j > 0 && (j < width - 1))
				{
					numNeighbors += numMiddleNeighbors(i,j);
				}


				//checks for number of neighbors in the space and fills nextGenBoard appropriately
				fillNextGenBoard(i,j,numNeighbors);
			}
		}


		if(genNumber > 0 && checkSimDone() == 1)
		{
			cout << "Simulation is done!";
			break;
		}

		setBoardsEqual();



		//check for output mode
		if(genNumber > 0 && outputMode == 'p')
		{
			this_thread::sleep_for(chrono::seconds(2));
			printBoard('p');
		}
		else if(genNumber > 0 && outputMode == 'e')
		{
			if(cin.get() == '\n')
			{
				printBoard('e');
				continue;
			}
			else
			{
				printBoard('e');
				continue;
			}
		}
		else
		{
			printBoard('f');
			continue;
		}


	}
	return 0;
}
int Game::playDonut(char outputMode)
{
	int numNeighbors = 0;
	while(true)
	{

		for(int i = 0; i < height; ++i)
		{

			for(int j = 0; j < width; ++j)
			{
				numNeighbors = 0;

				//check corner spaces
				if(i == 0 && j == 0) //top left corner
				{
					if(gameBoard[0][1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[1][0] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[1][1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[0][width-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[1][width-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[height-1][0] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[height-1][1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[height-1][width-1] == 'X')
					{
						numNeighbors++;
					}
				}
				else if(i == (height-1) && j == 0) //bottom left corner
				{
					if(gameBoard[i-1][0] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[0][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[0][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[0][width-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][width-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[height-1][width-1] == 'X')
					{
						numNeighbors++;
					}
				}
				else if(i == 0 && j == (width - 1)) //top right corner
				{
					if(gameBoard[i][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][0] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][0] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[height-1][0] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[height-1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[height-1][j] == 'X')
					{
						numNeighbors++;
					}
				}
				else if(i == (height-1) && j == (width - 1)) //bottom right corner
				{
					if(gameBoard[i-1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[0][0] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[0][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[0][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][0] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][0] == 'X')
					{
						numNeighbors++;
					}
				}

				//check left column, not including corners
				else if((i > 0 && i < height - 1) && j == 0)
				{
					if(gameBoard[i-1][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][width-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][width-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][width-1] == 'X')
					{
						numNeighbors++;
					}
				}
				//check right column, not including corners
				else if((i > 0 && i < height - 1) && j == width - 1)
				{
					if(gameBoard[i-1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][0] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][0] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][0] == 'X')
					{
						numNeighbors++;
					}
				}

				//check top row, not including corners
				else if((j > 0 && j < width - 1) && i == 0)
				{
					if(gameBoard[i][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[height-1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[height-1][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[height-1][j+1] == 'X')
					{
						numNeighbors++;
					}
				}

				//check bottom row, not including corners
				else if((j > 0 && j < width - 1) && i == (height-1))
				{
					if(gameBoard[i-1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[0][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[0][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[0][j+1] == 'X')
					{
						numNeighbors++;
					}
				}

				//check all spaces not on the border of the board
				else if(i > 0 && i < (height - 1) && j > 0 && (j < width - 1))
				{
					numNeighbors += numMiddleNeighbors(i,j);
				}

				//checks for number of neighbors in the space and fills nextGenBoard appropriately
				fillNextGenBoard(i,j,numNeighbors);

			}
		}

		if(genNumber > 0 && checkSimDone() == 1)
		{
			cout << "Simulation is done!";
			break;
		}

		setBoardsEqual();

		//check for output mode
		if(genNumber > 0 && outputMode == 'p')
		{
			this_thread::sleep_for(chrono::seconds(2));
			printBoard('p');
		}
		else if(genNumber > 0 && outputMode == 'e')
		{
			if(cin.get() == '\n')
			{
				printBoard('e');
				continue;
			}
			else
			{
				printBoard('e');
				continue;
			}
		}
		else
		{
			printBoard('f');
			continue;
		}
	}

	return 0;
}


int Game::playMirror(char outputMode)
{
	int numNeighbors = 0;

	while(true)
	{

		for(int i = 0; i < height; ++i)
		{

			for(int j = 0; j < width; ++j)
			{
				numNeighbors = 0;


				//check corner spaces
				if(i == 0 && j == 0) //top left corner
				{
					if(gameBoard[0][1] == 'X')
					{
						numNeighbors+=2;
					}
					if(gameBoard[1][0] == 'X')
					{
						numNeighbors+=2;
					}
					if(gameBoard[1][1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j] == 'X')
					{
						numNeighbors+=3;
					}
				}
				else if(i == (height-1) && j == 0) //bottom left corner
				{
					if(gameBoard[i-1][0] == 'X')
					{
						numNeighbors+=2;
					}
					if(gameBoard[i-1][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j+1] == 'X')
					{
						numNeighbors+=2;
					}
					if(gameBoard[i][j] == 'X')
					{
						numNeighbors+=3;
					}
				}
				else if(i == 0 && j == (width - 1)) //top right corner
				{
					if(gameBoard[i][j-1] == 'X')
					{
						numNeighbors+=2;
					}
					if(gameBoard[i+1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j] == 'X')
					{
						numNeighbors+=2;
					}
					if(gameBoard[i+1][j] == 'X')
					{
						numNeighbors+=3;
					}
				}
				else if(i == (height-1) && j == (width - 1)) //bottom right corner
				{
					if(gameBoard[i-1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][j] == 'X')
					{
						numNeighbors+=2;
					}
					if(gameBoard[i][j-1] == 'X')
					{
						numNeighbors+=2;
					}
					if(gameBoard[i][j] == 'X')
					{
						numNeighbors+=3;
					}
				}

				//check left column, not including corners
				else if((i > 0 && i < height - 1) && j == 0)
				{
					if(gameBoard[i-1][j] == 'X')
					{
						numNeighbors+=2;
					}
					if(gameBoard[i-1][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j] == 'X')
					{
						numNeighbors+=2;
					}
					if(gameBoard[i][j] == 'X')
					{
						numNeighbors++;
					}
				}
				//check right column, not including corners
				else if((i > 0 && i < height - 1) && j == width - 1)
				{
					if(gameBoard[i-1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][j] == 'X')
					{
						numNeighbors+=2;
					}
					if(gameBoard[i][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j] == 'X')
					{
						numNeighbors+=2;
					}
					if(gameBoard[i+1][j] == 'X')
					{
						numNeighbors++;
					}
				}

				//check top row, not including corners
				else if((j > 0 && j < width - 1) && i == 0)
				{
					if(gameBoard[i][j-1] == 'X')
					{
						numNeighbors+=2;
					}
					if(gameBoard[i][j+1] == 'X')
					{
						numNeighbors+=2;
					}
					if(gameBoard[i+1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i+1][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j] == 'X')
					{
						numNeighbors++;
					}
				}

				//check bottom row, not including corners
				else if((j > 0 && j < width - 1) && i == (height-1))
				{
					if(gameBoard[i-1][j-1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][j] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i-1][j+1] == 'X')
					{
						numNeighbors++;
					}
					if(gameBoard[i][j-1] == 'X')
					{
						numNeighbors+=2;
					}
					if(gameBoard[i][j+1] == 'X')
					{
						numNeighbors+=2;
					}
					if(gameBoard[i][j] == 'X')
					{
						numNeighbors++;
					}
				}


				//check all spaces not on the border of the board
				else if(i > 0 && i < (height - 1) && j > 0 && (j < width - 1))
				{
					numNeighbors += numMiddleNeighbors(i,j);
				}


				//checks for number of neighbors in the space and fills nextGenBoard appropriately
				fillNextGenBoard(i,j,numNeighbors);
			}
		}


		if(genNumber > 0 && checkSimDone() == 1)
		{
			cout << "Simulation is done!";
			break;
		}

		setBoardsEqual();



		//check for output mode
		if(genNumber > 0 && outputMode == 'p')
		{
			this_thread::sleep_for(chrono::seconds(2));
			printBoard('p');
		}
		else if(genNumber > 0 && outputMode == 'e')
		{
			if(cin.get() == '\n')
			{
				printBoard('e');
				continue;
			}
			else
			{
				printBoard('e');
				continue;
			}
		}
		else
		{
			printBoard('f');
			continue;
		}
	}

	return 0;
}

//checks number of neighbors for each space and fills nextGenBoard respectively
void Game::fillNextGenBoard(int x, int y, int totNeighbors)
{
	int i = x;
	int j = y;
	if(totNeighbors <= 1)
	{
		nextGenBoard[i][j] = '-';
	}
	else if(totNeighbors == 3)
	{
		if(gameBoard[i][j] == '-')
		{
			nextGenBoard[i][j] = 'X';
		}
	}
	else if(totNeighbors > 3)
	{
		nextGenBoard[i][j] = '-';
	}
}

//counts numNeighbors for all middle spaces (same for each game mode)
int Game::numMiddleNeighbors(int x, int y)
{
	int i = x;
	int j = y;
	int numMidNeighbors = 0;
	if(gameBoard[i-1][j-1] == 'X')
	{
		numMidNeighbors++;
	}
	if(gameBoard[i-1][j] == 'X')
	{
		numMidNeighbors++;
	}
	if(gameBoard[i-1][j+1] == 'X')
	{
		numMidNeighbors++;
	}
	if(gameBoard[i][j-1] == 'X')
	{
		numMidNeighbors++;
	}
	if(gameBoard[i][j+1] == 'X')
	{
		numMidNeighbors++;
	}
	if(gameBoard[i+1][j-1] == 'X')
	{
		numMidNeighbors++;
	}
	if(gameBoard[i+1][j] == 'X')
	{
		numMidNeighbors++;
	}
	if(gameBoard[i+1][j+1] == 'X')
	{
		numMidNeighbors++;
	}

	return numMidNeighbors;

}


//prints board and generation number either to the screen or to a file
void Game::printBoard(char mode)
{

	if(mode == 'p' || mode == 'e')
	{

		cout << genNumber << endl;
		genNumber++;
		for(int i = 0; i < height; ++i)
		{
			for(int j = 0; j < width; ++j)
			{
				if(j == (width - 1))
				{
					cout << gameBoard[i][j] << endl;

				}
				else
				{
					cout << gameBoard[i][j];
				}

			}
		}
	}

	else if(mode == 'f')
	{
		outputFile << genNumber << endl;
		genNumber++;
		for(int i = 0; i < height; ++i)
		{
			for(int j = 0; j < width; ++j)
			{
				if(j == (width - 1))
				{
					outputFile << gameBoard[i][j] << '\n';

				}
				else
				{
					outputFile << gameBoard[i][j];
				}
			}
		}
	}
}

//sets gameBoard to equal nextGenBoard
void Game::setBoardsEqual()
{
	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			gameBoard[i][j] = nextGenBoard[i][j];
		}
	}
}


//checks if game board is the same as nextGenBoard and if so, return 1
int Game::checkSimDone()
{
	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			if(gameBoard[i][j] != nextGenBoard[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}

void Game::setOutFileName(string name)
{
	outFileName = name;
	return;
}
