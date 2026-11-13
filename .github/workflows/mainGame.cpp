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

11-12-2026
Exception from Marriot Presentations
timer: https://stackoverflow.com/questions/12231166/timing-algorithm-clock-vs-time-in-c
******************************************************************************************/
#include <iostream>
#include <cstdlib>//random function
#include <conio.h>//key presses
#include <chrono>//for game timing
#include<fstream>//for file IO
#include "celestials.h"
#include "StartScreen.h"

using namespace std;
using namespace std::chrono;

//defining each key to make calling easier later
#define keyUp    72
#define keyLeft  75
#define keyRight 77
#define keyDown  80
#define keyEnter 13
#define keyHelp 104

//matrix/game screen size
const int SIZE_ROW = 51; //[32,40] pop up window size, [51,69] Full school computer screen
const int SIZE_COLUMN = 69;

void PrintScreen(string matrix[SIZE_ROW][SIZE_COLUMN]) {
    for (int r = 0; r < SIZE_ROW; r++) {
        for (int c = 0; c < SIZE_COLUMN; c++) {
            cout << matrix[r][c];
        }
        cout << "\n";
    }
}

void checkPlanets(int x, int y, Celestial object)//only works for sun currently
{
    const string MSG = "Rock ship hit orbital body";
	
    //loop goes through each position on sun and makes sure rocket hasn't hit it
    for (int i = object.getX(); i < object.getX() + object.getS(); i++) {
        for (int j = object.getY(); j < object.getY() + object.getS(); j++) {
            if (x == j && y == i)
            {
                throw(MSG);
                cout << "error";
            }
        }
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


        //Celestial bodies

        //sun (make and call print fn)
        Celestial sun(5, 22, 33);
        sun.screenPrint(space);
        //red planet
        Planet red(1);
        red.setVals(1, 34, 30);
        red.screenPrint(space);
        //orange planet(make and call print fn)
        Planet orange(2);
        orange.setVals(4, 10, 10);
        orange.screenPrint(space);
        //purple planet
        Planet purple(3);
        purple.setVals(2, 10, 52);
        purple.screenPrint(space);
        //blue planet
        Planet blue(4);
        blue.setVals(3, 30, 15);
        blue.screenPrint(space);
        //green planet
        Planet green(5);
        green.setVals(6, 44, 60);
        green.screenPrint(space);

		int secretPlanet = rand() % 10 + 1; //10% chance of secret planet appearing
       // int secretPlanet = 1;//for testing
        if (secretPlanet == 1) {
            //pink planet
            Planet pink(6);
            pink.setVals(2, 15, 30);
			pink.screenPrint(space);
        }

        //rocket   >=>
        int xRocketPosition = 25;
        int yRocketPosition = 24;
        space[yRocketPosition][xRocketPosition] = "\x1b[31m>=>\x1b[0m";

		keyPressed = _getch();
            if (keyPressed == keyEnter) {
                PrintScreen(space);
            }
		//starts stopwatch for user
		auto start = high_resolution_clock::now();
	
        //changed to a do-while for project requirments
        bool win = false;
        bool lose = false;
        do
        {
            keyPressed = _getch();
          
            //functionality for removing old rocket    
            space[yRocketPosition][xRocketPosition] = "   ";

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


            try
            {
                checkPlanets(xRocketPosition, yRocketPosition, sun);
            }
            catch (string message)
            {
                cout << message << endl;
                lose = true;
            }

            //prints new rocket
            space[yRocketPosition][xRocketPosition] = "\x1b[31m>=>\x1b[0m";
            PrintScreen(space);
           
        } while (win == false && lose == false);

		//stops stopwach and records time
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(end - start);
	
        system("cls");
        if (lose == true) {
            cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t You have chosen to fly into the sun "<<(duration.count()*0.001)<<" seconds in." << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t              \x1b[31m You lose \x1b[0m  " << endl;
        }

    return 0;
}
