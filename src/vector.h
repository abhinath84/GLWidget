/*
 * vector.h
 *
 *  Created on: 26-Mar-2016
 *      Author: abhi
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#if (defined(_WIN64) || defined(_WIN32))
  #ifdef GLWIDGET_EXPORTS
      #define GLWIDGET_DECLSPEC __declspec(dllexport)
  #else
      #define GLWIDGET_DECLSPEC __declspec(dllimport)
  #endif
#elif __linux
  #define GLWIDGET_DECLSPEC 
#endif

class GLWIDGET_DECLSPEC Vector {
public:
  Vector();
  ~Vector();
};

#endif /* VECTOR_H_ */
