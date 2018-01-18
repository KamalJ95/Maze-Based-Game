#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "drawmaze.h"
#include "traps.h"
#include "key.h"
#include <fstream>
using namespace std;


struct movement
{
	char keystroke;
	void moveXY(int x, int y) //movement function
	{
		COORD move; //defines the co-ordinates of a character cell. Named movement
		move.X = x; //movement starting position of x is 0.
		move.Y = y; //movenent starting position of y of y is 0.
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), move); //sets the cursor position of movement
	}

	//Movement for first maze
	void move_maze() //FUNCTION for movement
	{
		maze mazearray;
		user player;
		traps trap;
		traps trap2;
		traps trap3;
		traps trap4;
		key key1;
		key1.keyacquired = false;
		int x = 1; //sets x at 1 and will set previous x at 1
		int y = 1; //sets y at 1, prev y will be 1
		int xprev = 1;
		int yprev = 1;
		while (true) //loop the maze
		{
			moveXY(xprev, yprev); //makes sure nothing is output when moving forwards
			cout << " "; //doesnt output anything when moving forward

			moveXY(x, y); //which ASCII char I will use for the moving
			cout << player.symbol;

			keystroke = _getch(); //keystroke gets character, read a char from the screen
			xprev = x;
			yprev = y;

			if (keystroke == 'w' ||  keystroke == 'W') //if w is selected, move y-1 which is up.
				y -= 1;
			else if (keystroke == 's' || keystroke == 'S') //if s is selected, move y+1 which is down
				y += 1;
			else if (keystroke == 'a' || keystroke == 'A') // if a is selected, move x-1 which will be left
				x -= 1;
			else if (keystroke == 'd' ||  keystroke == 'D') //if d is selected, move x+1 which will be right
				x += 1;

			if (keystroke == 'i' ||  keystroke == 'I')
			{
				system("cls");
				ifstream resource;
				string output;
				resource.open("mazeinfo1.txt");

				while (getline(resource, output)) //outputs a getline so spaces can be used and wont be single words.
				{
					cout << output << endl;
				}
				system("pause");
				system("cls"); //After information is done, reprints out the game with same elements as before.
				mazearray.draw_maze();
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
			}
			if (keystroke == 'e' || keystroke == 'E') //If keystroke is exit symbol.
			{
				system("cls");
				char input;

					cout << "Are you sure you want to exit (Y/N) ?" << endl;
					cin >> input; //Allows user input or yes or no.
					if (input == 'Y' || input == 'y')
					{
						break; //if yes, breaks out of game back to main menu
					}
					if (input == 'n' || input == 'N') //if no, then redraws the maze out.
					{
						system("pause");
						system("cls");
						mazearray.draw_maze();
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
				}
		
			}

			if (mazearray.mazearray[y][x] == 1)  //enforces collision
			{
				x = xprev;
				y = yprev;
			}
			if (mazearray.mazearray[y][x] == 2) //First fake key
			{
				mazearray.mazearray[y][x] = 0;
				system("cls");
				cout << "That was a fake key!" << endl;
				system("pause");
				system("cls");
				mazearray.draw_maze();
				cout << "Fake keys are scattered throughout the maze." << endl;
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


			}
			if (mazearray.mazearray[y][x] == 3 && trap.dead == true) //First trap, removes player health, redraws maze with trap dead using a mazearray y x is 0.
			{
				system("cls");
				cout << "You stepped on a trap! You take 1 damage! " << endl;
				system("pause");
				system("cls");
				mazearray.mazearray[y][x] = 0;
				player.health = player.health - 1;
				system("cls");
				mazearray.draw_maze();
				trap.dead = false;
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

			}
			if (mazearray.mazearray[y][x] == 4 && trap2.dead == true) //second trap in the maze.
			{
				mazearray.mazearray[y][x] = 0;
				player.health = player.health - 1;
				system("cls");
				mazearray.draw_maze();
				trap2.dead = false;
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

			}
			if (mazearray.mazearray[y][x] == 5 && trap3.dead == true) //Third trap in the maze.
			{
				mazearray.mazearray[y][x] = 0;
				player.health = player.health - 1;
				system("cls");
				mazearray.draw_maze();
				trap3.dead = false;
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

			}
			if (mazearray.mazearray[y][x] == 6) //Second fake key, blows up and deals damage.
			{
				mazearray.mazearray[y][x] = 0;
				player.health = player.health - 1;
				system("cls");
				cout << "The fake key blows up on you and you lose health!" << endl;
				system("pause");
				system("cls");
				mazearray.draw_maze();
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

			}
			if (mazearray.mazearray[y][x] == 7 && trap4.dead == true) // Fourth trap in the game, protects real key to finish maze. deals high damage.
			{
				mazearray.mazearray[y][x] = 0;
				player.health = player.health - 2;
				system("cls");
				mazearray.draw_maze();
				trap4.dead = false;
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

			}
			if (mazearray.mazearray[y][x] == 8) //outputs text scene.
			{
				mazearray.mazearray[y][x] = 0;
				system("cls");
				cout << "The air suddenly turns cold. The trap ahead feels like it will deal more damage than other traps." << endl;
				cout << "You should be careful." << endl;
				system("pause");
				system("cls");
				mazearray.draw_maze();
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

			}
			if (mazearray.mazearray[y][x] == 9) //Real key, will say key1 is true and so the following settings will unlock maze door to finish maze.
			{
				mazearray.mazearray[y][x] = 0;
				system("cls");
				cout << "You have found a key that seems real! You hear a door in the distance open!" << endl;
				system("pause");
				system("cls");
				mazearray.draw_maze();
				key1.keyacquired = true;
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

			}
			if (mazearray.mazearray[y][x] == 10 && key1.keyacquired == false) //if key is not acquired, there will be collision with the door
			{
				x = xprev;
				y = yprev;
			}

			if (mazearray.mazearray[y][x] == 10 && key1.keyacquired == true) //if key is true, collision doesn't exist and maze can be finished.
			{
				system("cls");
				cout << " Well done on completing the maze! Thank you for playing! " << endl;
				cout << " Final Project - Maze Based Game - 2." << endl;
				cout << " Made by Kamal Jahah." << endl;
				system("pause");
				break;

			}
			if (mazearray.mazearray[y][x] == 11) //health pack for player. may be needed for the end if they have accidently lost too many lives.
			{
				mazearray.mazearray[y][x] = 0;
				player.health = player.health + 1;
				system("cls");
				cout << " You found a health pack! " << endl;
				system("pause");
				system("cls");
				mazearray.draw_maze();
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

			}
			if (player.health <= 0) //if player health is less than 0.
			{
				x = 1;
				y = 1;
				system("cls");
				cout << "You have died!" << endl;
				break;
			}
			try //First exception error. Will run an error if user can somehow get into the borders of the maze.
				{
				if (mazearray.mazearray[y][x] == 1)
				{
				throw 10;
				}
				}
				catch (int x)
				{
					cout << "You cannot be in the borders of the game. ERROR NUMBER: " << x << endl; //Error number 10. Will throw error 10 and redraw the maze.
					system("pause");
					system("cls");
					break;
				}
			try //Second exception error, will run an error if user somehow has less than -0 health.
				{
					if (player.health < 0)
					{
						throw 20;
					}
				}
				catch (int y)
				{
					cout << "You cannot have less than 0 health. ERROR NUMBER: " << y << endl; //Error number 20. Throws error 20, redraws the maze. Hopefully this wont need to be done.
					system("pause");
					system("cls");
					break;
				}
			try //Third exception error, runs error is health exceeds 4.
				{
				if (player.health > 4) //Just a test to prove that the error handling is working. Maze now changed so player cannot have more than 4 health somehow.
				{
					throw 30;
					}
				}
			catch (int z)
			{
				system("cls");
				cout << "Health cannot exceed 4. ERROR NUMBER: " << z << endl;
				system("pause");
				system("cls");
				break;
			}

		}
	}
};
#pragma once
