# COMP2113Group26

A group project for COMP2113 by Xie Qingzhu and Liu Jinhui

## Description of your game and introduction of the game rules

This is a single player sliding tile puzzle video game.User can play on a plain 3×3 / 4×4 / 5×5 grid, with numbered tiles that slide when a player moves them using the four arrow keys. First, the user can choose the difficulty of the game, which means that they can choose whether they play the game based on a 3×3, 4×4 or 5×5 grid. Every turn, a new tile may randomly appear in an empty spot on the board which is either D or D+.

Every time, the user can select the direction of the sliding of tiles. If the user enters 1, all tiles will move up; If the user enters 2, all tiles will move down; If the user enters 3, all tiles will move left; If the user enters 4, all tiles will move right; if you enters “exit”, the game will end. Tiles slide as far as possible in the chosen direction until they are stopped by either another tile or the edge of the grid. If two tiles of the same number collide while moving, they will merge into a tile which is a high level of grade (i.e., D becomes D+).

A scoreboard at the bottom keeps track of the user's current GPA and best GPA (under the calculation method of HKU). The user's GPA starts at zero, and will be re-calculated whenever the tiles move.

## Features to implement

1. User specific data saving (File input and output): load user's game data at the beginning of the game and save the data into user_name.txt once the user wants to exit the game.
2. Load game history (File input): use ```ifstream``` of the fstream library to load users previous game history, including playing time and the best scores in those plays.
3. Store a constantly changing game table (Data structures): in this game, we use a 2D vector of type int to store the constantly changing game table.
4. Random generation of new tiles (Generation of random game events): use ```srand(time(NULL))``` in library cstlib and ```rand()``` to collaborately generate new tile at one randomly choosed position in the game table once the user wants to move the tile.
5. Slide the tiles in different directions (Data structures): in the movement functions, we use a 1D vector of int type to merge adjacent positions of the same value in a row/column and store the 1D vector back to the 2D game table.
6. Real time checking of game status (Dynamic memory management; Data structures for storing game status): we use dynamic variable to mark the coordinate of available positions, and store the dynamic variable into a list containg all the available positions.

## Match code requirement

### **Random generation**

Using  ```srand(time(NULL))``` in cstlib and ```rand()``` to collaborately generate new value at one randomly choosed tile in the game table once the user wants to move the tile.

### **Data structures**

1. Using a 2D vector of type int to store the constantly changing game table.

2. Using a 1D vector of int type in the movement functions to merge adjacent positions of the same value in a row/column and store the 1D vector back to the 2D game table.

3. Using a list to store all the available positions in the game table.

### **Dynamic memory**

Using dynamic variables of type position (a user defined structure) to mark the coordinate of available positions in the current game table.

### **File input/output**

1. User specific data saving: Load user's game data at the beginning of the game and save the data into user_name.txt once the user wants to exit the game.

2. Load game history: use ```ifstream``` of the fstream library to load users previous game history, including playing time and the best scores in those plays.

### **Multiple files**

All the functions are stored in related .cpp files rather than main.cpp. Also, corresponding header(.h) files are written in order to cooperate with Makefile to compile successfully.

## Non-standard C/C++ libraries

1. ```#include<cstdio>```: we use the ```remove``` function in function ```void del(string file_name)``` to delete the file temp.txt to achieve the function of edit files which store user's game history.
2. ```#include<ctime>```: we use this library to get the current local time and store it in the game history as a reference for the users. Please refer to the following code block to see the specific use.

```c++
#include<ctime>

time_t rawtime;
time (&rawtime);//get the calender time
cout << ctime (&rawtime);//print a readable string of current local time
```

## Compilation and execution instructions

1. In ubuntu or terminal, input

```bash
git clone https://github.com/Liu-Jinhui/COMP2113Group26.git
```

to download directory from github.

2. Input

```bash
cd COMP2113Group26
```

to attend the game directory.

3. Input

```bash
make main
```

to compile the codes.

4. Input

```bash
./main
```

to execute the program.

5. Enjoy the game.
6. In our game, if you don't want to play the game at this moment, press ```E``` to exit the game, and your grid will be stored.
7. To reload the game, input

```bash
./main
```

8. The "[user name].txt" formed after game execution is for the game data. Do not delete this file unless you want to reset the whole program.

----
For Markdown syntax, please refer to:

[GitHub Guidelines](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)

[Markdown Guide](https://www.markdownguide.org/)
