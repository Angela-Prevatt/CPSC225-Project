class Celestial {
  private:
  int size;
  int location;
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
