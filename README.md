# COMP2113Group26

A group project for COMP2113 by Xie Qingzhu and Liu Jinhui

## Description of your game and introduction of the game rules

This is a single player sliding tile puzzle video game.User can play on a plain 3×3 / 4×4 / 5×5 grid, with numbered tiles that slide when a player moves them using the four arrow keys. First, the user can choose the difficulty of the game, which means that they can choose whether they play the game based on a 3×3, 4×4 or 5×5 grid. Every turn, a new tile may randomly appear in an empty spot on the board which is either D or D+.

Every time, the user can select the direction of the sliding of tiles. If the user enters 1, all tiles will move up; If the user enters 2, all tiles will move down; If the user enters 3, all tiles will move left; If the user enters 4, all tiles will move right; if you enters “exit”, the game will end. Tiles slide as far as possible in the chosen direction until they are stopped by either another tile or the edge of the grid. If two tiles of the same number collide while moving, they will merge into a tile which is a high level of grade (i.e., D becomes D+). 

A scoreboard on the upper-right keeps track of the user’s CGPA (under the calculation method of HKU). The user's score (CGPA) starts at zero, and is increased whenever two tiles combine, by the GPA of the new tile. 

## Features to implement

## Match code requirement

**Random generation** 
**Data structures** 
**Dynamic memory** 
**File input/output** 
**Multiple files** 

## Non-standard C/C++ libraries

## Compilation and execution instructions
1. In ubuntu or terminal, input

```bash
make main
```

to compile the codes.
2. Then, input 

```bash
./main
```

to execute the program.
3. Enjoy the game.
4. In our game, if you don't want to play the game at this moment, press Exit to quit the game, and your grid will be stored. 
5. To reload the game, input

```bash
./main
```

6. The "[user name].txt" formed after game execution is for the game data. Do not delete this file unless you want to reset the whole program.




> Include game introduction, installation process and menu

For Markdown syntax, please refer to:

[GitHub Guidelines](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)

[Markdown Guide](https://www.markdownguide.org/)
