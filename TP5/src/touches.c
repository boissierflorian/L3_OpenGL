//////////////////////////////////////////////////
// Headers
//////////////////////////////////////////////////
#include "touches.h"
#include <glut.h>
#include <stdio.h>

// Variables globales
double transZ = 0.0;
double rotX   = 0.0;
double rotY   = 0.0;


//////////////////////////////////////////////////
void gererClavier(unsigned char touche, int x, int y)
{
  switch (touche)
  {
  case '-':
    transZ -= 1.0;
    break;
  case '+':
    transZ += 1.0;
    break;
  case '4':
    rotX -= 10.0;
    break;
  case '6':
    rotX += 10.0;
    break;
  case '8':
    rotY += 10.0;
    break;
  case '2':
    rotY -= 10.0;
    break;
  }

  glutPostRedisplay();
}
