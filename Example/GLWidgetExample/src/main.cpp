/*
 * main.cpp
 *
 *  Created on: 25-Mar-2016
 *      Author: abhi
 */

#include <iostream>
#include "game.h"

using namespace std;

int main(int argc, char **argv)
{
  GLWidget *gameWidget = new Game();
  gameWidget->mainloopGL(argc, argv);

  return(0);
}
