#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "celestials.h"
using namespace std;

const int SIZE_ROW = 51; //[32,40] pop up window sizes [51,69] Full school computer screen
const int SIZE_COLUMN = 69;



void Celestial::setVals(int s, int x, int y) {
	size = s;
	xCoord = x;
	yCoord = y;
}

Celestial :: Celestial(int s, int x, int y){
	setVals(s, x, y);
}

void Celestial :: screenPrint(string space[51][69])  {
	
	for (int i = xCoord; i < xCoord + size; i++) { //loop for size, will print square of s size starting in x,y corner
		for (int j = yCoord; j < yCoord + size; j++) {
			space[i][j] = "\x1b[103m  \x1b[0m";
		}
	}
}

int Celestial::getS() {
	return size;
}
int Celestial::getX() {
	return xCoord;
}
int Celestial::getY() {
	return yCoord;
}


Planet::Planet(int c) {
	color = c;
}

int Planet::getC() {
	return color;
}

void Planet::screenPrint(string board[51][69]) {
	for (int ii = xCoord; ii < xCoord + size; ii++) { //loop for size, will print square of s size starting in x,y corner
		for (int jj = yCoord; jj < yCoord + size; jj++) {
			switch (color) {
			case 1: //red
			board[ii][jj] = "\x1b[48;5;1m  \x1b[0m";
			break;
			case 2: //orange
				board[ii][jj] = "\x1b[48;5;166m  \x1b[0m";
				break;
			case 3: //purple
				board[ii][jj] = "\x1b[48;5;91m  \x1b[0m";
				break;
			case 4: //blue
				board[ii][jj] = "\x1b[48;5;12m  \x1b[0m";
				break;
			case 5: //green
				board[ii][jj] = "\x1b[48;5;193m  \x1b[0m";
				break;
			case 6: //pink
				board[ii][jj] = "\x1b[48;5;201m  \x1b[0m";
				break;
			
		 default:
				break;
			}
		}
	} 
 }

