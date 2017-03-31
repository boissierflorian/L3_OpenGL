////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

#include "globales.h"
#include "graphique.h"
#include "clavier.h"
#include "geometrie.h"
#include "souris.h"

GLfloat taillePoint = 1.0f;

point2D point = UNDEFINED;

int main(int argc, char* argv[])
{
  // initialiser glu
  glutInit(&argc, argv);

  // fenêtre de taille 256x256
  glutInitWindowSize(256, 256);

  // positionnée en 100x100
  glutInitWindowPosition(100, 100);
  
  // créer la fenêtre
  glutCreateWindow(argv[0]);

  // gestion des évènements clavier
  glutKeyboardFunc(gestionClavier);

  // choix de la fonction de rafraîchissement
  glutDisplayFunc(dessiner);

  // démarrer la boucle évenementielle
  glutMainLoop();
  
  return 0;
}
