#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

#include "graphique.h"

/* dimensions initiales de la fenêtre d'affichage */
#define LARGEUR  256
#define HAUTEUR  256


/**
 * Fonction d'initialisation des paramètres d'affichage
 */
static void init_screen(void)
{

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

  glutInit (&argc, argv);

  glutInitWindowPosition(100, 100); 
  glutInitWindowSize(LARGEUR, HAUTEUR); 

  glutInitDisplayMode(GLUT_DEPTH);

  glutCreateWindow(argv[0]);

  /* choix de la fonction de rafraichissement */
  glutDisplayFunc(dessiner);


  init_screen();

  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
  

  return 0;
}


