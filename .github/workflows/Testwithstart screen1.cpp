/*
* Elizabeth Zurybida 11-4-2026
Refrences:
How to use ANSI colors: https://jakob-bagterp.github.io/colorist-for-python/ansi-escape-codes/introduction/#sequence-parts
More colors: https://jakob-bagterp.github.io/colorist-for-python/ansi-escape-codes/extended-256-colors/#examples
                           //color        //reset
    //cout << ("I want     \x1b[##m  RED  \x1b[0m     color") << endl;

Multi dimentional arrays: https://www.w3schools.com/cpp/cpp_arrays_multi.asp 


11-6-2026
Welcome text inspired by Mack's project
ASCII art generated here: https://www.asciiart.eu/text-to-ascii-art
  ________  _______     __       ______    _______
/         )|   __  \   /  \     /  _   \  /       |
(:   \___/ (. |__) :) /    \   (: ( \___)(: ______)
 \___  \   |:  ____/ /' /\  \   \/ \      \/    |
  __/  \\  (|  /    //  __'  \  //  \ _   // ___)_
 /  \   :)/|__/ \  /   /  \\  \(:   _) \ (:       |
(_______/(_______)(___/    \___)\_______) \_______)

 ___________  _______    _______   ______   __   ___
(      _    )/       \  /       | /  _   \ |/ | /   )
 )__/  \\__/|:        |(: ______)(: ( \___)(: |/   /
    \\_ /   |_____/   ) \/    |   \/ \     |    __/
    |.  |    //      /  // ___)_  //  \ _  (// _  \
    \:  |   |:  __   \ (:       |(:   _) \ |: | \  \
     \__|   |__|  \___) \_______) \_______)(__|  \__)
     merlin 1
******************************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;


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

void StartScreen() {

    //5 Line Oblique
    cout << "\t\t\t\t\t\t\t\t\t ||   / |  / /" << endl;
    cout << "\t\t\t\t\t\t\t\t\t ||  /  | / /  ___     //  ___      ___      _   __      ___    " << endl;
    cout << "\t\t\t\t\t\t\t\t\t || / /||/ / //___) ) // //   ) ) //   ) ) // ) )  ) ) //___) )" << endl;
    cout << "\t\t\t\t\t\t\t\t\t ||/ / |  / //       // //       //   / / // / /  / / //" << endl;
    cout << "\t\t\t\t\t\t\t\t\t |  /  | / ((____   // ((____   ((___/ / // / /  / / ((____" << endl;
    cout << "" << endl;
    cout << "\t\t\t\t\t\t\t\t\t  __  ___  ___                             " << endl;
    cout << "\t\t\t\t\t\t\t\t\t    / /   //   ) )                         " << endl;
    cout << "\t\t\t\t\t\t\t\t\t   / /   //   / /                          " << endl;
    cout << "\t\t\t\t\t\t\t\t\t  / /   ((___/ /                          " << endl;
    cout << "\n\n\n\n\n" << endl;

    cout << "\t\t\t\t\t\t\t\t\t\t\t\t \x1b[5m Press enter to begin \x1b[25m  " << endl;
    cout << "\n\n\n\n\n" << endl;

    /*
    while(user has not pressed enter){
    wait
    }
    */
}



int main()
{ 
    StartScreen();
    
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
    //PrintScreen(space);
 

    return 0;
}