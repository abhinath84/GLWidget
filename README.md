GLWidget - Object Oriented glut framework

GLWidget class is a abstract class which help user to create
glut window and doing gl related stuff.

Link: https://www.youtube.com/watch?v=MnlknEMjjGw

--------------------------------------------
Example:
--------------------------------------------
game.h
```cpp
class Game: public GLWidget 
{
public:
  Game();
  ~Game();

  virtual void displayGL();

private:
  void drawLineStripLoop_3D();
};
```

main.cpp
```cpp
#include <iostream>
#include "game.h"

using namespace std;

int main(int argc, char **argv)
{
  GLWidget *gameWidget = new Game();
  gameWidget->mainloopGL(argc, argv);
  
  return(0);
}
```
