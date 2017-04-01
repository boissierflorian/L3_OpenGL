////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

#include "clavier.h"
#include "globales.h"
#include <stdio.h>

point2D translation = { UNDEFINED, UNDEFINED };

////////////////////////////////////////////////////////////
void gestionClavier(unsigned char touche, int x, int y)
{
  if (touche == '+')
    taillePoint++;
  else if (touche == '-')
  {
    if (taillePoint > 1.0f)
      taillePoint--;
  }

  glutPostRedisplay();
}


////////////////////////////////////////////////////////////
void gestionSpecialeClavier(int touche, int x, int y)
{
  // Point inexistant
  if (point.x == UNDEFINED && point.y == UNDEFINED)
    return;
  
  switch (touche)
  {
  case GLUT_KEY_LEFT:
    translation.x = -0.1f;
    translation.y = 0.f;
    break;
  case GLUT_KEY_RIGHT:
    translation.x = 0.1f;
    translation.y = 0.f;
    break;
  case GLUT_KEY_UP:
    translation.x = 0.f;
    translation.y = 0.1f;
    break;
  case GLUT_KEY_DOWN:
    translation.x = 0.f;
    translation.y = -0.1f;
    break;
  default:
    break;
  }

  glutPostRedisplay();
}
