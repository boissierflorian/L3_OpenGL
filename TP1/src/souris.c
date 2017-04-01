////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "souris.h"
#include "globales.h"
#include <stdio.h>

////////////////////////////////////////////////////////////
void gestionSouris(int bouton, int etat, int x, int y)
{
  // Le bouton a été relaché
  if (etat == GLUT_UP)
  {
    // Point classique
    if (mode_primitive == 1)
    {
	// Le bouton gauche a été relaché
	if (bouton == GLUT_LEFT_BUTTON)
	{
	    screenTo2D(x, y, &point.x, &point.y);

	    // Rafraîchissement
	    glutPostRedisplay();
	}
    }
    // Un segment
    else if (mode_primitive == 2 || mode_primitive == 3)
    {
      if (bouton == GLUT_LEFT_BUTTON)
      {
	screenTo2D(x, y, &point.x, &point.y);
	glutPostRedisplay();
      }
      else if (bouton == GLUT_RIGHT_BUTTON)
      {
	screenTo2D(x, y, &point2.x, &point2.y);
	glutPostRedisplay();
      }
    }
  }
}


////////////////////////////////////////////////////////////
void screenTo2D(int mouseX, int mouseY, float* x, float* y)
{
  // Dimensions de la fenêtre
  int width = glutGet(GLUT_WINDOW_WIDTH);
  int height = glutGet(GLUT_WINDOW_HEIGHT);

  // Conversion du système de coordonnées de la fenêtre
  // en [0;2]
  float ox = (float) mouseX / (width / 2.f);
  float oy = (float) mouseY / (height / 2.f);

  // On soustrait 1 pour passer aux coordonnées [-1, +1]
  // Soit le système utilisé par OpenGL
  ox -= 1.f;
  oy -= 1.f;

  // Pour y il faut inverser le signe car dans le système
  // de la fenêtre actuelle y pointe vers le bas
  oy = -oy;

  *x = ox;
  *y = oy;
}
