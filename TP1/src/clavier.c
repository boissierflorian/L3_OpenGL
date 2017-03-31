////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

#include "clavier.h"
#include "globales.h"
#include <stdio.h>

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
