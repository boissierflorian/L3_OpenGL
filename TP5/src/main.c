//////////////////////////////////////////////////
// Headers
//////////////////////////////////////////////////
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include "graphique.h"
#include "touches.h"

// dimensions de la fenêtre
#define LARGEUR 256
#define HAUTEUR 256


//////////////////////////////////////////////////
static void initScreen()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, 1, 1, 50);
  glViewport(0, 0, LARGEUR, HAUTEUR);
}


//////////////////////////////////////////////////
int main(int argc, char** argv)
{
  // Initialisation
  glutInit(&argc, argv);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(LARGEUR, HAUTEUR);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE);
  glutCreateWindow(argv[0]);

  // Événements
  glutDisplayFunc(dessiner);
  glutReshapeFunc(retailler);
  glutKeyboardFunc(gererClavier);
  
  initScreen();

  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
  
  return 0;
}
