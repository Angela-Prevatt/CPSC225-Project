#include <iostream>
#include <fstream> 
#include <string>
#include <conio.h> //key presses
#include "printClues.h"
using namespace std;

int keyPressed;
#define keyEnter 13


void printClues(int color) {

	ifstream fin("planets.txt");
    string line;
    int count = 0;
    switch (color)
    {
    case 1:
        //ignores till desired line
        for (int i = 1; i < 2; ++i) {
            if (!fin.ignore(numeric_limits<streamsize>::max(), '\n')) {
                cerr << "File has fewer than " << 1 << " lines.\n";
            }
        }
        //reads and prints text
        cout << "Your clues are..." << endl;
        while (getline(fin, line) && count < 3) {
            cout << line << '\n';
            count++;
        }
        fin.close();

        break;
    case 2:
        //ignores till desired line
        for (int i = 1; i < 8; ++i) {
            if (!fin.ignore(numeric_limits<streamsize>::max(), '\n')) {
                cerr << "File has fewer than " << 1 << " lines.\n";
            }
        }
        //reads and prints text
        cout << "Your clues are..." << endl;
        while (getline(fin, line) && count < 3) {
            cout << line << '\n';
            count++;
        }
        fin.close();

        break;
    case 3:
        //ignores till desired line
        for (int i = 1; i < 15; ++i) {
            if (!fin.ignore(numeric_limits<streamsize>::max(), '\n')) {
                cerr << "File has fewer than " << 1 << " lines.\n";
            }
        }
        //reads and prints text
        cout << "Your clues are..." << endl;
        while (getline(fin, line) && count < 3) {
            cout << line << '\n';
            count++;
        }
        fin.close();

        break;
    case 4:
        //ignores till desired line
        for (int i = 1; i < 21; ++i) {
            if (!fin.ignore(numeric_limits<streamsize>::max(), '\n')) {
                cerr << "File has fewer than " << 1 << " lines.\n";
            }
        }
        //reads and prints text
        cout << "Your clues are..." << endl;
        while (getline(fin, line) && count < 3) {
            cout << line << '\n';
            count++;
        }
        fin.close();
        break;
    case 5:
        //ignores till desired line
        for (int i = 1; i < 27; ++i) {
            if (!fin.ignore(numeric_limits<streamsize>::max(), '\n')) {
                cerr << "File has fewer than " << 1 << " lines.\n";
            }
        }
        //reads and prints text
        cout << "Your clues are..." << endl;
        while (getline(fin, line) && count < 3) {
            cout << line << '\n';
            count++;
        }
        fin.close();
        break; 
    case 6:
        //ignores till desired line
        for (int i = 1; i < 33; ++i) {
            if (!fin.ignore(numeric_limits<streamsize>::max(), '\n')) {
                cerr << "File has fewer than " << 1 << " lines.\n";
            }
        }
        //reads and prints text
        cout << "Your clues are..." << endl;
        while (getline(fin, line) && count < 3) {
            cout << line << '\n';
            count++;
        }
        fin.close();
            break;
    default:
        cout << "error";
        break;
    }

    cout << "\t\t\t\t\t\t\t\t\t\t\t\t \x1b[5m Press enter to continue \x1b[25m  " << endl;//blinky text
    keyPressed = _getch();
    if (keyPressed == keyEnter ) {
 
    }

}

