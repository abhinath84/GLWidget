GLWidget - Object Oriented glut framework

--------------------------------------------
Example:

class Game: public GLWidget {
public:
  Game();
  ~Game();

  virtual void displayGL();

private:
  void drawLineStripLoop_3D();
};

-------------------------------------------
#include <iostream>
#include "game.h"

using namespace std;

int main(int argc, char **argv)
{
  GLWidget *gameWidget = new Game();
  gameWidget->mainloopGL(argc, argv);

  return(0);
}
