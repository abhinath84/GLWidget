/*
 * glwidget.cpp
 *
 *  Created on: 25-Mar-2016
 *      Author: abhi
 */

#include "glwidget.h"

GLWidget *GLWidget::instance = NULL;

GLWidget::GLWidget()
:window(),
 glutDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL)
{
}

GLWidget::GLWidget(int win_x, int win_y, int win_w, int win_h, const string &win_title)
:window(win_x, win_y, win_w, win_h, win_title),
 glutDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL)
{
}

GLWidget::~GLWidget()
{
}

void GLWidget::setDisplayModeGL(unsigned int displayMode)
{
  glutDisplayMode = displayMode;
}

void GLWidget::mainloopGL(int argc, char **argv)
{
  setInstance();

  /// Initialize glut.
  glutInit(&argc, argv);
  glutInitDisplayMode(glutDisplayMode);
  glutInitWindowPosition(window.x, window.y);
  glutInitWindowSize(window.width, window.height);
  glutCreateWindow(window.title.c_str());

  // initialize user specific GL/glut related stuff.
  initializeGL();

  // set callback functions
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutSpecialFunc(special);
  glutKeyboardFunc(keyboard);
  glutOverlayDisplayFunc(overlayDisplay);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutPassiveMotionFunc(passiveMotion);
  glutVisibilityFunc(visibility);
  glutEntryFunc(entry);
  glutSpaceballMotionFunc(spaceBallMotion);
  glutSpaceballRotateFunc(spaceBallRotate);
  glutSpaceballButtonFunc(spaceBallButton);
  glutButtonBoxFunc(buttonBox);
  glutDialsFunc(dials);
  glutTabletMotionFunc(tableMotion);
  glutTabletButtonFunc(tableButton);
  glutMenuStatusFunc(menuStatus);
  glutIdleFunc(idle);
  //glutTimerFunc(30, timer, 50);

  // create menu manager
  createMenuGL();

  // customize glut related stuff like:
  // set glutTimerFunc etc, before call to
  // 'glutMainLoop'
  beforeMainLoopGL();

  /// start glut mainloop
  glutMainLoop();
}

void GLWidget::initializeGL()
{
  // Black background
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f );

  // Set drawing color to green
  glColor3f(0.0f, 1.0f, 0.0f);
}

void GLWidget::createMenuGL()
{
}

void GLWidget::beforeMainLoopGL()
{
}

void GLWidget::setInstance()
{
  instance = this;
}

void GLWidget::displayGL()
{
  //  Clear the window or more specifically the frame buffer...
  //  This happens by replacing all the contents of the frame
  //  buffer by the clear color
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

  /// swap background buffer.
  glutSwapBuffers();
}

void GLWidget::display()
{
  instance->displayGL();
}

void GLWidget::reshapeGL(int w, int h)
{
  GLfloat nRange = 100.0f;

  // Prevent a divide by zero
  if(h == 0)
    h = 1;

  // Set Viewport to window dimensions
  glViewport(0, 0, w, h);

  // Reset projection matrix stack
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Establish clipping volume (left, right, bottom, top, near, far)
  if (w <= h)
    glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
  else
    glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);

  // Reset Model view matrix stack
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void GLWidget::reshape(int w, int h)
{
  instance->reshapeGL(w, h);
}

void GLWidget::specialGL(int key, int x, int y)
{
}

void GLWidget::special(int key, int x, int y)
{
  instance->specialGL(key, x, y);
}

void GLWidget::keyboardGL(unsigned char key, int x, int y)
{
}

void GLWidget::keyboard(unsigned char key, int x, int y)
{
  instance->keyboardGL(key, x, y);
}

void GLWidget::overlayDisplayGL()
{
}

void GLWidget::overlayDisplay()
{
  instance->overlayDisplayGL();
}

void GLWidget::mouseGL(int button, int state, int x, int y)
{
}

void GLWidget::mouse(int button, int state, int x, int y)
{
  instance->mouseGL(button, state, x, y);
}

void GLWidget::motionGL(int x, int y)
{
}

void GLWidget::motion(int x, int y)
{
  instance->motionGL(x, y);
}

void GLWidget::passiveMotionGL(int x, int y)
{
}

void GLWidget::passiveMotion(int x, int y)
{
  instance->passiveMotionGL(x, y);
}

void GLWidget::visibilityGL(int state)
{
}

void GLWidget::visibility(int state)
{
  instance->visibilityGL(state);
}

void GLWidget::entryGL(int state)
{
}

void GLWidget::entry(int state)
{
  instance->entryGL(state);
}

void GLWidget::spaceBallMotionGL(int x, int y, int z)
{
}

void GLWidget::spaceBallMotion(int x, int y, int z)
{
  instance->spaceBallMotionGL(x, y, z);
}

void GLWidget::spaceBallRotateGL(int x, int y, int z)
{
}

void GLWidget::spaceBallRotate(int x, int y, int z)
{
  instance->spaceBallRotateGL(x, y, z);
}

void GLWidget::spaceBallButtonGL(int button, int state)
{
}

void GLWidget::spaceBallButton(int button, int state)
{
  instance->spaceBallButtonGL(button, state);
}

void GLWidget::buttonBoxGL(int button, int state)
{
}

void GLWidget::buttonBox(int button, int state)
{
  instance->buttonBoxGL(button, state);
}

void GLWidget::dialsGL(int dial, int value)
{
}

void GLWidget::dials(int dial, int value)
{
  instance->dialsGL(dial, value);
}

void GLWidget::tableMotionGL(int x, int y)
{
}

void GLWidget::tableMotion(int x, int y)
{
  instance->tableMotionGL(x, y);
}

void GLWidget::tableButtonGL(int button, int state, int x, int y)
{
}

void GLWidget::tableButton(int button, int state, int x, int y)
{
  instance->tableButtonGL(button, state, x, y);
}

void GLWidget::menuStatusGL(int status, int x, int y)
{
}

void GLWidget::menuStatus(int status, int x, int y)
{
  instance->menuStatusGL(status, x, y);
}

void GLWidget::idleGL()
{
}

void GLWidget::idle()
{
  instance->idleGL();
}

void GLWidget::timerGL(int value)
{
}

void GLWidget::timer(int value)
{
  instance->timerGL(value);
}
