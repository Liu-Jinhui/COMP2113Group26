//menu.cpp

#include <iostream>
#include <string>
#include "menu.h"
using namespace std;

void welcome() {
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "                                                  (๐•ᴗ•๐) Welcome to this game (๐•ᴗ•๐)" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void print_menu() {
	system("clear");
	cout << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "                                                                || Menu ||                            " << endl;
	cout << endl;
	cout << "                                                          _____________________                      " << endl;
	cout << "                                                         |    Regulation (R)   |                    " << endl;
	cout << "                                                          ---------------------                      " << endl;
	cout << endl;
	cout << "                                                          _____________________                     " << endl;
	cout << "                                                         |  Start the game (S) |                    " << endl;
	cout << "                                                          ---------------------                   " << endl;
	cout << endl;
	cout << "                                                          _____________________                      " << endl;
	cout << "                                                         |  Exit the game (E)  |                     " << endl;
	cout << "                                                          ---------------------                      " << endl;
	cout << endl;
	cout << "                                                          _____________________                      " << endl;
	cout << "                                                         |     History (H)     |                     " << endl;
	cout << "                                                          ---------------------                      " << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "▽ Your choice" << endl;
}

void print_regulation() {
	system("clear");
	cout << "						         Introduction of our game" << endl;
	cout << "				This is a game coded by Jinhui Liu and Qingzhu Xie." << endl;
	cout << "				This is a single-player sliding tile puzzle video game." << endl;
	cout << endl;
	cout << "				Every turn, a new tile may randomly appear in an empty spot on the board which is either D or D+." << endl;
	cout << "				The user can select the direction of the sliding of tiles. "
	cout << "				Tiles slide as far as possible in the chosen direction until they are stopped by either another tile or the edge of the grid. " << endl;
	cout << "				If you enter 1, all tiles will move up; If you enter 2, all tiles will move down; If you enter 3, all tiles will move left; If you enter 4, all tiles will move right." << endl;
	cout << "				if you enter “exit”, the game will end." << endl;
	cout << "				If two tiles of the same number collide while moving, they will merge into a tile which is a high level of grade (i.e., D becomes D+). " << endl;
	cout << endl;
	cout << "				You can choose your difficulty of the game. " << endl;
	cout << "				A scoreboard on the upper-right keeps track of your CGPA (under the calculation method of HKU)." << endl;
	cout << "				Your CGPA starts at zero, and is increased whenever two tiles combine, by the GPA of the new tile. " << endl;
	cout << endl;
	cout << "                                                         ENJOY YOUR GAME!!!" << endl;
	
}

void bye() {
	system("clear");
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------    Bye   -------------------------------------------------------------------------------------" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
