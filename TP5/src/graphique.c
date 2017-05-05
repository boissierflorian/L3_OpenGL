//////////////////////////////////////////////////
// Headers
//////////////////////////////////////////////////
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include "graphique.h"
#include "touches.h"


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
  // Zoom & Rotation (Ox, Oy);
  glTranslatef(0.0, 0.0, transZ);
  glRotatef(rotY, 0.0, 1.0, 0.0);
  glRotatef(rotX, 1.0, 0.0, 0.0);
  test_extrude();
  // Force l'affichage
  glFlush();
  // Double-buffering
  glutSwapBuffers(); 
}


//////////////////////////////////////////////////
void test_extrude()
{
  point3D t = {0, 0, -5};
  point3D contour[] = {{0, 0, 0}, {-0.5, -0.5, 0}, {0, -1, 0},
			{2, -1, 0}, {2.5, -0.5, 0}, {2, 0, 0}};
  int nbsom = 6;

  extrude(t, contour, nbsom);
}


//////////////////////////////////////////////////
void extrude(point3D t, point3D contour[], int nbsom)
{
  glPushMatrix();
  // La face de devant
  glBegin(GL_POLYGON);
  glColor3f(0, 1, 1);

  int i;
  for (i = 0; i < nbsom; i++)
  {
    point3D point = contour[i];
    glVertex3f(point.x, point.y, point.z);
  }
  glEnd();

  // La face arrière
  glBegin(GL_POLYGON);
  glColor3f(1, 0, 0);
  
  for (i = 0; i < nbsom; i++)
  {
    point3D point = contour[i];
    glTranslatef(t.x, t.y, t.z);
    glVertex3f(point.x, point.y, point.z);
  }
  glEnd();
  
  glPopMatrix();
}
