#include <iostream>
#include <string>
#include <conio.h>
#include "drawmaze.h"
#include "movement.h"
#include "traps.h"
#include <fstream>

using namespace std;

int main()
{
	string choice; //outputs choices for maze
	system("COLOR 2"); //green
	cout << "1 - Start Maze" << endl;
	cout << "2 - Information about the maze." << endl;
	cout << "3 - Quit." << endl;
	getline(cin, choice);
	if (choice == "1") //if choice is one, will start maze.
	{
		system("COLOR 8"); //grey
		system("cls");
		movement movement1;
		maze maze;
		user player;
		maze.draw_maze();
		cout << "Press 'I' for information about the game." << endl;
		cout << "Press 'E' to exit the game." << endl;
		cout << "Player has " << player.health << " health remaining" << endl;
		cout << endl;

		cout << "Win the game by exiting through the 'D' " << endl;
		cout << endl;

		cout << "Play the game by using: " << endl;
		cout << " W = Up" << endl;
		cout << " A = Left" << endl;
		cout << " S = Down" << endl;
		cout << " D = Right" << endl;

		movement1.move_maze();

	}
	if (choice == "2") //if choice is 2, returns to the main.
	{
		ifstream resource;
		string output;
		resource.open("mazeinfo1.txt");

		while (getline(resource,output)) //outputs a getline so spaces can be used and wont be single words.
		{
			cout << output << endl;
		}
		return main();

	}
	else if (choice == "3") //if choice is 3, exits game.
	{
		exit(EXIT_SUCCESS);
	}


	try {
		if (choice != "3") //If their choice is not 1-3 then throws exception. UPDATED: CHANGE ALL MY INTEGERS INTO STRINGS AND MANAGED TO FIX THIS. NOW DOES NOT ALLOW INPUTS OF ANYTHING OTHER THAN 1-3. WELL DONE KAMAL YOU SMART GUY.
		{
			throw 40;
		}
	}
	catch (int a)
	{
		system("cls");
		return main();
	}


	return 0;
}
