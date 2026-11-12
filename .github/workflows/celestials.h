#include <iostream>
using namespace std;

class Celestial {
  private:
  int size;
  int xCoord;
  int yCoord;
public:
	virtual void screenPrint(string space[51][69]); //virtual since planet will inherit, take space string so it can print
	void setVals(int s, int x, int y);
  Celestial(int s=5, int x=24, int y=24); //makes the sun as default
  ~Celestial(){
	  cout << "destructed" << endl;
  }
int getS();
int getX();
int getY();
};

class Planet: public Celestial{
  public:
  int color;
  void setColor(string);
  Planet(int);
};

