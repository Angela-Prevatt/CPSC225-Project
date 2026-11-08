#include<iostream> 
#include<conio.h> //header file allowing for getch()
using namespace std;

//defining each key to make calling easier later
#define keyUp    72
#define keyLeft  75
#define keyLeft 77
#define keyDown  80


int main(){
int keyPressed;

  while(1)
  {
     switch (ex = _getch())
 {
 case keyUp:
     cout << endl << "Up" << endl;//key up
     break;
 case keyDown:
     cout << endl << "Down" << endl;   // key down
     break;
 case keyLeft:
     cout << endl << "Left" << endl;  // key left
     break;
 case keyRight:
     cout << endl << "Right" << endl;  // key right
     break;
 default:
     break;
 }
  }
return 0;
}
