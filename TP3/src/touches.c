#include <glut.h>

#include "touches.h"

void gerer_clavier(unsigned char touche, int x, int y)
{
  if (touche == '-')
    trans_axeZ -= 1.0;
  else if (touche == '+')
    trans_axeZ += 1.0;
  else if (touche == '6')
    angle_rotY += 10.0;
  else if (touche == '4')
    angle_rotY -= 10.0;
  else if (touche == '8')
    angle_rotX -= 10.0;
  else if (touche == '2')
    angle_rotX += 10.0;

  glutPostRedisplay();
}

void gerer_sclavier(int touche, int x, int y)
{
  if (touche == GLUT_KEY_LEFT)
  {
    kx /= 2.0; 
  }
  else if (touche == GLUT_KEY_RIGHT)
  {
    kx *= 2.0;
  }
  else if (touche == GLUT_KEY_DOWN)
  {
    ky /= 2.0;
  }
  else if (touche == GLUT_KEY_UP)
  {
    ky *= 2.0;
  }
  else if (touche == 104)
  {
    kz /= 2.0;
  }
  else if (touche == 105)
  {
    kz *= 2.0;
  }
  
  glutPostRedisplay();
}
