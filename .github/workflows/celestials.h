#include <iostream>
using namespace std;

class Celestial {
  private:
  int size;
  int xCoord;
  int yCoord;
public:
	virtual void screenPrint(string space[51][69]);
  Celestial(int s=5, int x=24, int y=24);
  ~Celestial(){
	  cout << "destructed" << endl;
  }
};

class Planet: public Celestial{
  public:
  int gravity;
  string name;
  Planet(string);
};

class Comet : public Celestial {
  public:
int speed;
};
