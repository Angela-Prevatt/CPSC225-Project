/*
*
Refrences:
How to use ANSI colors: https://jakob-bagterp.github.io/colorist-for-python/ansi-escape-codes/introduction/#sequence-parts
More colors: https://jakob-bagterp.github.io/colorist-for-python/ansi-escape-codes/extended-256-colors/#examples
                           //color        //reset
    //cout << ("I want     \x1b[##m  RED  \x1b[0m     color") << endl;

Multi dimentional arrays: https://www.w3schools.com/cpp/cpp_arrays_multi.asp


11-6-2026
Welcome text inspired by Mack's project
ASCII art generated here: https://www.asciiart.eu/text-to-ascii-art

11-10-2026
Working out how to clear screen
https://www.geeksforgeeks.org/cpp/how-to-clear-console-in-cpp/
******************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <conio.h>

#include "StartScreen.h"
//#include "celestials.h"
using namespace std;

//defining each key to make calling easier later
#define keyUp    72
#define keyLeft  75
#define keyRight 77
#define keyDown  80
#define keyEnter 13

//matrix/game screen size
const int SIZE_ROW = 51; //[32,40] pop up window sizes [51,69] Full school computer screen
const int SIZE_COLUMN = 69;


void PrintScreen(string matrix[SIZE_ROW][SIZE_COLUMN]) {
    for (int r = 0; r < SIZE_ROW; r++) {
        for (int c = 0; c < SIZE_COLUMN; c++) {
            cout << matrix[r][c];
        }
        cout << "\n";
    }
}


int main()
{
    StartScreen();
    int keyPressed;

    string space[SIZE_ROW][SIZE_COLUMN];
    int row, column;

    //makes random variables truely random
    srand(time(0));

    //fills in game screen with three spaces in each position
    for (row = 0; row < SIZE_ROW; row++) {
        for (column = 0; column < SIZE_COLUMN; column++) {

            //randomly adds a star occationally
            if (rand() % 11 == 1) {
                space[row][column] = " * ";
            }
            else {
                space[row][column] = "   ";
            }
        }
    }


    //Planets

    //sun
    for (int i = 22; i < 29; i++) {
        for (int j = 33; j < 40; j++) {
            space[i][j] = "\x1b[103m  \x1b[0m";
        }
    }
    // space[24][34] = "\x1b[103m  \x1b[0m ";

     //mercury
    space[23][44] = "\x1b[43m  \x1b[0m ";
    //Earth
    space[23][44] = "\x1b[43m  \x1b[0m ";


    //rocket   >=>
    int xRocketPosition = 25;
    int yRocketPosition = 24;
    space[yRocketPosition][xRocketPosition] = "\x1b[31m>=>\x1b[0m";


    //chnaged to a do -while for project requirments
    bool win = false;
    bool lose = false;
    do
    {
        keyPressed = _getch();
        if (keyPressed == keyEnter) {
            PrintScreen(space);
        }

        //functionality for removing old rocket
        space[yRocketPosition][xRocketPosition] = "\x1b[30m>=>\x1b[0m";

        //chooses position for new rocket
        switch (keyPressed)
        {
        case keyUp:
            //move rocket up
            yRocketPosition--;
            break;
        case keyDown:
            //move rocket down
            yRocketPosition++;
            break;
        case keyLeft:
            //move rocket left
            xRocketPosition--;
            break;
        case keyRight:
            //move rocket right
            xRocketPosition++;
            break;
        default:
            break;
        }

        if(yRocketPosition==22 && xRocketPosition ==33){
          //throw("You died");
            lose == true;
            break;
         }


        //clears screen
        system("cls");

        //prints new rocket
        space[yRocketPosition][xRocketPosition] = "\x1b[31m>=>\x1b[0m";
        PrintScreen(space);

    } while (win == false);
    system("cls");
    if (lose == true) {
        cout << "loser";
    }
  
    return 0;
}
