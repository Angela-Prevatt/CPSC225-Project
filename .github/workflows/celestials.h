class Celestial {
  private:
  int size;
  int xCoord;
  int yCoord;
public:
  Celestial();
  ~Celestial();
}

class Planet: public Celestial{
  public:
  int gravity;
  string name;
}

class Comet : public Celestial {
  public:
int speed;
}
