#include <iostream>
#include <cstdlib>
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

void Celestial::screenPrint(string space[51][69]) {
	
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

