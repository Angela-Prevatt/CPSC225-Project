#include <iostream>
#include <cstdlib>
#include "celestials.h"
using namespace std;

const int SIZE_ROW = 51; //[32,40] pop up window sizes [51,69] Full school computer screen
const int SIZE_COLUMN = 69;


Celestial :: Celestial(int s, int x, int y){
 size=s;
  xCoord=x;
  yCoord=y;
}

void Celestial::screenPrint(string space[51][69]) {
	for (int i = xCoord; i < xCoord + size; i++) {
		for (int j = yCoord; j < yCoord + size; j++) {
			space[i][j] = "\x1b[103m  \x1b[0m";
		}
	}
}


Planet:: Planet(string n){
   name= n;
}

