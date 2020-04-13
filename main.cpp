#include "Game.h"

int main(int argc, char** argv)
{
	char choice;
	char gameModeChoice;
	string fileName;
	string outputFileName;
	int height;
	int width;
	double decimalVal;
	char outputMode;

	cout << "Enter 'p' to provide a map file or 'r' to have a map randomly generated." << endl;
	cin >> choice;
	if(choice == 'p') //for map file
	{
		cout << "Enter a file name: " << endl;
		cin >> fileName;
		cout << "Enter 'p' for a pause, 'e' to hit enter between generations, or 'f' to output to a file" << endl;
		cin >> outputMode;

		if(outputMode == 'f')
		{
			cout << "Enter a file name to be used for output: " << endl;
			cin >> outputFileName;
		}
		
		cout << "Enter 'c' for classic, 'd' for donut, or 'm' for mirror mode: "<<endl;
		cin >> gameModeChoice;
		Game myGame(fileName);
		myGame.setOutFileName(outputFileName);
		if(gameModeChoice == 'c')
		{
			myGame.playClassic(outputMode);
		}
		else if(gameModeChoice == 'd')
		{
			myGame.playDonut(outputMode);
		}
		else
		{
			myGame.playMirror(outputMode);
		}
		

	}
	else //for random world with specified height, width, and decimal value
	{
		cout << "Enter how tall you want the world to be: " << endl;
		cin >> height;
		
		cout << "Enter how wide you want the world to be: " << endl;
		cin >> width;
		
		cout << "Enter a decimal value (greater than zero and less than one) to represent the initial population density of the world" << endl;
		cin >> decimalVal;
		cout << "Enter 'p' for a pause, 'e' to hit enter between generations, or 'f' to output to a file" << endl;
		cin >> outputMode;

		if(outputMode == 'f')
		{
			cout << "Enter a file name to be used for output: " << endl;
			cin >> outputFileName;
		}
		
		cout << "Enter 'c' for classic, 'd' for donut, or 'm' for mirror mode: "<<endl;
		cin >> gameModeChoice;
		Game myGame(height, width, decimalVal, outputMode);
		myGame.setOutFileName(outputFileName);
		if(gameModeChoice == 'c')
		{
			myGame.playClassic(outputMode);
		}
		else if(gameModeChoice == 'd')
		{
			myGame.playDonut(outputMode);
		}
		else
		{
			myGame.playMirror(outputMode);
		}
		
	}


	
}