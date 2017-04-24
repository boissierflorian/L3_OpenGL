#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

#include "graphique.h"
#include "touches.h"

/* dimensions initiales de la fenêtre d'affichage */
#define LARGEUR  256
#define HAUTEUR  256

double trans_axeZ = 1.0;
double angle_rotY = 0.0;
double angle_rotX = 0.0;

double kx = 1.0;
double ky = 1.0;
double kz = 1.0;

/**
 * Fonction d'initialisation des paramètres d'affichage
 */
static void init_screen(void)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, 1, 1, 50);
  glViewport(0, 0, LARGEUR, HAUTEUR);
}

/**
 * Fonction principale qui crée et initialise la fenêtre
 * d'affichage et lance la boucle d'affichage Glut.
 * @param argc le nombre d'argument sur la ligne de commande
 * @param argv une table de chaîne de caractères contenant chacun
 * des arguments de la ligne de commande.
 */
int main (int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitWindowPosition(100, 100); 
  glutInitWindowSize(LARGEUR, HAUTEUR); 
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE);

  glutCreateWindow(argv[0]);

  /* choix de la fonction de rafraichissement */
  glutDisplayFunc(dessiner);
  glutReshapeFunc(retailler);
  glutKeyboardFunc(gerer_clavier);
  glutSpecialUpFunc(gerer_sclavier);

  init_screen();

  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
  
  return 0;
}
