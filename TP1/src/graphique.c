////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <GL/gl.h>
#include <math.h>
#include <stdio.h>

#include "graphique.h"
#include "globales.h"


////////////////////////////////////////////////////////////
void dessiner(void)
{
  // Change la couleur d'effacement
  glClearColor(0, 0, 0, 1);

  // Efface le frame buffer
  glClear(GL_COLOR_BUFFER_BIT);

  // Taille des points
  glPointSize(taillePoint);

  // Épaisseur des lignes
  glLineWidth(taillePoint);

  //dessinerDemiCarre();
  //dessinerCercle(0, 0, 0.9);

  glBegin(GL_LINES);
  glVertex2f(-0.25f, 0.25f);
  glVertex2f(0.25f, 0.25f);
  glEnd();
  
  // Problème interne à UNIX
  glFlush();
}


////////////////////////////////////////////////////////////
void dessinerDemiCarre()
{
  glColor3f(1, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2f(-0.25f, 0.25f);
  glVertex2f(0.25f, 0.25f);
  glVertex2f(0.25f, -0.25f);
  glVertex2f(-0.25f, -0.25f);
  glEnd();
}


////////////////////////////////////////////////////////////
void dessinerCercle(float cx, float cy, float r)
{
  glColor3f(0, 0, 1);
  glBegin(GL_POLYGON);

  for (int ii = 0; ii < 100; ii++)
  {
    float theta = 2.0f * 3.1415926f * ((float)ii / 100.f);
    float x = r * cos(theta);
    float y = r * sin(theta);
    glVertex2f(x + cx, y + cy);
  }
  
  glEnd();
}
