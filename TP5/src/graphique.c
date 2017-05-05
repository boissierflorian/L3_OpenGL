//////////////////////////////////////////////////
// Headers
//////////////////////////////////////////////////
#include "graphique.h"


//////////////////////////////////////////////////
void retailler(GLsizei largeur, GLsizei hauteur)
{
  if (largeur > hauteur)
    glViewport(largeur / 2 - hauteur / 2, 0, hauteur, hauteur);
  else
    glViewport(0, hauteur / 2 - largeur / 2, largeur, largeur);

  glutPostRedisplay();
}


//////////////////////////////////////////////////
void dessiner()
{
  // Efface la la fenêtre
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // Reset de la matrice
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  // Force l'affichage
  glFlush();
  // Double-buffering
  glutSwapBuffers(); 
}


//////////////////////////////////////////////////
void extrude(point3D t, point3D contour[], int nbsom)
{
  
}
