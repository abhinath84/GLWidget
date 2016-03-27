/*
 * game.h
 *
 *  Created on: 25-Mar-2016
 *      Author: abhi
 */

#ifndef GAME_H_
#define GAME_H_

#include <math.h>
#include "glwidget.h"
#include "point.h"
#include "color.h"

// typedef
typedef Point<GLfloat>  Point3f;
typedef Point<GLdouble> Point3d;
typedef Point<GLint>    Point3i;

typedef Color<GLfloat>  Color3f;
typedef Color<GLdouble> Color3d;
typedef Color<GLint>    Color3i;

// Define a constant for the value of PI
#define GL_PI 3.1415f

class Game: public GLWidget {
public:
  Game();
  ~Game();

  virtual void displayGL();

private:
  void drawLineStripLoop_3D();
};

#endif /* GAME_H_ */
