////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <GL/glut.h>
#include <glut.h>

#include "menu.h"
#include "globales.h"

////////////////////////////////////////////////////////////
void init_menu()
{
  // Sous-menu pour la couleur du tracé
  int menu_couleur = glutCreateMenu(gerer_couleur_trace);
  glutAddMenuEntry("Rouge", 1);
  glutAddMenuEntry("Vert", 2);
  glutAddMenuEntry("Bleu", 3);
  
  // Sous-menu pour l'épaisseur du tracé
  int menu_epaisseur = glutCreateMenu(gerer_epaisseur_trace);
  glutAddMenuEntry("1.0", 1);
  glutAddMenuEntry("2.0", 2);
  glutAddMenuEntry("3.0", 3);

  // Sous-menu pour la primitive du tracé
  int menu_primitive = glutCreateMenu(gerer_primitive);
  glutAddMenuEntry("Point", 1);
  glutAddMenuEntry("Segment", 2);
  glutAddMenuEntry("Cercle", 3);
  
  // Menu principal
  glutCreateMenu(gerer_menu_principal);
  glutAddSubMenu("Couleur", menu_couleur);
  glutAddSubMenu("Épaisseur", menu_epaisseur);
  glutAddSubMenu("Primitive", menu_primitive);
  glutAddMenuEntry("Effacer", 1);
  glutAttachMenu(GLUT_MIDDLE_BUTTON);
}


////////////////////////////////////////////////////////////
void gerer_menu_principal(int cle)
{
  switch(cle)
  {
  case 1:
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    break;
  default:
    break;
  }

  glutPostRedisplay();
}


////////////////////////////////////////////////////////////
void gerer_couleur_trace(int cle)
{
  switch(cle)
  {
  case 1:
    rouge = 1.f;
    vert = bleu = 0.f;
    break;
  case 2:
    vert = 1.f;
    rouge = bleu = 0.f;
    break;
  case 3:
    bleu = 1.f;
    rouge = vert = 0.f;
    break;
  default:
    break;
  }

  glutPostRedisplay();
}


////////////////////////////////////////////////////////////
void gerer_epaisseur_trace(int cle)
{
  taillePoint = (float) cle;
  glutPostRedisplay();
}


////////////////////////////////////////////////////////////
void gerer_primitive(int cle)
{
  // On change de mode
  if (cle != mode_primitive)
  {
    point.x = point.y = point2.x = point2.y = UNDEFINED;
    glutPostRedisplay();
  }
  
  mode_primitive = (float) cle;
}
