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
#include "menu.h"

GLfloat taillePoint = 3.f;

point2D point = {UNDEFINED, UNDEFINED};
point2D point2 = {UNDEFINED, UNDEFINED};

int main(int argc, char* argv[])
{
  // initialiser glu
  glutInit(&argc, argv);

  // fenêtre de taille 256x256
  glutInitWindowSize(256, 256);

  //glutInitDisplayMode(GLUT_DOUBLE);
  
   // positionnée en 100x100
  glutInitWindowPosition(100, 100);
  
  // créer la fenêtre
  glutCreateWindow(argv[0]);

  // initialisation du menu
  init_menu();
  
  // gestion des évènements clavier
  glutKeyboardFunc(gestionClavier);

  // gestion des évènements souris
  glutMouseFunc(gestionSouris);

  // gestion des évènements spéciaux clavier
  glutSpecialUpFunc(gestionSpecialeClavier);
  
  // choix de la fonction de rafraîchissement
  glutDisplayFunc(dessiner);
  
  // démarrer la boucle évenementielle
  glutMainLoop();
  
  return 0;
}
