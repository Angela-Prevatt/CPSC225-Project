/*
Refrences:
How to use ANSI colors: https://jakob-bagterp.github.io/colorist-for-python/ansi-escape-codes/introduction/#sequence-parts
More colors: https://jakob-bagterp.github.io/colorist-for-python/ansi-escape-codes/extended-256-colors/#examples
                           //color        //reset
    //cout << ("I want     \x1b[##m  RED  \x1b[0m     color") << endl;

Multi dimentional arrays: https://www.w3schools.com/cpp/cpp_arrays_multi.asp 

******************************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;


//matrix/game screen size
const int SIZE_ROW = 51; //[32,40] pop up window sizes [51,69] Full school computer screen
const int SIZE_COLUMN = 69;


void printScreen(string matrix[SIZE_ROW][SIZE_COLUMN]) {
    for (int r = 0; r < SIZE_ROW; r++) {
        for (int c = 0; c < SIZE_COLUMN; c++) {
            cout << matrix[r][c];
        }
        cout << "\n";
    }
}



int main()
{ 
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

    //printing with color
    //neptune
    space[25][34] = "\x1b[106m  \x1b[0m ";
    //rocket   >=>
    space[25][24] = "\x1b[31m>=>\x1b[0m";
    
    
    //print
    printScreen(space);
 

    return 0;
}