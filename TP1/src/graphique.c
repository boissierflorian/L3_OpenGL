////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <GL/gl.h>
#include <math.h>
#include <stdio.h>

#include "graphique.h"
#include "globales.h"

float rouge = 1.f;
float vert = 0.f;
float bleu = 0.f;

int mode_primitive = 1;

////////////////////////////////////////////////////////////
void dessiner(void)
{
  // Change la couleur d'effacement
  glClearColor(1, 1, 1, 1);

  // Efface le frame buffer
  glClear(GL_COLOR_BUFFER_BIT);

  // Taille des points
  glPointSize(taillePoint);

  // Épaisseur des lignes
  glLineWidth(taillePoint);

  //dessinerDemiCarre();
  //dessinerCercle(0, 0, 0.9);

  glColor3f(rouge, vert, bleu);
  
  if (point.x != UNDEFINED && point.y != UNDEFINED)
  {
    if (translation.x != UNDEFINED && translation.y != UNDEFINED)
    {
      point.x += translation.x;
      point.y += translation.y;
     
      // Reset
      translation.x = UNDEFINED;
      translation.y = UNDEFINED;
    }

    // Segment
    if (point2.x != UNDEFINED && point2.y != UNDEFINED)
    {
      if (mode_primitive == 2)
      {
	glBegin(GL_LINES);
	glVertex2f(point.x, point.y);
	glVertex2f(point2.x, point2.y);
	glEnd();
      }
      else
      {
	double dist = sqrt((point2.x - point.x) * (point2.x - point.x) +
			   (point2.y - point.y) * (point2.y - point.y) );
	dessinerCercle(point.x, point.y, dist);
      }
    }
    // Point unique
    else
    {      
      glBegin(GL_POINTS);
      glVertex2f(point.x, point.y);
      glEnd();
    }
  }
  
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
